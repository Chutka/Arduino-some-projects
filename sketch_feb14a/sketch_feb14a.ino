#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

#include <iarduino_KB.h>
  iarduino_KB KB(9, 8, 7, 6, 5, 4, 3, 2);


#include "J.h"


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

void setup() {
  matrix.setIntensity(2); // Use a value between 0 and 15 for brightness
  matrix.setRotation(3);
  f = new J(5, 5);
  f->drawFigure(playField);
  Serial.begin(9600);
  KB.begin(KB2);
}

void moveFigure() {
  for (int i = 0; i < 100; i++) {
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
      if (KB.getNum == 3) {
        f->moveFigureY(playField);
      }
      Serial.print(KB.getNum);
      Serial.print("\n");
    }
    matrix.write();
    delay(10);
  }
  
}

void loop() {
  
  moveFigure();
  if (f->getCheckMove()) {
    Serial.print("End");
  }
}
