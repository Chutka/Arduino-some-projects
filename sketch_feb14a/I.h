#pragma once
#include "Figure.h"

class I :
  public Figure
{
public:
  I(int x, int y) : Figure(x, y) { };
  void drawFigure(int matrix[33][10]);
  void clearFigure(int matrix[33][10]);
  void rotateFigure(int matrix[33][10]);
  bool checkRight(int matrix[33][10]);
  bool checkLeft(int matrix[33][10]);
  bool checkBottom(int matrix[33][10]);

  ~I();
};
