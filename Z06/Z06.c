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

void matrSort(uint8_t row[]) {
	for (uint8_t i = 0; i < SIZE - 1; i++) {
		for (uint8_t j = i; j < SIZE; j++) {
			if (row[i] > row[j]) {
				uint8_t box = row[i];
				row[i] = row[j];
				row[j] = box;
			}
		}
	}
}

int main(void) {
	uint8_t mA[SIZE][SIZE] = { 0 };
	uint8_t n = 0;

	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	for (uint8_t i = 0; i < SIZE; i++) {
		matrSort(mA[i]);
	}

	printf("Matrix A:\n");
	printMatr(mA);

	return 0;
}