#include "Figure.h"

Figure::Figure(int x, int y)
{
	maskX = x;
	maskY = y;
	position = 0;
	checkMove = true;
}

bool Figure::getCheckMove() {
	return checkMove;
}

void Figure::drawFigure(int matrix[32][8]) {
	switch (position) {
	case 0:
		matrix[maskY - 1][maskX - 1] = 1;
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY + 1][maskX] = 1;
		break;
	case 1:
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY - 1][maskX] = 1;
		matrix[maskY - 1][maskX + 1] = 1;
		break;
	default:
		break;
	}
}

void Figure::clearFigure(int matrix[32][8]) {
	switch (position) {
	case 0:
		matrix[maskY - 1][maskX - 1] = 0;
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY + 1][maskX] = 0;
		break;
	case 1:
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY - 1][maskX] = 0;
		matrix[maskY - 1][maskX + 1] = 0;
		break;
	default:
		break;
	}
}

void Figure::moveFigure(int matrix[32][8], int x, int y) {
	clearFigure(matrix);
	if (!checkLeft(matrix) && !checkRight(matrix)) {
		maskX = x;
	}
	if (!checkBottom(matrix)) {
		maskY = y;
	}
	else {
		checkMove = false;
	}
	drawFigure(matrix);
}

void Figure::rotateFigure(int matrix[32][8]) {
	clearFigure(matrix);
	position = (position + 1) % 2;
	drawFigure(matrix);
}

bool Figure::checkLeft(int matrix[32][8]) {
	if (maskX > 1) {
		switch (position) {
		case 0:
			if (matrix[maskY - 1][maskX - 2] == 1 ||
				matrix[maskY][maskX - 2] == 1 ||
				matrix[maskY + 1][maskX - 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY][maskX - 1] == 1 ||
				matrix[maskY + 1][maskX - 2] == 1) {
				return true;
			}
			break;
		default:
			break;
		}
	}
	else {
		return true;
	}
	return false;
}

bool Figure::checkRight(int matrix[32][8]) {
	if (maskX < 6) {
		switch (position) {
		case 0:
			if (matrix[maskY - 1][maskX] == 1 ||
				matrix[maskY][maskX + 1] == 1 ||
				matrix[maskY + 1][maskX + 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY][maskX + 2] == 1 ||
				matrix[maskY + 1][maskX + 1] == 1) {
				return true;
			}
			break;
		default:
			break;
		}
	}
	else {
		return true;
	}
	return false;
}

bool Figure::checkBottom(int matrix[32][8]) {
	if (maskY < 30) {
		switch (position) {
		case 0: 
			if (matrix[maskY + 2][maskX] == 1 ||
				matrix[maskY + 1][maskX - 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY + 2][maskX - 1] == 1 ||
				matrix[maskY + 2][maskX] == 1 ||
				matrix[maskY + 1][maskX + 1] == 1) {
				return true;
			}
			break;
		default:
			break;
		}
	}
	else {
		return true;
	}
	return false;
}

int Figure::getMaskX() {
	return maskX;
}

int Figure::getMaskY() {
	return maskY;
}

Figure::~Figure()
{
}