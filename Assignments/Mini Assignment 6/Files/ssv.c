// Christian Tonnesen
// 260847409


#include<stdio.h>
#include<stdlib.h>

void parse(char record[], int *acct, float *amnt) {
	sscanf (record, "%d %f", acct, amnt);
	return;
}

// The variables of account and amount are passed to the parse function by memory address and are assigned the values from their line of the sscanf
