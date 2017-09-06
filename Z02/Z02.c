#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define size 10

void initMatr(uint8_t m[][size]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < size; i++) {
		for (uint8_t j = 0; j < size; j++) {
			m[i][j] = rand() % 10 + 1;
		}
	}
}

void printMatr(uint8_t m[][size]) {
	for (uint8_t i = 0; i < size; i++) {
		for (uint8_t j = 0; j < size; j++) {
			printf("%3hhi", m[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	uint8_t matr[size][size] = { 0 };
	uint16_t sum = 0;
	
	initMatr(matr);
	printf("Matrix: \n");
	printMatr(matr);
	printf("\n");

	uint8_t min = matr[0][0];
	uint8_t max = matr[0][0];

	for (uint8_t i = 0; i < size; i++) {
		uint8_t colSum = 0;
		for (uint8_t j = 0; j < size; j++) {
			sum += matr[i][j];

			if (matr[i][i] > max) {
				max = matr[i][j];
			}

			if (matr[i][i] < min) {
				min = matr[i][j];
			}
		}
	}

	printf("Sum of elements: %hu.\n", sum);
	printf("Arithmetical mean: %hu.\n", sum/(2*size));
	printf("Maximum element: %hu.\n", max);
	printf("Minimum element: %hu.\n", min);

	return 0;
}