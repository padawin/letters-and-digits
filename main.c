#include <stdio.h>
#include <stdlib.h>

char play();
void startSuperEasy();
void startEasy();
void startHard();
void startSuperHard();

int main() {
	while (play()) {
		printf("Restart (y/n)? ");
		size_t sizeChoice = 1;
		char* restart = malloc(sizeof(char) * sizeChoice);
		getline(&restart, &sizeChoice, stdin);
		free(restart);
		if (restart[0] != 'y') {
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

	size_t sizeChoice = 1;
	char* choice = malloc(sizeof(char) * sizeChoice);
	int level;
	do {
		printf("Level: ");
		getline(&choice, &sizeChoice, stdin);
		level = choice[0] - '0';
	} while (level < 0 || level > 3);

	free(choice);

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

void startSuperEasy() {

}

void startEasy() {

}

void startHard() {

}

void startSuperHard() {

}
