// Christian Tonnesen
// 260847409

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

if (argc != 3) {
	printf ("Wrong number of arguments. Please input ./reverse WORD1 WORD2\n");
	return 1;
	}

// If statmement checks to see if there is an incorrect number of arguments

int reverse_c = 0;

int counter = 0;

int length = strlen(argv[1]);

// strlen gets the length of the first word

for (int i = length-1; 0 <= i; i--) {
	if (argv[1][i] != argv[2][reverse_c]) {
		counter++;
		
		// The for loop starts at the end of the first word and checks if it equals the first character of the second word

		}
	reverse_c++;
	}	

// The reverse c++ is what increments the second word index  forward


if (0 ==  counter) {
	printf ("WORD1=%s WORD2=%s - REVERSE\n", argv[1], argv[2]);
} else {
	printf ("WORD1=%s WORD2=%s - NOT REVERSE\n", argv[1], argv[2]);

}

// If counter is greater than 0, then the words are not reversed

}
