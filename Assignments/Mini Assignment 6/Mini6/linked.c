#include <stdio.h>
#include <stdlib.h>

struct ACCOUNT {
	int accountNumber;
	float balance;
	struct ACCOUNT* next;
};

struct ACCOUNT* head = NULL;

void findUpdate(int account, float amount) {

	if (head == NULL) {
		head = (struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));
		head->accountNumber = account;
		head->balance = amount;
		head->next = NULL;
		return;
	}

	struct ACCOUNT* current = head;
	
	while (current->next!=NULL) {
		if (current->accountNumber == account) {
			current->balance = current->balance + amount;
			return;
		}
		current = current->next;
	}
	
	if (current->accountNumber==account) {
			current->balance = current->balance + amount;
			return;
}

		struct ACCOUNT* newAccount = (struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));
		if (newAccount == NULL) exit(1);
		current->next = newAccount;
		newAccount->accountNumber = account;
		newAccount->balance = amount;
		newAccount->next = NULL;
	

}

void prettyPrint() {
	struct ACCOUNT* current = head;
	while (current != NULL) {
		printf("ACCOUNT ID: %5d   BALANCE: $ %9.2f \n", current->accountNumber, current->balance);
		current = current->next;
	}
}

