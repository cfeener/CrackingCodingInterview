/* Christopher Feener
 * Started on 5/28/2019
 * Rotates an array of 4-byte values 90-degrees.
 */

#define Matrix_Size 3

#include <stdio.h>
#include <inttypes.h>	//For uint32_t
#include <stdlib.h>	//For calloc()

//TODO: Swap 4 variables in much the same way as swapping 2 variables (5 lines), 
//	OR 'xor'-swap 3 times (3 * 3 lines).

int main (void) {

	int n = Matrix_Size;	//3X3 Matrix
	uint32_t * matrix = calloc(n * n, sizeof(uint32_t));

	//Initialize sample values:
	int i, j;
	for (i = 0; i < n; i++) {	//Rows
		for (j = 0; j < n; j++) {	//Columns
			matrix[i * n + j] = i * n + j;
			printf("%u ", matrix[i * n + j]);	//TODO: Debug
		}
		printf("\n");
	}

	return 0;
}
