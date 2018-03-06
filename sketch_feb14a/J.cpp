#include "J.h"

void J::drawFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY - 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY + 1][maskX + 1] = 1;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY + 1][maskX - 1] = 1;
		break;
	case 2:
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY - 1][maskX] = 1;
		matrix[maskY - 1][maskX - 1] = 1;
		break;
	case 3:
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX + 1] = 1;
		matrix[maskY - 1][maskX + 1] = 1;
		break;
	}
}

void J::clearFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY - 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY + 1][maskX + 1] = 0;
		break;
	case 1:
		matrix[maskY][maskX + 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY + 1][maskX - 1] = 0;
		break;
	case 2:
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY - 1][maskX] = 0;
		matrix[maskY - 1][maskX - 1] = 0;
		break;
	case 3:
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX + 1] = 0;
		matrix[maskY - 1][maskX + 1] = 0;
		break;
	}
}

void J::rotateFigure(int matrix[33][10]) {
	switch(position) {
		case 0:
			if (
				matrix[maskY][maskX + 1] != 1 &&
				matrix[maskY][maskX - 1] != 1 &&
				matrix[maskY + 1][maskX - 1] != 1
			) {
				clearFigure(matrix);
				position = (position + 1) % 4;
				drawFigure(matrix);
				break;	
			} else if (
				(
					matrix[maskY][maskX - 1] == 1 ||
					matrix[maskY + 1][maskX - 1] != 1
					) &&
				matrix[maskY][maskX + 1] != 1 &&
				matrix[maskY][maskX + 2] != 1 &&
				matrix[maskY - 1][maskX] != 1
			) {
				clearFigure(matrix);
				maskX += 1;
				position = (position + 1) % 4;
				drawFigure(matrix);
				break;				
			}
		case 1:
			if (
				matrix[maskY - 1][maskX] != 1 &&
				matrix[maskY - 1][maskX - 1] != 1 &&
				matrix[maskY + 1][maskX] != 1
			) {
				clearFigure(matrix);
				position = (position + 1) % 4;
				drawFigure(matrix);
				break;				
			}
			break;
		case 2:
			if (
				matrix[maskY][maskX - 1] != 1 &&
				matrix[maskY][maskX + 1] != 1 &&
				matrix[maskY - 1][maskX + 1] != 1
			) {
				clearFigure(matrix);
				position = (position + 1) % 4;
				drawFigure(matrix);
				break;				
			} else if (
				(
					matrix[maskY][maskX - 1] == 1 &&
					matrix[maskY - 1][maskX - 1] == 1
				) &&
				matrix[maskY - 1][maskX] != 1 &&
				matrix[maskY][maskX - 1] != 1 &&
				matrix[maskY][maskX - 2] != 1
			) {
				clearFigure(matrix);
				position = (position + 1) % 4;
				maskX -= 1;
				drawFigure(matrix);
				break;
			}
			break;
		case 3:
			if (
				matrix[maskY - 1][maskX] != 1 &&
				matrix[maskY + 1][maskX] != 1 &&
				matrix[maskY + 1][maskX + 1] != 1
			) {
				clearFigure(matrix);
				position = (position + 1) % 4;
				drawFigure(matrix);
				break;				
			}
			break;
	}
}

bool J::checkRight(int matrix[33][10]) {
	switch (position) {
	case 0:
		if (matrix[maskY - 1][maskX + 1] == 1 ||    
			matrix[maskY][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX + 2] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY][maskX + 2] == 1 ||
			matrix[maskY + 1][maskX] == 1) {
			return true;
		}
		break;
	case 2:
		if (matrix[maskY - 1][maskX + 1] == 1 ||    
			matrix[maskY][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX + 1] == 1) {
			return true;
		}
		break;
	case 3:
		if (matrix[maskY][maskX + 2] == 1 ||    
			matrix[maskY - 1][maskX + 2] == 1) {
			return true;
		}
		break;
	}
	return false;
}

bool J::checkLeft(int matrix[33][10]) {
		switch (position) {
		case 0:
			if (matrix[maskY - 1][maskX - 1] == 1 ||    
				matrix[maskY][maskX - 1] == 1 ||
				matrix[maskY - 1][maskX - 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY][maskX - 2] == 1 ||
				matrix[maskY + 1][maskX - 2] == 1) {
				return true;
			}
			break;
		case 2:
			if (matrix[maskY + 1][maskX - 1] == 1 ||    
				matrix[maskY][maskX - 1] == 1 ||
				matrix[maskY - 1][maskX - 2] == 1) {
				return true;
			}
			break;
		case 3:
			if (matrix[maskY][maskX + 2] == 1 ||    
				matrix[maskY - 1][maskX + 1] == 1) {
				return true;
			}
			break;
	}
	return false;
}

bool J::checkBottom(int matrix[33][10]) {
	switch (position) {
	case 0:
		if (matrix[maskY + 2][maskX] == 1 ||    
			matrix[maskY + 2][maskX + 1] == 1) {
			return true;
		}
		break;
	case 1:
		if (matrix[maskY + 1][maskX + 1] == 1 ||
			matrix[maskY + 1][maskX] == 1 ||
			matrix[maskY + 2][maskX - 1] == 1) {
			return true;
		}
		break;
	case 2:
		if (matrix[maskY + 2][maskX] == 1 ||
			matrix[maskY][maskX - 1] == 1) {
			return true;
		}
		break;
	case 3:
		if (matrix[maskY + 1][maskX - 1] == 1 ||    
			matrix[maskY + 1][maskX] == 1 || 
			matrix[maskY + 1][maskX + 1] == 1) {
			return true;
		}
		break;
	}
	return false;
}


J::~J()
{
}
