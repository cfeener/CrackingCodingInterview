/* Christopher Feener
 * Checks for duplicate characters in a string.
 */

#include <stdio.h>
#include <string.h>	//For strlen()
#include <ctype.h>	//For tolower()

#define BUF_SIZE 512
#define ALPHA_SIZE 26

int main (void) {

	char alpha[ALPHA_SIZE];
	int i;
	for (i = 0; i < ALPHA_SIZE; i++)
		alpha[i] = 0;

	printf("Please enter a string to check for duplicate letters: \n");

	char buffer[BUF_SIZE] = {'\0'};
	while (fgets(buffer, BUF_SIZE, stdin) == NULL)
		printf("Please input a string\n");

	int n = strlen(buffer);
	int flag = 0;
	for (i = 0; i < n; i++) {
		if (!isalpha(buffer[i]))
			continue;
		int x = ++alpha[tolower(buffer[i] - 'a')];
		if (x > 1) {
			flag++;
			break;
		}
	}

	if (flag != 0)
		printf("Duplicates found.\n");
	else printf("Duplicates NOT found!!\n");

	return 0;
}
