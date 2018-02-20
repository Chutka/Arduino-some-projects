#include "S.h"

void S::drawFigure(int matrix[32][8]) {
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

void S::clearFigure(int matrix[32][8]) {
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

void S::rotateFigure(int matrix[32][8]) {
	clearFigure(matrix);
	position = (position + 1) % 2;
  if (checkRight(matrix)) {
    maskX --;
  }
	drawFigure(matrix);
}

bool S::checkRight(int matrix[32][8]) {
	if (maskX < 7) {
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

bool S::checkLeft(int matrix[32][8]) {
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

bool S::checkBottom(int matrix[32][8]) {
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


S::~S()
{
}
