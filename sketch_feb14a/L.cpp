#include "L.h"

void L::drawFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY - 1][maskX] = 1;
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY + 1][maskX - 1] = 1;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY - 1][maskX - 1] = 1;
		break;
	case 2:
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY - 1][maskX] = 1;
		matrix[maskY - 1][maskX + 1] = 1;
		break;
	case 3:
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX + 1] = 1;
		matrix[maskY + 1][maskX + 1] = 1;
		break;
	default:
		break;
	}
}

void L::clearFigure(int matrix[33][10]) {
	switch (position) {
		case 0:
		matrix[maskY - 1][maskX] = 0;
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY + 1][maskX - 1] = 0;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY - 1][maskX - 1] = 0;
		break;
	case 2:
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY - 1][maskX] = 0;
		matrix[maskY - 1][maskX + 1] = 0;
		break;
	case 3:
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX + 1] = 0;
		matrix[maskY + 1][maskX + 1] = 0;
		break;
	default:
		break;
	}
}

void L::rotateFigure(int matrix[33][10]) {
	clearFigure(matrix);
	position = (position + 1) % 4;
  if (checkRight(matrix)) {
    maskX --;
  }
	drawFigure(matrix);
}

bool L::checkRight(int matrix[33][10]) {
	switch (position) {
	case 0:
		if (matrix[maskY - 1][maskX + 1] == 1 ||    
			matrix[maskY][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX + 1] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY - 1][maskX] == 1 ||
			matrix[maskY][maskX + 2] == 1) {
			return true;
		}
		break;
	case 2:
		if (matrix[maskY - 1][maskX + 2] == 1 ||    
			matrix[maskY][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX + 1] == 1) {
			return true;
		}
		break;
	case 3:
		if (matrix[maskY][maskX + 2] == 1 ||    
			matrix[maskY + 1][maskX + 2] == 1) {
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

bool L::checkLeft(int matrix[33][10]) {
	if (maskX > 1) {
		switch (position) {
		case 0:
			if (matrix[maskY + 1][maskX - 2] == 1 ||    
				matrix[maskY][maskX - 1] == 1 ||
				matrix[maskY - 1][maskX - 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY][maskX - 2] == 1 ||
				matrix[maskY - 1][maskX - 2] == 1) {
				return true;
			}
			break;
		case 2:
			if (matrix[maskY - 1][maskX - 1] == 1 ||    
				matrix[maskY][maskX - 1] == 1 ||
				matrix[maskY + 1][maskX - 1] == 1) {
				return true;
			}
			break;
		case 3:
			if (matrix[maskY][maskX - 2] == 1 ||    
				matrix[maskY + 1][maskX] == 1) {
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

bool L::checkBottom(int matrix[33][10]) {
	if (maskY < 30) {
		switch (position) {
		case 0:
			if (matrix[maskY + 2][maskX] == 1 ||    
				matrix[maskY + 2][maskX - 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY + 1][maskX] == 1 ||
				matrix[maskY + 1][maskX - 1] == 1 ||
				matrix[maskY + 1][maskX + 1] == 1) {
				return true;
			}
			break;
		case 2:
			if (matrix[maskY][maskX + 1] == 1 ||
				matrix[maskY + 2][maskX] == 1) {
				return true;
			}
			break;
		case 3:
			if (matrix[maskY + 1][maskX - 1] == 1 ||    
				matrix[maskY + 1][maskX] == 1 || 
				matrix[maskY + 2][maskX + 1] == 1) {
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


L::~L()
{
}
