#include "Figures.h"

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

void O::drawFigure(int matrix[33][10]) {
	matrix[maskY][maskX - 1] = 1;
	matrix[maskY][maskX] = 1;
	matrix[maskY - 1][maskX] = 1;
	matrix[maskY - 1][maskX - 1] = 1;
}

void O::clearFigure(int matrix[33][10]) {
	matrix[maskY][maskX - 1] = 0;
	matrix[maskY][maskX] = 0;
	matrix[maskY - 1][maskX] = 0;
	matrix[maskY - 1][maskX - 1] = 0;
}

void O::rotateFigure(int matrix[33][10]) {
}

bool O::checkRight(int matrix[33][10]) {
	if (matrix[maskY][maskX + 1] == 1 ||    
		matrix[maskY - 1][maskX + 1] == 1) {
		return true;
	}
	return false;
}

bool O::checkLeft(int matrix[33][10]) {
	if (matrix[maskY][maskX - 2] == 1 ||    
		matrix[maskY - 1][maskX - 2] == 1) {
		return true;
	}
	return false;
}

bool O::checkBottom(int matrix[33][10]) {
	if (matrix[maskY + 1][maskX] == 1 ||    
			matrix[maskY + 1][maskX - 1] == 1) {
		return true;
	}
	return false;
}


O::~O()
{
}