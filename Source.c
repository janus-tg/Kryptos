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
void atbashEncrypt(); //function to encrypt in Atbash cipher
void atbashDecrypt(); //function to decrypt in Atbash cipher
void affineEncrypt(); //function to encrypt in Affine cipher
void affineDecrypt(); //function to decipher in affine cipher 
int moduloMultiInverse(int a); //function to calculate the modular multiplicative inverse of an integer a with 26
void vigenereEncrypt();
void vigenereDecrypt();

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
	puts("\n1. Atbash cipher (circa 500 B.C.E");
	puts("2. Scytale cipher (circa 440 B.C.E");
	puts("3. Caesar shift  (circa 60 B.C.E)");
	puts("4. Affine cipher");
	puts("5. Vigenere cipher (circa 1500 C.E");
	puts("6. Bacon cipher (1605 C.E)");
	puts("7. Playfair cipher  (1854 C.E)");
	puts("8. Bifid cipher (circa 1900 C.E)");
	puts("9. ADVGVX cipher (circa 1917 C.E)");
	puts("10. Hill Cipher (1929 C.E)");
	printf("\nEnter the number of cipher: ");
	scanf("%d", &input);
	if (input == 1) {
		atbashEncrypt();
	}
	else if (input == 2) {
		scytaleEncrypt();
	}
	else if (input == 3) {
		caesarEncrypt();
	}
	else if (input == 4) {
		affineEncrypt();
	}
	else if (input == 5) {
		vigenereEncrypt();
	}
	else {
		fputs("Wrong input!", stdout);
		return;
	}
}
void decryptMenu() {
	int input = 0;
	puts("\nList of ciphers available:");
	puts("\n1. Atbash cipher (circa 500 B.C.E)");
	puts("2. Scytale cipher (circa 440 B.C.E(");
	puts("3. Caesar shift  (circa 60 B.C.E)");
	puts("4. Affine cipher");
	puts("5. Vigenere cipher (circa 1500 C.E");
	puts("6. Bacon cipher (1605 C.E)");
	puts("7. Playfair cipher  (1854 C.E)");
	puts("8. Bifid cipher (circa 1900 C.E)");
	puts("9. ADVGVX cipher (circa 1917 C.E)");
	puts("10. Hill Cipher (1929 C.E)");
	printf("\nEnter the number of cipher: ");
	scanf("%d", &input);
	if (input == 1) {
		atbashDecrypt();
	}
	else if (input == 2) {
		scytaleDecrypt();
	}
	else if (input == 3) {
		caesarDecrypt();
	}
	else if (input == 4) {
		affineDecrypt();
	}
	else if (input == 5) {
		vigenereDecrypt();
	}
	else {
		fputs("Wrong input!", stdout);
		return;
	}
}
void caesarEncrypt() {
	int shift = 0;
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThe Caesar shift is one of the oldest encryption techniques was used by Julius Caesar to encrypt");
	puts("millitary messages. This is a substitution cipher and it usually shifted and alphabets with 3 alphabets");
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
	fputs(input, stdout);
	free(input);
}
void caesarDecrypt() {
	int shift = 0;
	char* input = (char*)malloc(sizeof(char) * 2001);
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
	fputs(input, stdout);
	free(input);
}
void scytaleEncrypt() {
	int diameter = 0;
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThe ancient Greeks and Spartans used this cipher to communicate mainly during millitary campaigns");
	puts("The user used a rod of the same diameter on which the original message was written and read the decrypted message");
	puts("wrapping the parchment around the rod and reading the message");
	printf("\nEnter the diameter (only positive integer): ");
	scanf("%d", &diameter);
	getchar(); //to remove the enter from scanf
	
	char** output = (char**)calloc(strlen(input)+2, sizeof(char*));
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
	char* input = (char*)malloc(sizeof(char) * 2001);
	char** output = (char**)calloc(strlen(input) + 2, sizeof(char*));
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
void atbashEncrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThis an ancient cipher which has been used to encrypt the Hebrew alphabet. Its usage can be extensively");
	puts("seen in Biblical verses of the old testament or the Hebrew Bible\n");
	puts("Enter text for encryption in Atbash cipher:\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {//if lower case letters are entered
			input[i] = 'z' - input[i] + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {//if upper case letters are entered
			input[i] = 'Z' - input[i] + 'A';
		}
	}
	puts("\nEncrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void atbashDecrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("Enter text for Decryption in Atbash:\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {//if lower case letters are entered
			input[i] = 'z' - input[i] + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {//if upper case letters are entered
			input[i] = 'Z' - input[i] + 'A';
		}
	}
	puts("\nDecrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void affineEncrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	int a, b;
	puts("\nThe Affine cipher is a type of a mono-alphabetic substituion cipher where each letter is represented by a");
	puts("number which is substituted in a linear equation and the resulting number obtained is replaced by an alphabet.");
	puts("My version of the Affine cipher will utilize (ax + b) as the function where 'a' and 'b' are entered by the user");
	printf("\nEnter value of 'a' (Must be co-prime with 26): ");
	scanf("%d", &a);
	printf("Enter value of 'b': ");
	scanf("%d", &b);
	puts("\nEnter text for encryption in Affine cipher:\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = ((((a * input[i]) + b) - 'a') % 26) + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = ((((a * input[i]) + b) - 'A') % 26) + 'A';
		}
	}
	puts("\nEncrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void affineDecrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	int a, b;
	printf("\nEnter value of 'a' (Must be co-prime with 26): ");
	scanf("%d", &a);
	printf("Enter value of 'b': ");
	scanf("%d", &b);
	puts("Enter text for Decryption in Affine cipher:\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = ((((moduloMultiInverse(a)) * (input[i] - b)) - 'a') % 26) + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = ((((moduloMultiInverse(a)) * (input[i] - b)) - 'A') % 26) + 'A';
		}
	}
	puts("\nDecrypted text:\n");
	fputs(input, stdout);
	free(input);
}
int moduloMultiInverse(int a) {
	a = a % 26;
	for (int inverse = 1; inverse < 26; inverse++) {
		if ((a * inverse) % 26 == 1) {
			return inverse;
		}
	}
}
void vigenereEncrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	char* key = (char*)malloc(sizeof(char) * 2001);
	char*newKey = (char*)malloc(sizeof(char) * 2001);
	puts("\nThis is a type of poly-alphabetic substitution cipher which was first described by Giovan Battista Bellaso");
	puts("in 1553. This cipher utilizes a table which has the alphabet written out 26 times in different rows with each");
	puts("alphabet being shifted cyclically to the left i.e 26 possible Caesar shifts. For each alphabet to be encrypted,");
	puts("the cipher uses an alphabet from the table my matching the original input with the key. This cipher wasn't");
	puts("broken until 1863 by Freidrich Kasiski. This earned it the desciption of 'le chiffre indechiffrable'.");
	puts("This cipher was misattributed to Blaise de Vigenere in the 19th century and so acquired its current name");
	fputs("\nEnter the key (no spaces to be entered & text in lower case): ", stdout);
	getchar();
	fgets(key, 2000, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets
	
	puts("\nEnter text for encryption in Vigenere cipher (no spaces to be entered & text in lower case):\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	int i, j;
	for (i = 0, j = 0; i < strlen(input); i++) {
		if (j < strlen(key)) {
			newKey[i] = key[j];
			j++;
		}
		else {
			j = 0;
			newKey[i] = key[j];
			j++;
		}
	}
	newKey[i] = '\0';
	free(key);
	for (int i = 0; i < strlen(input); i++) {
		input[i] = (((input[i] - 'a') + (newKey[i] - 'a')) % 26) + 'a';
	}
	puts("\nEncrypted text:\n");
	fputs(input, stdout);
	free(newKey);
	free(input);
}
void vigenereDecrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	char* key = (char*)malloc(sizeof(char) * 2001);
	char* newKey = (char*)malloc(sizeof(char) * 2001);
	fputs("\nEnter the key (no spaces to be entered & text in lower case): ", stdout);
	getchar();
	fgets(key, 2000, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets

	puts("\nEnter text for decryption in Vigenere cipher (no spaces to be entered & text in lower case):\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	int i, j;
	for (i = 0, j = 0; i < strlen(input); i++) {
		if (j < strlen(key)) {
			newKey[i] = key[j];
			j++;
		}
		else {
			j = 0;
			newKey[i] = key[j];
			j++;
		}
	}
	newKey[i] = '\0';
	free(key);
	for (int i = 0; i < strlen(input); i++) {
		input[i] = (((input[i] - 'a') - (newKey[i] - 'a') + 26) % 26) + 'a';
	}
	puts("\nDecrypted text:\n");
	fputs(input, stdout);
	free(newKey);
	free(input);
}