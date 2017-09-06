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
	uint8_t n = 0;

	initMatr(mA);
	printf("Matrix A:\n");
	printMatr(mA);

	printf("Menu:\n");
	printf("1 - Left.\n");
	printf("2 - Right.\n");
	printf("3 - Up.\n");
	printf("4 - Down.\n");
	printf("Input choice: ");

	uint8_t ch = 0;
	scanf_s("%hhi", &ch);

	printf("Input moves: ");
	scanf_s("%hhi", &n);
	n %= SIZE;

	switch (ch) {
	case 1:
		for (uint8_t k = 0; k < n; k++) {
			for (uint8_t i = 0; i < SIZE; i++) {
				uint8_t box = mA[i][0];
				for (uint8_t j = 0; j < SIZE - 1; j++) {
					mA[i][j] = mA[i][j + 1];
				}
				mA[i][SIZE - 1] = box;
			}
		}
		break;

	case 2:
		for (uint8_t k = 0; k < n; k++) {
			for (uint8_t i = 0; i < SIZE; i++) {
				uint8_t box = mA[i][SIZE - 1];
				for (uint8_t j = SIZE - 1; j > 0; j--) {
					mA[i][j] = mA[i][j - 1];
				}
				mA[i][0] = box;
			}
		}
		break;

	case 3:
		for (uint8_t k = 0; k < n; k++) {
			for (uint8_t i = 0; i < SIZE; i++) {
				uint8_t box = mA[0][i];
				for (uint8_t j = 0; j < SIZE - 1; j++) {
					mA[j][i] = mA[j + 1][i];
				}
				mA[SIZE - 1][i] = box;
			}
		}
		break;

	case 4:
		for (uint8_t k = 0; k < n; k++) {
			for (uint8_t i = 0; i < SIZE; i++) {
				uint8_t box = mA[SIZE - 1][i];
				for (uint8_t j = SIZE - 1; j > 0; j--) {
					mA[j][i] = mA[j - 1][i];
				}
				mA[0][i] = box;
			}
		}
		break;
	}

	printf("Matrix A:\n");
	printMatr(mA);

	return 0;
}