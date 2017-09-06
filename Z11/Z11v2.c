#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define rowA 5
#define rowB 5

void matrPrint(uint16_t matr[][2], uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		for (uint8_t j = 0; j < 2; j++) {
			printf("%3hi ", matr[i][j]);
		}
		printf("\n");
	}
}

uint8_t newMas(uint16_t mA[][2], uint16_t mB[][2], uint16_t mC[][2]) {
	uint8_t indA = 0;
	uint8_t indB = 0;
	uint8_t indC = -1;
	bool flag = true;

	while (indA < rowA && indB < rowB) {
		indC++;
		if (mA[indA][0] <= mB[indB][0]) {
			mC[indC][0] = mA[indA][0];
			mC[indC][1] = mA[indA][1];
			indA++;
			flag = true;
		}
		else {
			mC[indC][0] = mB[indB][0];
			mC[indC][1] = mB[indB][1];
			indB++;
			flag = false;
		}

		while (true) {
			if (flag) {
				if (mB[indB][0] <= mC[indC][1] && mB[indB][1] > mC[indC][1]) {
					mC[indC][1] = mB[indB++][1];
					flag = false;
				}
				else if (mB[indB][1] < mC[indC][1]) {
					indB++;
				}
				else {
					break;
				}
			}
			else {
				if (mA[indA][0] <= mC[indC][1] && mA[indA][1] > mC[indC][1]) {
					mC[indC][1] = mA[indA++][1];
					flag = true;
				}
				else if (mA[indA][1] < mC[indC][1]) {
					indA++;
				}
				else {
					break;
				}
			}//else

			if (indA >= rowA || indB >= rowB) {
				break;
			}
		}//while(true)
	}

	//indC++;
	while (indA < rowA) {
		if (mA[indA][0] <= mC[indC][1] && mA[indA][1] > mC[indC][1]) {
			mC[indC][1] = mA[indA++][1];
		}
		else {
			indC++;
			mC[indC][0] = mA[indA][0];
			mC[indC][1] = mA[indA++][1];
		}
	}
	while (indB < rowB) {
		if (mB[indB][0] <= mC[indC][1] && mB[indB][1] > mC[indC][1]) {
			mC[indC][1] = mB[indB++][1];
		}
		else {
			indC++;
			mC[indC][0] = mB[indB][0];
			mC[indC][1] = mB[indB++][1];
		}
	}

	return indC + 1;
}

int main(void) {
	uint16_t A[rowA][2] = { { 1, 4 },{ 7, 9 },{ 11, 12 },{ 15, 18 },{ 20, 22 } };
	uint16_t B[rowB][2] = { { 0, 2 },{ 9, 11 },{ 15, 17 },{ 20, 23 },{ 25, 27 } };

/*	uint16_t A[rowA][2] = { { 3, 4 },{ 7, 9 },{ 12, 13 },{ 18, 20 },{ 21, 22 } };
	uint16_t B[rowB][2] = { { 0, 2 },{ 10, 11 },{ 15, 17 },{ 23, 25 },{ 26, 27 } };*/

/*	uint16_t A[rowA][2] = { { 2, 4 },{ 7, 9 },{ 11, 12 },{ 15, 18 },{ 20, 22 } };
	uint16_t B[rowB][2] = { { 0, 2 },{ 4, 7 },{ 9, 11 },{ 12, 15 },{ 18, 20 } };*/

	uint16_t C[rowA + rowB][2] = { 0 };

	printf("Matrix A:\n");
	matrPrint(A, rowA);

	printf("Matrix B:\n");
	matrPrint(B, rowB);

	uint8_t CSize = newMas(A, B, C);

	printf("Matrix C:\n");
	matrPrint(C, CSize);

	return 0;
}