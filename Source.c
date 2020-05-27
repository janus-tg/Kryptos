#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMenu(); //function to print the initial menu
void encryptMenu(); //list of ciphers to encrypt
void decryptMenu(); //list of ciphers to decrypt
void caesarEncrypt(); //function to encrypt in Caesar cipher
void caesarDecrypt(); //function to decrypt in Caesar cipher
void scytaleEncrypt(); //function to encrypt in Scytale cipher
void scytaleDecrypt(); //function to decrypt in scytale cipher


int main(void) {
	printMenu();
	return 0;
}

void printMenu() {
	int input = 0;
	do {
		printf("\n\nEnter 0 to decrypt and 1 to encrypt (Enter any other number to exit): ");
		scanf("%d", &input);
		if (input == 1) {
			encryptMenu();
		}
		else if (input == 0) {
			decryptMenu();
		}
		else {
			return;
		}
	} while (input != 0 || input != 1);
}
void encryptMenu() {
	int input = 0;
	puts("\nList of ciphers available:");
	puts("\n1. Caesar shift");
	puts("2. Scytale cipher");
	printf("Enter the number of cipher: ");
	scanf("%d", &input);
	switch (input) {
	case 1:
		caesarEncrypt();
	case 2:
		scytaleEncrypt();
	}
}
void decryptMenu() {
	int input = 0;
	puts("\nList of ciphers available:");
	puts("\n1. Caesar shift");
	puts("2. Scytale cipher");
	printf("\nEnter the number of cipher: ");
	scanf("%d", &input);
	switch (input) {
	case 1:
		caesarDecrypt();
	case 2:
		scytaleDecrypt();
	}

}
void caesarEncrypt() {
	int shift = 0;
	char* input;
	input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThe Caesar shift is one of the oldest encryption techniques was used by Julius Caesar to encrypt");
	puts("millitary messages. This is a substitution cipher and it usually shifted and alphabets with 3 alphabets\n");
	puts("down the alphabets. My program lets the user use this substitution for any shift value between 1-25.\n");
	printf("\nEnter the shift value (1-25): ");
	scanf("%d", &shift);
	getchar(); //to remove the enter from scanf
	puts("Enter text for encryption in Caesar shift (lowercase only):\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = (input[i] + shift - 'a') % 26 + 'a';
		}
	}
	puts("\nEncrypted text:\n");
	printf("%s", input);
	free(input);
}
void caesarDecrypt() {
	int shift = 0;
	char* input;
	input = (char*)malloc(sizeof(char) * 2001);
	printf("\nEnter the shift value (1-25): ");
	scanf("%d", &shift);
	getchar(); //to remove the enter from scanf
	puts("\nEnter text for decryption in Caesar shift (lowercase only):\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = (input[i] + (26 - shift) - 'a') % 26 + 'a'; //using the fact that decryption will be 26 - shift
		}
	}
	puts("\nDecrypted text:\n");
	printf("%s", input);
	free(input);
}
void scytaleEncrypt() {
	int diameter = 0;
	char* input;
	char** output;
	input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThe ancient Greeks and Spartans used this cipher to communicate mainly during millitary campaigns");
	puts("The user used a rod of the same diameter on which the original message was written and read the decrypted message");
	puts("wrapping the parchment around the rod and reading the message");
	printf("\nEnter the diameter (only positive integer): ");
	scanf("%d", &diameter);
	getchar(); //to remove the enter from scanf
	
	output = (char**)calloc(strlen(input)+2, sizeof(char*));
	for (int i = 0; i < strlen(input) + 2; i++) {
		output[i] = (char*)calloc(strlen(input) + 2, sizeof(char));
	}
	if (diameter >= strlen(input) || diameter == 1) {
		puts("Wrong diameter! Enter a diamter greater than 1 and not exceeding the total characters entered.");
	}
	else {
		puts("Enter text for encryption in Scytale (lowercase only):\n");
		fgets(input, 2000, stdin);
		strtok(input, "\n"); //this to remove the \n from using fgets
		int k = 0, row, col;
		for (row = 0; row < strlen(input) && k < strlen(input); row++) {
			for (col = 0; col < diameter && k < strlen(input); col++) {
				output[row][col] = input[k];
				k++;
			}
		}
		puts("\nEncrypted text:\n");
		for (int i = 0; i < diameter; i++) {
			for (int j = 0; j <= row; j++) {
				if (output[j][i] != 0) {
					printf("%c", output[j][i]);
				}
			}
		}
	}
	for (int i = 0; i < strlen(input) + 2; i++) {
		free(output[i]);
	}
	free(input);
	free(output);
}
void scytaleDecrypt() {
	int diameter = 0;
	char* input;
	char** output;
	input = (char*)malloc(sizeof(char) * 2001);
	output = (char**)calloc(strlen(input) + 2, sizeof(char*));
	for (int i = 0; i < strlen(input) + 2; i++) {
		output[i] = (char*)calloc(strlen(input) + 2, sizeof(char));
	}
	printf("\nEnter the diameter (only positive integer): ");
	scanf("%d", &diameter);
	getchar(); //to remove the enter from scanf
	if (diameter >= strlen(input) || diameter == 1) {
		puts("Wrong diameter! Enter a diamter greater than 1 and not exceeding the total characters entered.");
	}
	else {
		puts("Enter text for decryption in Scytale (lowercase only):\n");
		fgets(input, 2000, stdin);
		strtok(input, "\n"); //this to remove the \n from using fgets
		int k = 0, row, col;
		for (row = 0; row < strlen(input) && k < strlen(input); row++) {
			for (col = 0; col <= diameter && k < strlen(input); col++) {
				output[row][col] = input[k];
				k++;
			}
		}
		puts("\nDecrypted text:\n");
		for (int i = 0; i <= diameter; i++) {
			for (int j = 0; j <= row; j++) {
				if (output[j][i] != 0) {
					printf("%c", output[j][i]);
				}
			}
		}
	}
	for (int i = 0; i < strlen(input) + 2; i++) {
		free(output[i]);
	}
	free(input);
	free(output);
}