#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked.h"

void main() {
	FILE* ssv = fopen("mini6tester.ssv", "rt");
	if (ssv == NULL) {
		printf("\n File opening failed");
		exit(1);
	}

	int acct = 0;
	float amnt = 0;

	char line[100];
	while (fgets(line, sizeof(line), ssv)) {
		parse(line, &acct, &amnt);
		findUpdate(acct, amnt);
	}
	prettyPrint();
}
