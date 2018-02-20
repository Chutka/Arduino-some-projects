#include "Figure.h"

Figure::Figure(int x, int y) {
	maskX = x;
	maskY = y;
	position = 0;
	checkMove = true;
}

void Figure::moveFigureX(int matrix[32][8], int x) {
	clearFigure(matrix);
	if (!checkLeft(matrix) && !checkRight(matrix)) {
		maskX = x;
	}
	drawFigure(matrix);
}

void Figure::moveFigureY(int matrix[32][8]) {
	clearFigure(matrix);
	if (!checkBottom(matrix)) {
		maskY ++;
	}
	else {
		checkMove = false;
	}
	drawFigure(matrix);
}

bool Figure::getCheckMove() {
	return checkMove;
}

int Figure::getMaskX() {
	return maskX;
}

int Figure::getMaskY() {
	return maskY;
}

Figure::~Figure() {
}


void Figure::drawFigure(int matrix[32][8]) { }

void Figure::clearFigure(int matrix[32][8]) { }

void Figure::rotateFigure(int matrix[32][8]) { }

bool Figure::checkLeft(int matrix[32][8]) { 
	return false;
}

bool Figure::checkRight(int matrix[32][8]) { 
	return false;
}

bool Figure::checkBottom(int matrix[32][8]) {
	return false;
}