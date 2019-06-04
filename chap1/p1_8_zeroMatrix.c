/* Christopher Feener
 * Started on June 4, 2019
 * Zero entire row and column of a matrix where an entry is zero.
 */
#define N 3
#define M 3

#include <stdio.h>
#include <stdlib.h> 	//For calloc() and free()

void printMatrix(unsigned int * matrix, unsigned int n, unsigned int m) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%i ", matrix[i * n + j]);
                printf("\n");
        }
}

void process(unsigned int * matrix, unsigned int n, unsigned int m) {
	int i, j;
	int a, b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[n * i + j] == 0) {
				for (a = 0; a < n; a++)
					matrix[n * a + j] = 0;
				for (b = 0; b < m; b++)
					matrix[n * i + b] = 0;
			}
		}
	}
}

int main (void) {
	unsigned int n = N, m = M;
	unsigned int * matrix = (unsigned int *)calloc(n * m, sizeof(unsigned int));

	//Initialize:
	unsigned int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			matrix[n * i + j] = n * i + j;
		}
	}

	printf("Before: \n");
	printMatrix(matrix, n, m);

	process(matrix, n, m);

	printf("After: \n");
	printMatrix(matrix, n, m);

	free(matrix);

	return 0;
}
