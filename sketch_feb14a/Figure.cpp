#include "Figure.h"

Figure::Figure(int x, int y) {
	maskX = x;
	maskY = y;
	position = 0;
	checkMove = true;
}

void Figure::moveFigureRight(int matrix[33][10]) {
	clearFigure(matrix);
	if (!checkRight(matrix)) {
		maskX ++;
	}
	drawFigure(matrix);
}

void Figure::moveFigureLeft(int matrix[33][10]) {
	clearFigure(matrix);
	if (!checkLeft(matrix)) {
		maskX --;
	}
	drawFigure(matrix);
}

void Figure::moveFigureY(int matrix[33][10]) {
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


void Figure::drawFigure(int matrix[33][10]) { }

void Figure::clearFigure(int matrix[33][10]) { }

void Figure::rotateFigure(int matrix[33][10]) { }

bool Figure::checkLeft(int matrix[33][10]) { 
	return false;
}

bool Figure::checkRight(int matrix[33][10]) { 
	return false;
}

bool Figure::checkBottom(int matrix[33][10]) {
	return false;
}
