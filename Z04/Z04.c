#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void initMatr(uint8_t m[][SIZE]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < SIZE/2; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			m[i][j] = rand() % 51;
		}
	}
}

int main(void) {
	uint8_t mA[SIZE/2][SIZE] = { 0 };
	uint8_t mB[SIZE/2][SIZE/2] = { 0 };

	initMatr(mA);
	printf("Matrix A:\n");
	for (uint8_t i = 0; i < SIZE / 2; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			printf("%4hhi", mA[i][j]);
		}
		printf("\n");
	}

	for (uint8_t i = 0; i < SIZE / 2; i++) {
		uint8_t k = 0;
		for (uint8_t j = 0; j < SIZE / 2; j++) {
			mB[i][j] = mA[i][k] + mA[i][k + 1];
			k += 2;
		}
	}

	printf("Matrix B:\n");
	for (uint8_t i = 0; i < SIZE / 2; i++) {
		for (uint8_t j = 0; j < SIZE / 2; j++) {
			printf("%4hhi", mB[i][j]);
		}
		printf("\n");
	}

	return 0;
}