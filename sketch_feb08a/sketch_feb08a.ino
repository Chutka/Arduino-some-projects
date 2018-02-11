 
int pin[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3};        
int row[16] = {pin[12], pin[2], pin[7], pin[1], pin[11], pin[6], pin[10], pin[4]};
int col[16] = {pin[3], pin[9], pin[8], pin[13], pin[5], pin[0], pin[15], pin[14]};
int dms = 400;
boolean focusPointStop = false;

boolean mainMatrix[8][8] = {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0
}; 


class Point {
  private: 
    int positionX;
    int positionY;
    boolean relationUp, relationRight, relationBottom, relationLeft;
   public:
    Point(int x, int y);
    void setPositionX(int x);
    void setPositionY(int y);
    int getPositionX();
    int getPositionY();
};

Point *focusPoint;


void writeCurrentPoint() {
  mainMatrix[focusPoint->getPositionY()][focusPoint->getPositionX()] = 1;
}

void deleteCurrentPoint() {
  mainMatrix[focusPoint->getPositionY()][focusPoint->getPositionX()] = 0;
}

void drawMainMatrix(boolean screen[8][8], int v) {  
  int i, j;
  for (int c=0; c <v; c ++) {
    for (i=0; i<8; i++)
    for (j=0; j<8; j++) {
      if (screen[i][j]==1) {
        digitalWrite(row[i], LOW); 
        digitalWrite(col[j], HIGH); 
        delayMicroseconds(dms); 
        digitalWrite(row[i], HIGH); 
        digitalWrite(col[j], LOW); 
      } else {
        digitalWrite(row[i], HIGH); 
        digitalWrite(col[j], LOW); 
        delayMicroseconds(dms); 
        digitalWrite(row[i], HIGH); 
        digitalWrite(col[j], LOW);
      } 
    } 
  }
}

void findAndDeleteFullRow() {
  for (int i = 0; i < 8; i++) {
    short condition = 0;
    for (int j = 0; j < 8; j++) {
      if (mainMatrix[i][j] == 1) {
        condition ++;
      }
    }
    if (condition == 8) {
      for (int j = 7; j >= 0; j--) {
        mainMatrix[i][j] = 0;
        drawMainMatrix(mainMatrix, 5);
      }
      for (int revI = i; revI > 0; revI--) {
        for (int j = 0; j < 8; j++) {
            mainMatrix[revI][j] = mainMatrix[revI - 1][j];          
        }  
      }   
    }
  }
}

int generateRandomX() {
  return rand() % 8;
}

void setup(){
  for (int i = 0; i < 16; i++) {
    pinMode(pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(row[i], HIGH);
  }
  focusPoint = new Point(1, 0);
}

void loop(){
  if (!focusPointStop) {
    writeCurrentPoint();
    if (mainMatrix[focusPoint->getPositionY() + 1][focusPoint->getPositionX()] == 1 || focusPoint->getPositionY() == 7) {
      focusPoint = new Point(generateRandomX(), 0);
      writeCurrentPoint();
    }
    drawMainMatrix(mainMatrix, 3);
    if (mainMatrix[focusPoint->getPositionY() + 1][focusPoint->getPositionX()] == 1) {
      focusPointStop = true;
    } else {
      deleteCurrentPoint();
      focusPoint->setPositionY(focusPoint->getPositionY() + 1);
    }
    findAndDeleteFullRow();
  } else {
    drawMainMatrix(mainMatrix, 10);
  }
}


Point::Point(int x, int y) {
  positionX = x;
  positionY = y;
}

void Point::setPositionX(int x) {
  if (x >= 0 && x < 8) {
    positionX = x;
  }
  
}
void Point::setPositionY(int y) {
  if (y < 8) {
    positionY = y;
  }
}

int Point::getPositionX() {
  return positionX;
}

int Point::getPositionY() {
  return positionY;
}



