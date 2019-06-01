/* Christopher Feener
 * Started on 5/28/2019
 * Rotates an array of 4-byte values 90-degrees.
 */

#define Matrix_Size 3

#include <stdio.h>
#include <inttypes.h>	//For uint32_t
#include <stdlib.h>	//For calloc()

//Method: Swap 4 variables in much the same way as swapping 2 variables (5 lines)

void printMatrix(uint32_t * matrix, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%u ", matrix[i * n + j]);
		printf("\n");
	}
}

void rotateMatrix(uint32_t * matrix, int n) {
	int c, i, cycles = n/2;
	for (c = 0; c < cycles; c++) {
		for (i = c; i < n - c - 1; i++) {	//Go along first row of each cycle
			uint32_t temp = matrix[n * c + i];
			//Based on https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
			matrix[n * c + i] = matrix[n * (n - 1 - i) + c];	//Equals value from CCW, so result is CW
			matrix[n * (n - 1 - i) + c] = matrix[n * (n - 1 - c) + (n - 1 - i)];
			matrix[n * (n - 1 - c) + (n - 1 - i)] = matrix[n * i + (n - 1 - c)];
			matrix[n * i + (n - 1 - c)] = temp;
		}
	}
}

int main (void) {

	int n = Matrix_Size;	//3X3 Matrix
	uint32_t * matrix = calloc(n * n, sizeof(uint32_t));

	//Initialize sample values:
	int i, j;
	for (i = 0; i < n; i++) {	//Rows
		for (j = 0; j < n; j++)	//Columns
			matrix[i * n + j] = i * n + j;
	}

	printf("Before: \n");
	printMatrix(matrix, n);

	rotateMatrix(matrix, n);

	printf("\nAfter: \n");
	printMatrix(matrix, n);

	free(matrix);

	return 0;
}
