#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5

void initMatr(uint16_t m[][SIZE]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			m[i][j] = rand() % 10 + 1;
		}
	}
}

void printMatr(uint16_t m[][SIZE]) {
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			printf("%4hi", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	uint16_t mA[SIZE][SIZE] = { 0 };
	uint16_t mB[SIZE][SIZE] = { 0 };
	
	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			if (i == 0 && j == 0) {
				mB[i][j] = mA[i][j];
			}
			else {
				mB[i][j] = mA[i][j] + ((j == 0 && i > 0) ? mB[i - 1][SIZE - 1] : mB[i][j - 1]);
			}
		}
	}

	printf("Matrix B:\n");
	printMatr(mB);

	return 0;
}