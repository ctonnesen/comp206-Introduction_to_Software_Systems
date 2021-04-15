// Christian Tonnesen
// 260847409


#include <stdio.h>
#include <stdlib.h>

struct ACCOUNT {
	int accountNumber;
	float balance;
	struct ACCOUNT* next;
};

// Type ACCOUNT is declared for future use

struct ACCOUNT* head = NULL;

// Global variable head is set to NULL

void findUpdate(int account, float amount) {

	if (head == NULL) {
		head = (struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));
		head->accountNumber = account;
		head->balance = amount;
		head->next = NULL;
		return;
	}

// If head has not been filled with data yet, i.e. NULL, then allocate memory and fill it with the first line of the tester SSV

	struct ACCOUNT* current = head;

// Our traverser variable is created and set equal to the head of the list
	
	while (current->next!=NULL) {
		if (current->accountNumber == account) {
			current->balance = current->balance + amount;
			return;
		}

	current = current->next;
	}

// We go through the linked list until we reach the second to last node and if the account number matches any linked list node, we update the value

	if (current->accountNumber==account) {
			current->balance = current->balance + amount;
			return;
	}

// We check the last node to ensure it is not also from an existing account. In the event it is, we return and exit the function

		struct ACCOUNT* newAccount = (struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));
		if (newAccount == NULL) exit(1);
		current->next = newAccount;
		newAccount->accountNumber = account;
		newAccount->balance = amount;
		newAccount->next = NULL;

// Assuming the line hasn't matched any bank accounts, we make a new node with the bank number and add it to the end of the list
	
}

void prettyPrint() {
	struct ACCOUNT* current = head;
	while (current != NULL) {
		printf("ACCOUNT ID: %5d   BALANCE: $ %9.2f \n", current->accountNumber, current->balance);
		current = current->next;
	}
}

// While we don't hit the end of the of the linked list, print out the account number and balance of current node. Then, move the current to the next node

