#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include <iarduino_KB.h>
  iarduino_KB KB(9, 8, 7, 6, 5, 4, 3, 2);


#include "Figures.h"

int pinCS = 10;
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 4;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

int wait = 200;
Figure *f;

bool gamePause = false;

int playField[33][10] = {
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  
};


void drawMatrix() {
  for (int i = 0; i < 32; i++) {
    for (int j = 1; j < 9; j++) {
      if (playField[i][j] == 1) {
        matrix.drawPixel(i, j - 1, HIGH);
      }
    }
  }
}

int randomNumber(int maxPos, int minPos) {
  return (rand() % maxPos + minPos);
}

void generateFigure() {
  switch(rand() % 7) {
    case 0:
      f = new O(randomNumber(6, 2), 1);
      break;
    case 1:
      f = new I(randomNumber(6, 2), 1);
      break;
    case 2:
      f = new J(randomNumber(6, 2), 1);
      break;
    case 3:
      f = new T(randomNumber(6, 2), 1);
      break; 
    case 4:
      f = new S(randomNumber(6, 2), 1);
      break; 
    case 5:
      f = new L(randomNumber(6, 2), 1);
      break;
    case 6: 
      f = new Z(randomNumber(6, 2), 1);
      break;  
  }
  for (int i = 0; i < randomNumber(4, 0); i++) {
    f->rotateFigure(playField);
  }
  f->drawFigure(playField);
}

void setup() {
  matrix.setIntensity(2);
  matrix.setRotation(3);
  generateFigure();
  KB.begin(KB2);
}

void clearLines() {
  for (int i = 0; i < 32; i++) {
    bool cond = true;
    for (int j = 1; j < 9; j++) {
      if (playField[i][j] == 0) {
        cond = false;
      }
    }
    if (cond) {
      for (int j = 1; j < 9; j++) {
        playField[i][j] = 0;
        drawMatrix();
      }
      for (int k = i; k > 0; k--) {
        for (int j = 1; j < 9; j++) {
          playField[k][j] = playField[k - 1][j];
        }
      }
      for (int j = 1; j < 9; j++) {
         playField[0][j] = 0;
      }
    }
  }
}

void reset() {
	for(int i = 0; i < 32; i++) {
		for (int j = 1; j < 9; j++) {
			playField[i][j] = 0;
		}
	}
	generateFigure();
  if (gamePause) {
    gamePause = false;
  }
}

void setPause() {
  gamePause = !gamePause;
}

void moveFigure() {
  for (int i = 0; i < 20; i++) {
    matrix.fillScreen(LOW);
    drawMatrix(); 
    if (KB.check(KEY_DOWN)) {
      if (!gamePause) {
        if (KB.getNum == 0) {
          f->moveFigureRight(playField);
        }
        if (KB.getNum == 2) {
          f->moveFigureLeft(playField);
        }
        if (KB.getNum == 1) {
          f->rotateFigure(playField);
        }
      }
      if (KB.getNum == 15) {
        reset();
      }
      if (KB.getNum == 14) {
        setPause();
      }
    }
    if (KB.check(KEY_PRESS)) {
      if (KB.getNum == 5) {
        f->moveFigureY(playField);
        delay(10);
        i++;
      }
    }
    matrix.write();
    delay(10);
  }
  if (!gamePause) {
    f->moveFigureY(playField);
  }
  matrix.write();
}

bool checkEndOfGame() {
  for (int j = 1; j < 9; j++) {
    if (playField[1][j] == 1) {
      return true;
    }
  }
  return false;
}

void loop() {
  if (!f->getCheckMove()) {
    clearLines();
    if (!checkEndOfGame()) {
      generateFigure();
    } else {
      reset();
    }
  }
  moveFigure();
}
