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

Figure *f;
void drawMatrix() {
  for (int i = 0; i < 32; i++) {
    for (int j = 1; j < 9; j++) {
      if (playField[i][j] == 1) {
        matrix.drawPixel(i, j - 1, HIGH);
      }
    }
  }
}

void generateFigure() {
  switch(rand() % 3) {
    case 0:
      f = new O(5, 3);
      break;
    case 1:
      f = new I(5, 3);
      break;
    case 2:
      f = new J(5, 3);
      break;
  }
  f->drawFigure(playField);
}

void setup() {
  matrix.setIntensity(2);
  matrix.setRotation(3);
  generateFigure();
  Serial.begin(9600);
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


void moveFigure() {
  for (int i = 0; i < 20; i++) {
    matrix.fillScreen(LOW);
    drawMatrix(); 
    if (KB.check(KEY_DOWN)) {
      if (KB.getNum == 0) {
        f->moveFigureRight(playField);
        Serial.print("0");
      }
      if (KB.getNum == 2) {
        f->moveFigureLeft(playField);
        Serial.print("2");
      }
      if (KB.getNum == 1) {
        f->rotateFigure(playField);
        Serial.print("1");
      }
      Serial.print(KB.getNum);
      Serial.print("\n");
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
  f->moveFigureY(playField);
  matrix.write();
}


void loop() {
  if (!f->getCheckMove()) {
    clearLines();
    generateFigure();
  }
  moveFigure();
}
