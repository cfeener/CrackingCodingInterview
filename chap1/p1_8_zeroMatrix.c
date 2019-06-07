/* Christopher Feener
 * Started on June 4, 2019
 * Zero entire row and column of a matrix where an entry is zero.
 */
#define N 10
#define M 10

#include <stdio.h>
#include <stdlib.h> 	//For calloc() and free()
#include <stdbool.h>	//For true, false
#include <time.h>	//For time()

void printMatrix(unsigned int * matrix, unsigned int n, unsigned int m) {
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++)
                        printf("%02i ", matrix[i * n + j]);
                printf("\n");
        }
}

void process(unsigned int * matrix, bool * is_done, unsigned int n, unsigned int m) {
	int i, j;
	int a, b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (is_done[n * i + j])
				continue;
			else if (matrix[n * i + j] == 0) {
				for (a = 0; a < n; a++) {
					matrix[n * a + j] = 0;
					is_done[n * a + j] = true;
				}
				for (b = 0; b < m; b++) {
					matrix[n * i + b] = 0;
					is_done[n * i + b] = true;
				}
			}
		}
	}
}

int main (void) {
	unsigned int n = N, m = M;
	unsigned int * matrix = (unsigned int *)calloc(n * m, sizeof(unsigned int));
	bool * is_done = (bool *)calloc(n * m, sizeof(bool));

	//Initialize:
	srand(time(NULL));
	unsigned int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if ((i == 3 && j == 7) || (i == 8 && j == 1))
				matrix[n * i + j] = 0;
			else
				matrix[n * i + j] = rand() % 90 + 10;
			is_done[n * i + j] = false;
		}
	}

	printf("Before: \n");
	printMatrix(matrix, n, m);

	process(matrix, is_done, n, m);

	printf("After: \n");
	printMatrix(matrix, n, m);

	free(matrix);

	return 0;
}
