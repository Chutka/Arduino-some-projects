#include "I.h"

void I::drawFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY + 2][maskX] = 1;
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY - 1][maskX] = 1;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 1;
		matrix[maskY][maskX + 2] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX - 1] = 1;
		break;
	default:
		break;
	}
}

void I::clearFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY + 2][maskX] = 0;
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY - 1][maskX] = 0;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 0;
		matrix[maskY][maskX + 2] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX - 1] = 0;
		break;
	default:
		break;
	}
}

void I::rotateFigure(int matrix[33][10]) {
	switch(position) {
	case 0:
		if (
			matrix[maskY][maskX - 1] != 1 &&
			matrix[maskY][maskX + 1] != 1 &&
			matrix[maskY][maskX + 2] != 1
		) {
			clearFigure(matrix);
			position = (position + 1) % 2;
			drawFigure(matrix);
			return;
		} else if (
			matrix[maskY][maskX - 1] == 1 &&
			matrix[maskY][maskX + 1] != 1 &&
			matrix[maskY][maskX + 2] != 1 &&
			matrix[maskY][maskX + 3] != 1
		) {
			clearFigure(matrix);
			maskX += 1;				
			position = (position + 1) % 2;
			drawFigure(matrix);
			break;
		} else if (
			matrix[maskY][maskX + 1] == 1 &&
			matrix[maskY][maskX - 1] != 1 &&
			matrix[maskY][maskX - 2] != 1 &&
			matrix[maskY][maskX - 3] != 1
		) {
			clearFigure(matrix);
			maskX -= 2;
			position = (position + 1) % 2;
			drawFigure(matrix);
			break;
		} else if (
			matrix[maskY][maskX + 2] == 1 &&
			matrix[maskY][maskX + 1] != 1 &&
			matrix[maskY][maskX - 1] != 1 &&
			matrix[maskY][maskX - 2] != 1
		) {
			clearFigure(matrix);
			maskX -= 1;
			position = (position + 1) % 2;
			drawFigure(matrix);
			break;
		}
	case 1:
		if (
			matrix[maskY - 1][maskX] != 1 &&
			matrix[maskY + 1][maskX] != 1 &&
			matrix[maskY + 2][maskX] != 1			
		) {
			clearFigure(matrix);
			position = (position + 1) % 2;
			drawFigure(matrix);
		}
		break;
	}
}

bool I::checkRight(int matrix[33][10]) {
	switch (position) {
	case 0:
		if (matrix[maskY + 1][maskX + 1] == 1 ||
			matrix[maskY + 2][maskX + 1] == 1 ||
			matrix[maskY][maskX + 1] == 1 ||
			matrix[maskY - 1][maskX+ 1] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY][maskX + 3] == 1) {
			return true;
		}
		break;
	}
	return false;
}

bool I::checkLeft(int matrix[33][10]) {
	switch (position) {
	case 0:
		if (matrix[maskY + 1][maskX - 1] == 1 ||
			matrix[maskY + 2][maskX - 1] == 1 ||
			matrix[maskY][maskX - 1] == 1 ||
			matrix[maskY - 1][maskX - 1] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY][maskX - 2] == 1) {
			return true;
		}
		break;
	}
	return false;
}

bool I::checkBottom(int matrix[33][10]) {
	
	switch (position) {
	case 0:
		if (matrix[maskY + 3][maskX] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY + 1][maskX + 2] == 1 ||
			matrix[maskY + 1][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX] == 1 ||
			matrix[maskY + 1][maskX - 1] == 1) {
			return true;
		}
		break;
	}
	return false;
}


I::~I()
{
}
