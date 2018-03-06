#include "Z.h"

void Z::drawFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY + 1][maskX + 1] = 1;
		matrix[maskY + 1][maskX] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY][maskX - 1] = 1;
		break;
	case 1:
		matrix[maskY + 1][maskX - 1] = 1;
		matrix[maskY][maskX - 1] = 1;
		matrix[maskY][maskX] = 1;
		matrix[maskY - 1][maskX] = 1;
		break;
	default:
		break;
	}
}

void Z::clearFigure(int matrix[33][10]) {
	switch (position) {
	case 0:
		matrix[maskY + 1][maskX + 1] = 0;
		matrix[maskY + 1][maskX] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY][maskX - 1] = 0;
		break;
	case 1:
		matrix[maskY + 1][maskX - 1] = 0;
		matrix[maskY][maskX - 1] = 0;
		matrix[maskY][maskX] = 0;
		matrix[maskY - 1][maskX] = 0;
		break;
	default:
		break;
	}
}

void Z::rotateFigure(int matrix[33][10]) {
	clearFigure(matrix);
	position = (position + 1) % 2;
  switch (position) {
  case 0: 
        if(matrix[maskY - 1][maskX] != 1 &&
           matrix[maskY + 1][maskX - 1] != 1) {
           drawFigure(matrix);
        }
	  break;
  case 1:
        if(matrix[maskY + 1][maskX + 1] == 1) {
           maskX--; }
        if(matrix[maskY + 1][maskX] != 1 &&
           matrix[maskY + 1][maskX + 1] != 1) {
           drawFigure(matrix);
        }
	  break;
  default:
	  break;
		}
}



  



 // if (checkRight(matrix)) {
  //  maskX ++;
 // } else if (checkLeft(matrix)) {
 //   maskX = maskX - 2;
//  }
//	drawFigure(matrix);
// }

bool Z::checkRight(int matrix[33][10]) {
	if (maskX > 1) {
		switch (position) {
		case 0:
			if (matrix[maskY][maskX - 2] == 1 ||
				matrix[maskY - 1][maskX + 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY - 1][maskX - 2] == 1 ||
				matrix[maskY][maskX - 2] == 1 ||
				matrix[maskY + 1][maskX - 1] == 1) {
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

bool Z::checkLeft(int matrix[33][10]) {
	if (maskX < 7) {
		switch (position) {
		case 0:
			if (matrix[maskY + 2][maskX] == 1 ||
        matrix[maskY + 1][maskX - 1] == 1 ||
        matrix[maskY + 1][maskX + 1] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY + 1][maskX - 1] == 1 ||
       matrix[maskY - 1][maskX + 2] == 1) {
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

bool Z::checkBottom(int matrix[33][10]) {
	if (maskY < 30) {
		switch (position) {
		case 0:
			if (matrix[maskY + 2][maskX] == 1 ||
			  matrix[maskY + 2][maskX] == 1 ||
        matrix[maskY + 2][maskX] == 1) {
				return true;
			}
			break;
		case 1:
			if (matrix[maskY + 1][maskX] == 1 ||
				matrix[maskY + 2][maskX - 1] == 1) {
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


Z::~Z()
{
}
