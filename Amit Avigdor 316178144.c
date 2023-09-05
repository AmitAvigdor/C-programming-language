//Amit Avigdor עמית אביגדור 316178144
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_options();
void menu(int);
void diamond();
void lower_diamond(int, int);
void upper_diamond(int, int);
void stanga();
void SubsetStangaGoals(int, int, int, int, int[], int);
int getUserInput1();
int getUserInput2();
void printStanga(int[], int, int);

void main() {
	print_options();
	menu(3);
}

void print_options() { //printing menu options
	printf("Menu\n");
	printf("1. Display menu\n");
	printf("2. Diamond\n");
	printf("3. Stanga\n");
	printf("4. Knight\n");
	printf("5. Exit\n");
}

void menu(int count) { //menu
	printf("Enter your choice:\n");
	int input;
	scanf("%d", &input);
	if (input < 1 || input > 5) { //wrong input
		count--;
		if (count == 0) { //stop the program
			printf("no more tries\n");
			printf("Bye Bye!!!");
			return;
		}
		printf("Wrong input you have %d tries left\n", count); //tries left
		return menu(count);

	}
	if (input == 1) { //display menu
		print_options();
		return menu(count);
	}
	if (input == 2) { //show diamond
		diamond();
		return menu(count);

	}
	if (input == 3) { //show stanga
		stanga();
		return menu(count);

	}
	/*if (input == 4) {
		knight();

	}*/
	if (input == 5) { //end program
		printf("Bye Bye!!!");
		return;
	}
}

void diamond() {
	int dInput;
	printf("Enter the size of the diamond(2-9):\n");
	scanf("%d", &dInput);
	if (dInput < 2 || dInput > 9) { //wrong input
		diamond();
	}
	else {
		upper_diamond(dInput, dInput);
		lower_diamond(dInput, dInput);
	}

}
void print_numbers(int number) { // print diamond
	if (number < 1) {
		return;
	}
	printf("%d", number);
	print_numbers(number - 1);
	if (number == 1) {
		return;
	}
	printf("%d", number);
}

void print_spaces(int space) { //print spaces
	if (space == 0) { //stop codition
		return;
	}
	printf(" ");
	print_spaces(space - 1); //recursion call

}

void upper_diamond(int n, int k) { //build upper diamond
	if (n == 1) { //stop codition
		return;
	}
	print_spaces(n - 1);
	print_numbers(k - n + 1);
	printf("\n");
	upper_diamond(n - 1, k); //recursion call
}

void lower_diamond(int n, int k) { //build lower diamond
	if (n == 0) { //stop codition
		return;
	}
	print_numbers(n);
	printf("\n");
	if (n == 1) {
		return;
	}
	print_spaces(k - n + 1);
	lower_diamond(n - 1, k); //recursion call

}
void stanga() {
	int firstStangaInput, secondStangaInput;
	int arr[512];
	firstStangaInput = getUserInput1(); //get first input
	secondStangaInput = getUserInput2(); //get second input
	SubsetStangaGoals(firstStangaInput, secondStangaInput, 0, 0, arr, 0);
}
int getUserInput1() { //get first input
	int user;
	printf("Enter the result of the 1st team(0-15): \n");
	scanf("%d", &user);
	if (user < 0 || user > 15) //out of range
		 return getUserInput1();
	return user;
}

int getUserInput2() { //get second input
	int user;
	printf("Enter the result of the 2nd team(0-15): \n");
	scanf("%d", &user);
	if (user < 0 || user > 15) //out of range
		return getUserInput2();
	return user;
}

void printStanga(int str[], int count, int temp) { //print stanga goals
	if (count < temp) {
		printf("\n");
		return;
	}
	//format of printing
	printf("%d", str[temp]);
	printf(":");
	printf("%d", str[temp + 1]);
	printf(" ");
	printStanga(str, count, temp + 2); //print with recursion

}
void SubsetStangaGoals(int s1, int s2, int r1, int r2, int str[], int count) {
	str[count] = r1; //insert first team goal
	str[count + 1] = r2; //insert second team goal

	if (s1 == 0 && s2 == 0) { //stop condition
		printStanga(str, count, 0);
		return;
	}
	if (s1 < 0 || s2 < 0) {
		return;
	}

	if (s1 > 0) { //get 1 point goal
		SubsetStangaGoals(s1 - 1, s2, r1 + 1, r2, str, count + 2);

	}
	if (s1 > 1) { //get 2 points goal
		SubsetStangaGoals(s1 - 2, s2, r1 + 2, r2, str, count + 2);

	}
	if (s2 > 0) { //get 1 point goal
		SubsetStangaGoals(s1, s2 - 1, r1, r2 + 1, str, count + 2);

	}
	if (s2 > 1) { //get 2 points goal
		SubsetStangaGoals(s1, s2 - 2, r1, r2 + 2, str, count + 2);

	}

}