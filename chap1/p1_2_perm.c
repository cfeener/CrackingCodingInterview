#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPerm(char * s1, char *s2) {
	int a = strlen(s1), b = strlen(s2);
	if (a != b) return false;

	//TODO
	return true;
}

int main (void) {
	char * s1 = "This is the sentence";
	char * s2 = "Tihs is the sentence";
	char * sd = "Different!";

	if (isPerm(s1, s2)) 
		printf("Sentences s1 and s2 are permutations!\n");
	else printf("Sentences s1 and s2 are NOT permutations.\n");

	return 0;	
}
