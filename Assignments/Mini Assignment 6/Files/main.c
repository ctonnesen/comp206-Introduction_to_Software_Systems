// Christian Tonnesen
// 260847409

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked.h"

// The linked.h header is included to declare the functions from other source files

void main() {
	FILE* ssv = fopen("mini6tester.ssv", "rt");
	if (ssv == NULL) {
		printf("\n File opening failed");
		exit(1);
	}

// A variable of type FILE is created, and in the event the file does not exit, exits the function.

	int acct = 0;
	float amnt = 0;

	char line[100];
	while (fgets(line, sizeof(line), ssv)) {
		parse(line, &acct, &amnt);
		findUpdate(acct, amnt);
	}
	prettyPrint();
}

// The while loop goes line by line through the ssv and passees the current line to parse() with our acct and ammnt variables. Then, these variables are sent to findUpdate and update their respective nodes. Finally, after reaching the end of file, prettyPrint() prints all nodes.
