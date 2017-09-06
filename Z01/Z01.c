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
	uint8_t rowSum[size] = { 0 };
	uint16_t sum = 0;

	initMatr(matr);
	printf("Matrix: \n");
	printMatr(matr);
	printf("\n");

	for (uint8_t i = 0; i < size; i++) {
		uint8_t colSum = 0;
		for (uint8_t j = 0; j < size; j++) {
			printf("%3hhu", matr[i][j]);
			colSum += matr[i][j];
			rowSum[j] += matr[i][j];
			sum += matr[i][j];
		}
		printf(" | %hhu\n", colSum);
	}

	printf("--------------------\n");
	for (uint8_t i = 0; i < size; i++) {
		printf("%3hhu", rowSum[i]);
	}
	printf(" | %hu\n", sum);

	return 0;
}