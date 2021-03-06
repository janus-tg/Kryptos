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
void vigenereEncrypt(); //function to encrypt in Vigenere cipher
void vigenereDecrypt(); //function to decrypt in Vigenere cipher
void baconEncrypt(); //function to encrypt in Bacon's cipher
void baconDecrypt(); //function to decrypt in Bacon's cipher
void playfairEncrypt(); //function to encrypt in Playfair's cipher
void polybius(char* key, char** table);
void searchDelete(char* alphabet, char keyLetter);
void playfairDecrypt(); //function to decrypt in Playfair's cipher
void bifidEncrypt(); //function to encrypt in Bifid cipher
void bifidDecrypt(); //function to decrypt in Bifid cipher
void adfgxEncrypt(); //function to encrypt in ADFGX cipher
void mixedPolybius(char** table, char* grid);
void sort(char** newTable, int row, int col); //function to use bubble sort the column using the first row
void adfgxDecrypt(); //function to decrypt in ADFGX cipher
void space(char* input); //function to remove spaces
void unsort(char** table, char* key, int row, int col); //function to bring the matrix in order according to the key
void hillEncrypt(); //function to encrypt in Hill's Cipher
void hillDecrypt(); //function to decrypt in Hill's Cipher

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
	puts("\n1. Atbash cipher (circa 500 B.C.E)");
	puts("2. Scytale cipher (circa 440 B.C.E)");
	puts("3. Caesar shift  (circa 60 B.C.E)");
	puts("4. Affine cipher");
	puts("5. Vigenere cipher (circa 1500 C.E)");
	puts("6. Bacon cipher (1605 C.E)");
	puts("7. Playfair cipher  (1854 C.E)");
	puts("8. Bifid cipher (circa 1900 C.E)");
	puts("9. ADFGX cipher (circa 1917 C.E)");
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
	else if (input == 6) {
		baconEncrypt();
	}
	else if (input == 7) {
		playfairEncrypt();
	}
	else if (input == 8) {
		bifidEncrypt();
	}
	else if (input == 9) {
		adfgxEncrypt();
	}
	else if (input == 10) {
		hillEncrypt();
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
	puts("2. Scytale cipher (circa 440 B.C.E)");
	puts("3. Caesar shift  (circa 60 B.C.E)");
	puts("4. Affine cipher");
	puts("5. Vigenere cipher (circa 1500 C.E)");
	puts("6. Bacon cipher (1605 C.E)");
	puts("7. Playfair cipher  (1854 C.E)");
	puts("8. Bifid cipher (circa 1900 C.E)");
	puts("9. ADFGX cipher (circa 1917 C.E)");
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
	else if (input == 6) {
		baconDecrypt();
	}
	else if (input == 7) {
		playfairDecrypt();
	}
	else if (input == 8) {
		bifidDecrypt();
	}
	else if (input == 9) {
		adfgxDecrypt();
	}
	else if (input == 10) {
		hillDecrypt();
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
	puts("Enter text for encryption in Caesar shift:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {//loop to shift the alphabets according to user input
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = (input[i] + shift - 'a') % 26 + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {//case if upper case alphabets entered
			input[i] = (input[i] + shift - 'a') % 26 + 'A';
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
	puts("\nEnter text for decryption in Caesar shift:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = (input[i] + (26 - shift) - 'a') % 26 + 'a'; //using the fact that decryption will be 26 - shift
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = (input[i] + (26 - shift) - 'a') % 26 + 'a'; //case for uppercase letters
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

	char** output = (char**)calloc(strlen(input) + 2, sizeof(char*));
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
		for (row = 0; row < strlen(input) && k < strlen(input); row++) {//converting the input to a 2d matrix
			for (col = 0; col < diameter && k < strlen(input); col++) {
				output[row][col] = input[k];
				k++;
			}
		}
		puts("\nEncrypted text:\n");
		for (int i = 0; i < diameter; i++) {//reading the 2d matrix top to bottom then left to right
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
		for (row = 0; row < strlen(input) && k < strlen(input); row++) {//creating a 2d matrix to store the input
			for (col = 0; col <= diameter && k < strlen(input); col++) {
				output[row][col] = input[k];
				k++;
			}
		}
		puts("\nDecrypted text:\n");
		for (int i = 0; i <= diameter; i++) {//reading the matrix top to bottom then left to right
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
		}//alphabets replaced. a becomes z, b becomes y and so on
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
		}//converting to ax + b form and extracting the alphabet and storing it in the array
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
		}//x is a^-1 * b so modulo multi inverse used
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
	char* newKey = (char*)malloc(sizeof(char) * 2001);
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
void baconEncrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nThis was devised by Francis Bacon in 1605. This cipher is an example of steganography where a message is");
	puts("hidden in the presentation of text, rather than its content. This is done by replacing each alphabet of");
	puts("the text with a group of 5 letters conisting of 'a' and 'b'.");
	puts("\nEnter text for encryption in Bacon cipher (uppercase alphabets only):\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	char** output = (char**)calloc(strlen(input), sizeof(char*));
	for (int i = 0; i < strlen(input); i++) {
		output[i] = (char*)calloc(7, sizeof(char));
	}//simple combimation of a and b denotes each alphabet. match and store in the array
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 'A') {
			strncpy(output[i], "aaaaa ", 7);
		}
		else if (input[i] == 'B') {
			strncpy(output[i], "aaaab ", 7);
		}
		else if (input[i] == 'C') {
			strncpy(output[i], "aaaba ", 7);
		}
		else if (input[i] == 'D') {
			strncpy(output[i], "aaabb ", 7);
		}
		else if (input[i] == 'E') {
			strncpy(output[i], "aabaa ", 7);
		}
		else if (input[i] == 'F') {
			strncpy(output[i], "aabab ", 7);
		}
		else if (input[i] == 'G') {
			strncpy(output[i], "aabba ", 7);
		}
		else if (input[i] == 'H') {
			strncpy(output[i], "aabbb ", 7);
		}
		else if (input[i] == 'I') {
			strncpy(output[i], "abaaa ", 7);
		}
		else if (input[i] == 'J') {
			strncpy(output[i], "abaab ", 7);
		}
		else if (input[i] == 'K') {
			strncpy(output[i], "ababa ", 7);
		}
		else if (input[i] == 'L') {
			strncpy(output[i], "ababb ", 7);
		}
		else if (input[i] == 'M') {
			strncpy(output[i], "abbaa ", 7);
		}
		else if (input[i] == 'N') {
			strncpy(output[i], "abbab ", 7);
		}
		else if (input[i] == 'O') {
			strncpy(output[i], "abbba ", 7);
		}
		else if (input[i] == 'P') {
			strncpy(output[i], "abbbb ", 7);
		}
		else if (input[i] == 'Q') {
			strncpy(output[i], "baaaa ", 7);
		}
		else if (input[i] == 'R') {
			strncpy(output[i], "baaab ", 7);
		}
		else if (input[i] == 'S') {
			strncpy(output[i], "baaba ", 7);
		}
		else if (input[i] == 'T') {
			strncpy(output[i], "baabb ", 7);
		}
		else if (input[i] == 'U') {
			strncpy(output[i], "babaa ", 7);
		}
		else if (input[i] == 'V') {
			strncpy(output[i], "babab ", 7);
		}
		else if (input[i] == 'W') {
			strncpy(output[i], "babab ", 7);
		}
		else if (input[i] == 'X') {
			strncpy(output[i], "babbb ", 7);
		}
		else if (input[i] == 'Y') {
			strncpy(output[i], "bbaaa ", 7);
		}
		else if (input[i] == 'Z') {
			strncpy(output[i], "bbaab ", 7);
		}
		else {
			continue;
		}
	}
	puts("\nEncrypted text:\n");
	for (int i = 0; i < strlen(input); i++) {
		fputs(output[i], stdout);
	}

	for (int i = 0; i < strlen(input); i++) {
		free(output[i]);
	}
	free(input);
	free(output);
}
void baconDecrypt() {
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("Enter text for Decryption in Bacon cipher:\n");
	getchar();
	fgets(input, 2000, stdin);
	strtok(input, "\n"); //this to remove the \n from using fgets
	//use string delimitter strtok
	puts("\nDecrypted text:\n");
	char* token = strtok(input, " ");
	while (token != NULL) {
		if (strncmp(token, "aaaaa", 5) == 0) {
			printf("A");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aaaab", 5) == 0) {
			printf("B");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aaaba", 5) == 0) {
			printf("C");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aaabb", 5) == 0) {
			printf("D");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aabaa", 5) == 0) {
			printf("E");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aabab", 5) == 0) {
			printf("F");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aabba", 5) == 0) {
			printf("G");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "aabbb", 5) == 0) {
			printf("H");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abaaa", 5) == 0) {
			printf("I");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abaab", 5) == 0) {
			printf("J");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "ababa", 5) == 0) {
			printf("K");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "ababb", 5) == 0) {
			printf("L");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abbaa", 5) == 0) {
			printf("M");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abbab", 5) == 0) {
			printf("N");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abbba", 5) == 0) {
			printf("O");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "abbbb", 5) == 0) {
			printf("P");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "baaaa", 5) == 0) {
			printf("Q");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "baaab", 5) == 0) {
			printf("R");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "baaba", 5) == 0) {
			printf("S");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "baabb", 5) == 0) {
			printf("T");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "babaa", 5) == 0) {
			printf("U");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "babab", 5) == 0) {
			printf("V");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "babba", 5) == 0) {
			printf("W");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "babbb", 5) == 0) {
			printf("X");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "bbaaa", 5) == 0) {
			printf("Y");
			token = strtok(NULL, " ");
		}
		else if (strncmp(token, "bbaab", 5) == 0) {
			printf("Z");
			token = strtok(NULL, " ");
		}
		else {
			puts("Wrong input!");
			return;
		}
	}
	free(input);
}
void playfairEncrypt() {
	char* key = (char*)malloc(sizeof(char) * 1500);
	char** table = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		table[i] = (char*)malloc(sizeof(char) * 5);
	}
	puts("\nThis encryption scheme was devised by Charles Wheatstone in 1854 but it is named after Lord Playfair for promoting");
	puts("its usage. This cipher encrypts a pair of letters or digrams and is thus harder to decode using frequency analysis");
	puts("than a substitution cipher. This cipher was extensively used in the second Boer war and World War 1 due to  ");
	puts("the ease with which messages could be encoded");
	fputs("\nEnter a key (no spaces should be entered, no repeated alphabet and lowercase only): ", stdout);
	getchar();
	fgets(key, 1499, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets
	polybius(key, table);
	free(key); //maybe
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nEnter text for encryption in Playfair cipher:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n");
	int inputLength = strlen(input);
	if (inputLength % 2 != 0) {
		input[inputLength] = 'z';
		input[inputLength + 1] = '\0';
	}
	int inputCounter, row, col, r1, c1, r2, c2;
	char l1, l2;
	for (inputCounter = 0; inputCounter < strlen(input) - 1; inputCounter += 2) {
		l1 = input[inputCounter]; //l1 and l2 denote the bigrams
		l2 = input[inputCounter + 1];
		for (row = 0; row < 5; row++) {
			for (col = 0; col < 5; col++) {
				if (table[row][col] == l1) {//storing the row and column where the bigram was matched with the table
					r1 = row;
					c1 = col;
				}if (table[row][col] == l2) {
					r2 = row;
					c2 = col;
				}
			}
		}
		if (c1 == c2) {
			if (r1 != 4 && r2 != 4) {
				input[inputCounter] = table[r1 + 1][c1];
				input[inputCounter + 1] = table[r2 + 1][c1];
			}
			else {//boundary case when we are at the edge of table
				if (r1 == 4 && r2 != 4) {
					input[inputCounter] = table[0][c1];
					input[inputCounter + 1] = table[r2 + 1][c1];
				}if (r2 == 4 && r1 != 4) {
					input[inputCounter] = table[r1 + 1][c1];
					input[inputCounter + 1] = table[0][c1];
				}
			}
		}
		else if (r1 == r2) {
			if (c1 != 4 && c2 != 4) {
				input[inputCounter] = table[r1][c1 + 1];
				input[inputCounter + 1] = table[r2][c2 + 1];
			}
			else {//boundary case when we are at the edge of table
				if (c1 == 4 && c2 != 4) {
					input[inputCounter] = table[r1][0];
					input[inputCounter + 1] = table[r2][c2 + 1];
				}if (c2 == 4 && c1 != 4) {
					input[inputCounter] = table[r1][c1 + 1];
					input[inputCounter + 1] = table[r2][0];
				}
			}
		}
		else {
			input[inputCounter] = table[r1][c2];
			input[inputCounter + 1] = table[r2][c1];
		}
	}
	for (int i = 0; i < 5; i++) {
		free(table[i]);
	}
	free(table);
	puts("\nEncrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void polybius(char* key, char** table) {
	char* alphabet = (char*)malloc(sizeof(char) * 26);
	char letter = 'a';
	char keyLetter;
	int i;
	for (i = 0; i < 25; i++) {// only 25 alphabet table. so, j is excluded
		if (letter != 'j') {
			alphabet[i] = letter;
			letter++;
		}
		else {
			letter++;
			i--;
		}
	}
	alphabet[i] = '\0';
	//implement a search and delete feature here
	for (int k = 0; k < strlen(key); k++) {
		keyLetter = key[k];
		searchDelete(alphabet, keyLetter);
	}

	int a = 0, b = 0, j = 0;
	for (a = 0; a < 5; a++) {
		for (j = 0; j < 5; j++) {
			if (((5 * a) + j) < strlen(key)) {
				table[a][j] = key[((5 * a) + j)];
			}
			else {
				if (alphabet[b] != NULL) {
					table[a][j] = alphabet[b];
					b++;
				}
			}
		}
	}
	free(alphabet);
}
void searchDelete(char* alphabet, char keyLetter) {
	int i, j; // function to search and delete after matching
	for (i = 0, j = 0; i < strlen(alphabet); i++) {
		if (alphabet[i] != keyLetter) {
			alphabet[j++] = alphabet[i];
		}
	}
	alphabet[j] = '\0';
}
void playfairDecrypt() {
	char* key = (char*)malloc(sizeof(char) * 1500);
	char** table = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		table[i] = (char*)malloc(sizeof(char) * 5);
	}
	fputs("\nEnter a key (no spaces should be entered, no repeated alphabet and lowercase only): ", stdout);
	getchar();
	fgets(key, 1499, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets
	polybius(key, table);
	free(key);
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nEnter text for decryption in Playfair cipher:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n");
	int inputCounter, row, col, r1, c1, r2, c2;
	char l1, l2;
	for (inputCounter = 0; inputCounter < strlen(input) - 1; inputCounter += 2) {
		l1 = input[inputCounter];
		l2 = input[inputCounter + 1];
		for (row = 0; row < 5; row++) {
			for (col = 0; col < 5; col++) {
				if (table[row][col] == l1) {
					r1 = row;
					c1 = col;
				}if (table[row][col] == l2) {
					r2 = row;
					c2 = col;
				}
			}
		}
		if (c1 == c2) {
			if (r1 != 0 && r2 != 0) {
				input[inputCounter] = table[r1 - 1][c1];
				input[inputCounter + 1] = table[r2 - 1][c2];
			}
			else {
				if (r1 == 0 && r2 != 0) {
					input[inputCounter] = table[4][c1];
					input[inputCounter + 1] = table[r2 - 1][c1];
				}if (r2 == 0 && r1 != 0) {
					input[inputCounter] = table[r1 - 1][c1];
					input[inputCounter + 1] = table[4][c1];
				}
			}
		}
		else if (r1 == r2) {
			if (c1 != 0 && c2 != 0) {
				input[inputCounter] = table[r1][c1 - 1];
				input[inputCounter + 1] = table[r2][c2 - 1];
			}
			else {
				if (c1 == 0 && c2 != 0) {
					input[inputCounter] = table[r1][4];
					input[inputCounter + 1] = table[r2][c2 - 1];
				}if (c2 == 0 && c1 != 0) {
					input[inputCounter] = table[r1][c1 - 1];
					input[inputCounter + 1] = table[r2][4];
				}
			}
		}
		else {
			input[inputCounter] = table[r1][c2];
			input[inputCounter + 1] = table[r2][c1];
		}
	}
	for (int i = 0; i < 5; i++) {
		free(table[i]);
	}
	free(table);
	puts("\nDecrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void bifidEncrypt() {
	char* key = (char*)malloc(sizeof(char) * 1500);
	char** table = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		table[i] = (char*)malloc(sizeof(char) * 5);
	}
	puts("\nThe Bifid cipher was introduced by Felix Delastelle in 1901. It utilizes a Polybius square with");
	puts("transposition. The input's coordinates are written in a vertical manner but they are read out horizontally");
	puts("and thus encryption is achieved. In this rendition of the cipher a code block of input length is going to be taken.");
	fputs("\nEnter a key (no spaces should be entered, no repeated alphabet and lowercase only): ", stdout);
	getchar();
	fgets(key, 1499, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets
	polybius(key, table);
	free(key); //maybe
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nEnter text for encryption in Bifid cipher:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n");
	int* coordinate = (int*)malloc(sizeof(int) * 2 * (strlen(input) + 1));
	int* column = (int*)malloc(sizeof(int) * (strlen(input) + 2));
	int inputCounter, row, col, i = 0, j = 0, k = 0, r1, c1;
	char letter;
	for (inputCounter = 0; inputCounter < strlen(input); inputCounter++) {
		letter = input[inputCounter];
		for (row = 0; row < 5; row++) {
			for (col = 0; col < 5; col++) {
				if (letter == table[row][col]) {
					coordinate[i] = row;// coordinate array is storing all the rows first
					column[i] = col;// column array is storing all the columns first
					i++;
				}
			}
		}
	}
	for (j = 0, k = i; j <= i; j++, k++) {
		coordinate[k] = column[j];//merging all the column numbers to come after all the row numbers
	}
	free(column);
	for (int a = 0, b = 0; b < j - 1; a += 2, b++) {
		r1 = coordinate[a];
		c1 = coordinate[a + 1];
		input[b] = table[r1][c1];//reading from merged coordinate array
	}
	free(coordinate);
	for (int i = 0; i < 5; i++) {
		free(table[i]);
	}
	free(table);
	puts("\nEncrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void bifidDecrypt() {
	char* key = (char*)malloc(sizeof(char) * 1500);
	char** table = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		table[i] = (char*)malloc(sizeof(char) * 5);
	}
	fputs("\nEnter a key (no spaces should be entered, no repeated alphabet and lowercase only): ", stdout);
	getchar();
	fgets(key, 1499, stdin);
	strtok(key, "\n"); //this to remove the \n from using fgets
	polybius(key, table);
	free(key); //maybe
	char* input = (char*)malloc(sizeof(char) * 2001);
	puts("\nEnter text for decryption in Bifid cipher:\n");
	fgets(input, 2000, stdin);
	strtok(input, "\n");
	int* coordinate = (int*)malloc(sizeof(int) * 2 * (strlen(input) + 1));
	int* column = (int*)malloc(sizeof(int) * (strlen(input) + 2));
	int inputCounter, row, col, i = 0, j = 0, k = 0, r1, c1;
	char letter;
	for (inputCounter = 0; inputCounter < strlen(input); inputCounter++) {
		letter = input[inputCounter];
		for (row = 0; row < 5; row++) {
			for (col = 0; col < 5; col++) {
				if (letter == table[row][col]) {
					coordinate[i] = row;
					column[i] = col;
					i++;
				}
			}
		}
	}
	for (j = 0, k = i; j <= i; j++, k++) {
		coordinate[k] = column[j];
	}
	free(column);
	for (int a = 0, b = 0; b < j - 1; a += 2, b++) {
		r1 = coordinate[a];
		c1 = coordinate[a + 1];
		input[b] = table[r1][c1];
	}
	free(coordinate);
	for (int i = 0; i < 5; i++) {
		free(table[i]);
	}
	free(table);
	puts("\nDecrypted text:\n");
	fputs(input, stdout);
	free(input);
}
void adfgxEncrypt() {
	char* grid = (char*)malloc(sizeof(char) * 150);
	char** table = (char**)malloc(sizeof(char*) * 6);
	for (int i = 0; i < 6; i++) {
		table[i] = (char*)malloc(sizeof(char) * 6);
	}
	puts("\nThe ADFGX cipher was used by the German Army during World War 1 on the western front. This cipher was invented");
	puts("by Lieutenant Fritz Nebel. This cipher is an example of fractionating transposition cipher which combines a modified");
	puts("Polybius square with a single columnar transposition. This utilizes the alphabets 'A', 'D', 'F', 'G' and 'X' as they");
	puts("were are very distinct in Morse code and this reduces chances of error");
	puts("\nEnter the polybius square (no spaces should be entered, no repeated alphabet and lowercase only):\n");
	getchar();
	fgets(grid, 150, stdin);
	strtok(grid, "\n"); //this to remove the \n from using fgets
	mixedPolybius(table, grid); //function creates grid with adfgx using given input of grid
	free(grid);
	char* input = (char*)malloc(sizeof(char) * 2000);
	char* fractionated = (char*)malloc(sizeof(char) * 4000);
	puts("\nEnter text for encryption in ADFGX cipher:\n");
	fgets(input, 1999, stdin);
	strtok(input, "\n");
	int counter = 0;
	for (int i = 0; i < strlen(input); i++) {//loop to match each input alphabet with the table and write the fractionated
		//text in terms of adfgx in the fractionated array
		char letter = input[i];
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (letter == table[j][k]) {
					fractionated[counter] = table[j][0];
					fractionated[counter + 1] = table[0][k];
					counter += 2;
				}
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		free(table[i]);
	}
	free(table);
	free(input);
	fractionated[counter] = '\0';
	char* key = (char*)malloc(sizeof(char) * 150);
	fputs("\nEnter a transposition key (one word, no repeated alphabet and lowercase only): ", stdout);
	fgets(key, 149, stdin);
	strtok(key, "\n");
	int row;
	if (strlen(fractionated) % strlen(key) != 0) {//cases to calculate number of rows of table
		row = (strlen(fractionated) / strlen(key)) + 1;
	}
	else {
		row = strlen(fractionated) / strlen(key);
	}
	char** newTable = (char**)calloc(row + 1, sizeof(char*));
	for (int i = 0; i < row + 1; i++) {
		newTable[i] = (char*)calloc(strlen(key), sizeof(char));
	}
	puts("");
	for (int i = 0, k = 0, l = 0; i < row + 1 && fractionated[k] != '\0'; i++) {
		for (int j = 0; j < strlen(key) && fractionated[k] != '\0'; j++) {
			if (i == 0) {//filling the first row with the key
				newTable[i][j] = key[l];
				l++;
			}
			else if (fractionated[k] == ' ') {//if space is present then skip it
				j--;
				k++;
				continue;
			}
			else {//filling the table with the text from fractionated(in terms of adfgx)
				newTable[i][j] = fractionated[k];
				k++;
			}
		}
	}
	sort(newTable, row, strlen(key));//function to sort the columns alphabetically according to first row of the table ie the key
	free(fractionated);
	puts("Encrypted text:\n");
	for (int i = 0; i < strlen(key); i++) {
		for (int j = 0; j < row + 1; j++) {
			if (j != 0 && newTable[i][j] != ' ') {
				printf("%c", newTable[j][i]);
			}
		}
	}
	free(key);
	for (int i = 0; i < row + 1; i++) {
		free(newTable[i]);
	}
	free(newTable);
}
void sort(char** newTable, int row, int col) {
	//using a bubble sort algorithm
	int top, i;
	for (top = col - 1; top > 0; top--) {
		for (i = 0; i < top; i++) {
			if (newTable[0][i] > newTable[0][i + 1]) {
				for (int j = 0; j < row + 1; j++) {
					char temp = newTable[j][i];
					newTable[j][i] = newTable[j][i + 1];
					newTable[j][i + 1] = temp;
				}
			}
		}
	}
}
void mixedPolybius(char** table, char* grid) {//function to create adfgx table
	for (int i = 0, k = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == 0 && j == 0) {
				table[i][j] = ' ';
			}
			else if (i == 0 && j == 1) {
				table[i][j] = 'A';
			}
			else if (i == 0 && j == 2) {
				table[i][j] = 'D';
			}
			else if (i == 0 && j == 3) {
				table[i][j] = 'F';
			}
			else if (i == 0 && j == 4) {
				table[i][j] = 'G';
			}
			else if (i == 0 && j == 5) {
				table[i][j] = 'X';
			}
			else if (i == 1 && j == 0) {
				table[i][j] = 'A';
			}
			else if (i == 2 && j == 0) {
				table[i][j] = 'D';
			}
			else if (i == 3 && j == 0) {
				table[i][j] = 'F';
			}
			else if (i == 4 && j == 0) {
				table[i][j] = 'G';
			}
			else if (i == 5 && j == 0) {
				table[i][j] = 'X';
			}
			else {
				table[i][j] = grid[k];
				k++;
			}
		}
	}
}
void adfgxDecrypt() {
	char* input = (char*)malloc(sizeof(char) * 4000);
	puts("\nEnter text for decryption:\n");
	getchar();
	fgets(input, 3999, stdin);
	strtok(input, "\n");
	space(input);
	puts(input);
	char* key = (char*)malloc(sizeof(char) * 150);
	fputs("\nEnter a transposition key (one word, no repeated alphabet and lowercase only): ", stdout);
	fgets(key, 149, stdin);
	strtok(key, "\n");
	int row;
	if (strlen(input) % strlen(key) != 0) {
		row = (strlen(input) / strlen(key)) + 1;
	}
	else {
		row = strlen(input) / strlen(key);
	}
	int col = strlen(key);
	char** table = (char**)calloc(sizeof(char*), row + 1);
	for (int i = 0; i < row + 1; i++) {
		table[i] = (char*)calloc(sizeof(char), col);
	}
	for (int i = 0, j = 0, k = 0; j < col; j++, k++) {
		table[0][j] = key[k];
	}
	sort(table, row, col);
	for (int i = 0, k = 0; i < col && input[k] != '\0'; i++) {
		for (int j = 0; j < row + 1 && input[k] != '\0'; j++) {
			if (j == 0) {
				continue;
			}
			else if (input[k] == ' ') {
				j--;
				k++;
				continue;
			}
			else {
				table[j][i] = input[k];
				k++;
			}
		}
	}
	//now, rearrange letters according to key
	unsort(table, key, row, col);
	free(input);
	free(key);
	char* text = (char*)malloc(sizeof(char) * 3000);
	int counter = 0;
	for (int i = 0; i < row + 1; i++) {
		for (int j = 0; j < col; j++) {
			if (i != 0 && table[i][j] != NULL) {
				text[counter] = table[i][j];
				counter++;
			}
		}
	}
	text[counter] = '\0';
	for (int i = 0; i < row + 1; i++) {
		free(table[i]);
	}
	free(table);
	char* grid = (char*)malloc(sizeof(char) * 100);
	char** polybius = (char**)malloc(sizeof(char*) * 6);
	for (int i = 0; i < 6; i++) {
		polybius[i] = (char*)malloc(sizeof(char) * 6);
	}
	puts("\nEnter the polybius square (no spaces should be entered, no repeated alphabet and lowercase only):\n");
	fgets(grid, 150, stdin);
	strtok(grid, "\n"); //this to remove the \n from using fgets
	mixedPolybius(polybius, grid);
	free(grid);
	char* output = (char*)malloc(sizeof(char) * 1500);
	int outputCounter = 0;
	for (int k = 0; k < strlen(text) - 1; k += 2) {
		char row = text[k];
		char col = text[k + 1];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (row == polybius[i][0] && col == polybius[0][j]) {
					output[outputCounter] = polybius[i][j];
					outputCounter++;
				}
			}
		}
	}
	free(text);
	for (int i = 0; i < 6; i++) {
		free(polybius[i]);
	}
	free(polybius);
	output[outputCounter] = '\0';
	puts("\nDecrypted text:\n");
	fputs(output, stdout);
	free(output);
}
void space(char* input) {//function to remove spaces from input string
	int j = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			input[j++] = input[i];
		}
	}
	input[j] = '\0';
}
void unsort(char** table, char* key, int row, int col) {//function to sort the alphabetical columns according to the key
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < col; j++) {
			if (key[i] == table[0][j]) {
				for (int k = 0; k < row + 1; k++) {
					char temp = table[k][i];
					table[k][i] = table[k][j];
					table[k][j] = temp;
				}
			}
		}
	}
}
void hillEncrypt() {
	//creating an array to store all the alphabets from 'A' to 'Z'
	char* alphabetArray = (char*)malloc(sizeof(char) * 27);
	char letter = 'A';
	for (int i = 0; i < 26; i++) {
		alphabetArray[i] = letter;
		letter++;
	}
	alphabetArray[26] = '\0';
	char* charInput = (char*)malloc(sizeof(char) * 2000);
	puts("\nThe Hill cipher was invented by Leslie S. Hill in 1929. It was the first polygraphic cipher which allowed for");
	puts("operation on max 3 symbols at once. This cipher works on the principle of matrix multiplication. The input is");
	puts("converted into a matric which is multiplied by the matrix obtained from the key.");
	fputs("\nEnter text for encryption (only uppercase letters):\n\n", stdout);
	getchar();
	fgets(charInput, 1999, stdin);
	strtok(charInput, "\n"); //remove \n from input array
	for (int i = 0; charInput[i] != '\0'; i++) { //removing spaces from input
		if (charInput[i] == ' ') {
			charInput[i] = charInput[i + 1];
			i++;
		}
	}
	puts("Matrix with key GYBNQKURP taken.");
	int* intInput = (int*)malloc(sizeof(int) * strlen(charInput));
	for (int i = 0; i < strlen(charInput); i++) {
		for (int j = 0; j < strlen(alphabetArray); j++) {
			if (charInput[i] == alphabetArray[j]) {
				intInput[i] = j;
			}
		}
	}
	int** intKey = (int**)malloc(sizeof(int*) * 4);
	for (int i = 0; i < 4; i++) {
		intKey[i] = (int*)malloc(sizeof(int) * 4);
	}
	intKey[0][0] = 6;
	intKey[0][1] = 24;
	intKey[0][2] = 1;
	intKey[1][0] = 13;
	intKey[1][1] = 16;
	intKey[1][2] = 10;
	intKey[2][0] = 20;
	intKey[2][1] = 17;
	intKey[2][2] = 15;
	puts("\nEncrypted text:\n");
	//key * 3 letters = answer % 26 --> search from table ---> print letter
	int counter = 0, loop = 0;
	while (counter < strlen(charInput)) {
		for (int i = 0; i < 3; i++, loop++) {
			int result = 0;
			counter = loop / 3;
			for (int j = 0; j < 3; j++) {
				result += intKey[i][j] * intInput[counter];
				counter++;
			}
			printf("%c", alphabetArray[result % 26]);
		}
	}
	free(alphabetArray);
	free(intInput);
	for (int i = 0; i < 4; i++) {
		free(intKey[i]);
	}
	free(intKey);
	free(charInput);
}
void hillDecrypt() {
	//creating an array to store all the alphabets from 'A' to 'Z'
	char* alphabetArray = (char*)malloc(sizeof(char) * 27);
	char letter = 'A';
	for (int i = 0; i < 26; i++) {
		alphabetArray[i] = letter;
		letter++;
	}
	alphabetArray[26] = '\0';
	char* charInput = (char*)malloc(sizeof(char) * 2000);
	fputs("\nEnter text for decryption (only uppercase letters):\n\n", stdout);
	getchar();
	fgets(charInput, 1999, stdin);
	strtok(charInput, "\n"); //remove \n from input array
	int* intInput = (int*)malloc(sizeof(int) * strlen(charInput));
	for (int i = 0; i < strlen(charInput); i++) {
		for (int j = 0; j < strlen(alphabetArray); j++) {
			if (charInput[i] == alphabetArray[j]) {
				intInput[i] = j;
			}
		}
	}
	int** intKey = (int**)malloc(sizeof(int*) * 4);
	for (int i = 0; i < 4; i++) {
		intKey[i] = (int*)malloc(sizeof(int) * 4);
	}
	puts("Matrix with key GYBNQKURP taken.");
	intKey[0][0] = 8;
	intKey[0][1] = 5;
	intKey[0][2] = 10;
	intKey[1][0] = 21;
	intKey[1][1] = 8;
	intKey[1][2] = 21;
	intKey[2][0] = 21;
	intKey[2][1] = 12;
	intKey[2][2] = 8;
	puts("\nDecrypted text:\n");
	//key * 3 letters = answer % 26 --> search from table ---> print letter
	int counter = 0, loop = 0;
	while (counter < strlen(charInput)) {
		for (int i = 0; i < 3; i++, loop++) {
			int result = 0;
			counter = loop / 3;
			for (int j = 0; j < 3; j++) {
				result += intKey[i][j] * intInput[counter];
				counter++;
			}
			printf("%c", alphabetArray[result % 26]);
		}
	}
	free(alphabetArray);
	free(intInput);
	for (int i = 0; i < 4; i++) {
		free(intKey[i]);
	}
	free(intKey);
	free(charInput);
}