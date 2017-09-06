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

void sort(uint16_t matr[][2], uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		for (uint8_t j = i + 1; j < size; j++) {
			if (matr[j][0] < matr[i][0]) {
				uint16_t box = matr[i][0];
				matr[i][0] = matr[j][0];
				matr[j][0] = box;

				box = matr[i][1];
				matr[i][1] = matr[j][1];
				matr[j][1] = box;
			}
		}
	}
}

uint8_t newMas(uint16_t mA[][2], uint16_t mB[][2], uint16_t mC[][2]) {
	uint16_t boxMas[rowA + rowB][2] = { 0 };
	uint8_t size = 0;

	for (uint8_t i = 0; i < rowA; i++) {
		boxMas[size][0] = mA[i][0];
		boxMas[size++][1] = mA[i][1];
	}

	for (uint8_t i = 0; i < rowB; i++) {
		boxMas[size][0] = mB[i][0];
		boxMas[size++][1] = mB[i][1];
	}

	sort(boxMas, rowA + rowB);
	printf("Both matrix sorted:\n");
	matrPrint(boxMas, rowA + rowB);

	uint8_t mCInd = 0;
	uint8_t boxMasInd = 0;
	mC[mCInd][0] = boxMas[boxMasInd][0];
	mC[mCInd][1] = boxMas[boxMasInd++][1];

	while (boxMasInd <= size) {
		if (boxMas[boxMasInd][0] <= mC[mCInd][1] && boxMas[boxMasInd][1] > mC[mCInd][1]) {
			mC[mCInd][1] = boxMas[boxMasInd][1];
		}
		else if (boxMas[boxMasInd][0] > mC[mCInd][1]) {
			mC[++mCInd][0] = boxMas[boxMasInd][0];
			mC[mCInd][1] = boxMas[boxMasInd][1];
		}
		boxMasInd++;
	}

	return mCInd;
}

int main(void) {
	uint16_t A[rowA][2] = { {1, 4}, {7, 9}, {11, 12}, {15, 18}, {20, 22} };
	uint16_t B[rowB][2] = { {0, 7}, {9, 11}, {15, 17}, {20, 31}, {37, 40} };
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