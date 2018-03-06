#include "O.h"

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
