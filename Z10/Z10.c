#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5

void initMatr(uint8_t m[][SIZE]) {
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			m[i][j] = rand() % 51;
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

bool checkElem(uint8_t m[][SIZE], uint8_t el) {
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			if (m[i][j] == el) {
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	uint8_t mA[SIZE][SIZE] = { 0 };
	uint8_t mB[SIZE][SIZE] = { 0 };

	srand((unsigned int)time(NULL));

	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	initMatr(mB);
	printf("Matrix B:\n");
	printMatr(mB);

	printf("Elements:");
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			if (!checkElem(mB, mA[i][j])) {
				printf("%4hhi", mA[i][j]);
			}
		}
	}
	printf("\n");

	return 0;
}