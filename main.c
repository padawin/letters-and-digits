#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char play();
void startSuperEasy(int nbTurns, int currentTurn);
void startEasy(int nbTurns, int currentTurn);
void startHard(int nbTurns, int currentTurn);
void startSuperHard(int nbTurns, int currentTurn);

char readDigit(const char *prompt);
char readLetter(const char *prompt);
char readChar();
void readString(char* str);
void init();
char generateLetter(char min, char max);

char readDigit(const char *prompt) {
	char digit;
	do {
		printf("%s ", prompt);
		digit = readChar();
	} while (digit < '0' || digit > '9');

	return digit - '0';
}

char readLetter(const char *prompt) {
	char letter;
	do {
		printf("%s ", prompt);
		letter = readChar();
		if (letter >= 'a' && letter <= 'z') {
			letter = toupper(letter);
		}
	} while (letter < 'A' || letter > 'Z');

	return letter;
}

char readChar() {
	char ret;
	size_t sizeChoice = 1;
	char* in = malloc(sizeof(char) * sizeChoice);
	getline(&in, &sizeChoice, stdin);
	ret = in[0];
	free(in);
	return ret;
}

void readString(char str[3]) {
	size_t sizeChoice = 3;
	char* in = malloc(sizeof(char) * sizeChoice);
	getline(&in, &sizeChoice, stdin);
	strncpy(str, in, 3);
	free(in);
}

int main() {
	while (play()) {
		char restart = readLetter("Restart (y/n)?");
		if (restart != 'Y') {
			break;
		}
	}

	return 0;
}

char play() {
	int level, nbTurns;
	// ask for difficulty level:
	// - 0 => letter to digit or digit to letter
	// - 1 => letter addition
	// - 2 => letter subtraction A - B with A > B
	// - 3 => letter subtraction any letter
	printf("Choose a level of difficulty:\n");
	printf("0 => letter to digit or digit to letter\n");
	printf("1 => letter addition\n");
	printf("2 => letter subtraction A - B with A > B\n");
	printf("3 => letter subtraction any letter\n");

	do {
		level = readDigit("Level:");
	} while (level < 0 || level > 3);

	nbTurns = readDigit("How many turns (0 for infinite)?");

	switch (level) {
		case 0:
			startSuperEasy(nbTurns, 1);
			break;
		case 1:
			startEasy(nbTurns, 1);
			break;
		case 2:
			startHard(nbTurns, 1);
			break;
		case 3:
			startSuperHard(nbTurns, 1);
			break;
		default:
			return 0;
			break;
	}

	return 1;
}

void init() {
	time_t t;
	srand((unsigned) time(&t));
}

char generateLetter(char min, char max) {
	return min + rand() % (max + 1 - min);
}

void startSuperEasy(int nbTurns, int currentTurn) {
	init();
	char letter = generateLetter('A', 'Z');
	char determineLetter = rand() % 2;
	if (determineLetter) {
		printf("Which letter is %d?", letter - 'A' + 1);
		char choice = readLetter("");
		if (choice == letter) {
			printf("Congratulations!\n");
		}
		else {
			printf("No! %d is %c.\n", letter - 'A' + 1, letter);
		}
	}
	else {
		printf("Which value is %c? ", letter);
		char choice[3];
		readString(choice);
		if ('A' - 1 + atoi(choice) == letter) {
			printf("Congratulations!\n");
		}
		else {
			printf("No! %c is %d.\n", letter, letter - 'A' + 1);
		}
	}

	if (currentTurn != nbTurns) {
		startSuperEasy(nbTurns, ++currentTurn);
	}
}

void startEasy(int nbTurns, int currentTurn) {
	init();

}

void startHard(int nbTurns, int currentTurn) {
	init();

}

void startSuperHard(int nbTurns, int currentTurn) {
	init();

}
