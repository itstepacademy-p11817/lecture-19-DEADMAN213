#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5

void initMatr(uint8_t m[][SIZE]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			m[i][j] = rand() % 10 + 1;
		}
	}
}

void printMatr(uint8_t m[][SIZE]) {
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			printf("%4hhi", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	uint8_t mA[SIZE][SIZE] = { 0 };
	uint8_t mB[SIZE][SIZE] = { 0 };
	uint8_t mC[SIZE][SIZE] = { 0 };

	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	initMatr(mB);
	printf("Matrix B:\n");
	printMatr(mB);

	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			mC[i][j] = mA[i][j] * mB[i][j];
		}
	}

	printf("Matrix C:\n");
	printMatr(mC);

	return 0;
}