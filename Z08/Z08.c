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
			printf("%4hi", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	uint8_t mA[SIZE][SIZE] = { 0 };
	uint8_t num = 0;

	for (uint8_t i = 1; i <= SIZE/2; i++) {
		for (uint8_t j = i - 1; j < SIZE - i; j++) {
			mA[i - 1][j] = num++;
		}

		for (uint8_t j = i - 1; j < SIZE - i; j++) {
			mA[j][SIZE - i] = num++;
		}

		for (uint8_t j = SIZE - i; j >= i; j--) {
			mA[SIZE - i][j] = num++;
		}

		for (uint8_t j = SIZE - i; j >= i; j--) {
			mA[j][i - 1] = num++;
		}
	}

	if (SIZE % 2 != 0) {
		mA[SIZE / 2][SIZE / 2] = num;
	}

	printf("Matrix A:\n");
	printMatr(mA);
	
	return 0;
}