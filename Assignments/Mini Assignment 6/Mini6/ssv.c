#include<stdio.h>
#include<stdlib.h>

void parse(char record[], int* acct, float* amnt) {
	sscanf(record, "%d %f", acct, amnt);
	return;
}