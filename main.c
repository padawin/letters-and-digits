#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char play();
void startSuperEasy();
void startEasy();
void startHard();
void startSuperHard();

char readChar();
void init();

char readChar() {
	char ret;
	size_t sizeChoice = 1;
	char* in = malloc(sizeof(char) * sizeChoice);
	getline(&in, &sizeChoice, stdin);
	ret = in[0];
	free(in);
	return ret;
}

int main() {
	while (play()) {
		printf("Restart (y/n)? ");
		char restart = readChar();
		if (restart != 'y') {
			break;
		}
	}

	return 0;
}

char play() {
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

	int level;
	do {
		printf("Level: ");
		level = readChar() - '0';
	} while (level < 0 || level > 3);

	switch (level) {
		case 0:
			startSuperEasy();
			break;
		case 1:
			startEasy();
			break;
		case 2:
			startHard();
			break;
		case 3:
			startSuperHard();
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

void startSuperEasy() {
	init();
}

void startEasy() {
	init();

}

void startHard() {
	init();

}

void startSuperHard() {
	init();

}
