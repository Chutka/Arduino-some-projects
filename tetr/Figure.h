#pragma once
class Figure
{
private:
	int maskX, maskY;
	int position;
	bool checkMove;
public:
	Figure(int x, int y);
	void drawFigure(int matrix[32][8]);
	void clearFigure(int matrix[32][8]);
	void rotateFigure(int matrix[32][8]);
	void moveFigure(int matrix[32][8], int, int);
	bool getCheckMove();
	int getMaskX();
	int getMaskY();
	bool checkRight(int matrix[32][8]);
	bool checkLeft(int matrix[32][8]);
	bool checkBottom(int matrix[32][8]);

	~Figure();
};

