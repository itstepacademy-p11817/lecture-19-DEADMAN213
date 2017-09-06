#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5

void initMatr(uint8_t m[][SIZE]) {
	srand((unsigned int)time(NULL));
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = 0; j < SIZE; j++) {
			m[i][j] = rand() % 6;
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

uint8_t zeroCount(uint8_t m[]) {
	uint8_t num = 0;
	for (uint8_t i = 0; i < SIZE; i++) {
		if (m[i] == 0) {
			num++;
		}
	}

	return num;
}

void rowDell(uint8_t m[][SIZE], uint8_t row) {
	for (uint8_t i = 0; i < SIZE; i++) {
		for (uint8_t j = row; j < SIZE - 1; j++) {
			m[j][i] = m[j + 1][i];
		}
	}

	for (uint8_t i = 0; i < SIZE; i++) {
		m[SIZE - 1][i] = 0;
	}
}

int main(void) {
	uint8_t mA[SIZE][SIZE] = { 0 };
	uint8_t numRow[SIZE] = { 0 };

	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	uint8_t max = 0;
	uint8_t ind = 0;
	bool flag = true;
	for (uint8_t i = 0; i < SIZE; i++) {
		uint8_t zero = zeroCount(mA[i]);
		if (zero > max) {
			ind = i;
			max = zero;
			flag = true;
		}
		else if (zero == max) {
			flag = false;
		}
	}

	if (flag) {
		rowDell(mA, ind);
	}
	
	printf("Matrix A:\n");
	printMatr(mA);

	return 0;
}