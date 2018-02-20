#pragma once
#include "Figure.h"
class S :
	public Figure
{
public:
	S(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[32][8]);
	void clearFigure(int matrix[32][8]);
	void rotateFigure(int matrix[32][8]);
	bool checkRight(int matrix[32][8]);
	bool checkLeft(int matrix[32][8]);
	bool checkBottom(int matrix[32][8]);

	~S();
};

