#define _CRT_SECURE_NO_WARNINGS
//עמית אביגדור 
//316178144
#include <stdio.h>
#include <math.h>
void main() {
	//numOfError - num of error times
	//user - user input
	int numOfError, user, input1, i, isPrime, isGermn, isMarsn, tmp, temp, index, tmpMarsn;
	int day, month, year, dateFlag, offSetDate, sign;
	int height, width, j;
	int numOfoHeight, numOfmHeight, numOfiHeight, numOfoWidth, numOfmWidth, numOfiWidth;
	int yearTMP, monthTMP, dayTMP, year2;
	//Menu options
	numOfError = 0;
	while (numOfError < 5) {
		printf("Please choose from the menu:\n");
		printf("0. Exit\n");
		printf("1. Prime time\n");
		printf("2. Calender calculating\n");
		printf("3. Matrix printing\n");
		scanf("%d", &user);
		if (user < 0 || user > 3) {
			numOfError++;
			printf("%d error out of 5, try again,\n", numOfError);
		}
		if (user == 0) {
			numOfError = 5;
			printf("You chose to end the program, bie bie.\n");
		}
		if (user == 1) {
			do {
				printf("Enter a number between 1 and 1000000:\n");
				scanf("%d", &input1); // input user for section 1
			} while (input1 <= 0 || input1 > 1000000);
			printf("         N|P|G|M|\n");
			printf("         u|r|e|a|\n");
			printf("         m|i|r|r|\n");
			printf("         b|m|m|s|\n");
			printf("         r|e|n|n|\n");
			printf("----------+-+-+-+\n");
			for (index = 0; index < 19; index++) {
				temp = (input1 - 9) + index;
				if ((temp > 0) && (temp <= 1000000)) {
					printf("%2d)%7d|", (index - 9), temp);
					// Chack if the input1 is Prime number
					isPrime = 1;
					for (i = 2; i <= temp / 2; i++) {
						if (temp % i == 0) {
							isPrime = 0;
							break;
						}
					}
					printf("%d|", isPrime);

					// Check if the input1 is Germn number
					isGermn = 1;
					tmp = (temp * 2) + 1;
					if (isPrime == 1) {
						for (i = 2; i <= tmp / 2; i++) {
							if (tmp % i == 0) {
								isGermn = 0;
								break;
							}
						}
					}
					else {
						isGermn = 0;
					}
					printf("%d|", isGermn);

					//Chack if the input1 is Mersenne
					isMarsn = 0;
					if (isPrime == 1) {
						tmpMarsn = 1;
						while (tmpMarsn <= (temp + 1)) {
							if (tmpMarsn == (temp + 1)) {
								isMarsn = 1;
								break;
							}
							tmpMarsn = tmpMarsn * 2;
						}

					}

					printf("%d|\n", isMarsn);





				}


			}


		}

		if (user == 2) {
			//Calender calculating 
			dateFlag = 0;
			do {
				printf("Enter day month and year:\n");
				scanf("%d", &day);
				scanf("%d", &month);
				scanf("%d", &year);
				if (year >= 0 && year <= 9999) {
					if (month >= 1 && month <= 12) {
						if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
							if (day <= 31 && day >= 1) {
								dateFlag = 1;
							}
						}
						else if (month == 4 || month == 6 || month == 9 || month == 11) {
							if (day <= 30 && day >= 1) {
								dateFlag = 1;
							}
						}
						else if (month == 2) {
							if (year % 400 == 0) {
								if (day <= 29 && day >= 1) {
									dateFlag = 1;
								}
							}
							else if (year % 100 == 0) {
								if (day <= 28 && day >= 1) {
									dateFlag = 1;
								}
							}
							else if (year % 4 == 0) {
								if (day <= 29 && day >= 1) {
									dateFlag = 1;
								}
							}
							else if (day <= 28 && day >= 1) {
								dateFlag = 1;
							}
						}
					}
				}
			} while (dateFlag == 0);
			// From this point we know that the date is current.
			do {
				printf("Enter a number between -1000000 and 1000000:\n");
				scanf("%d", &offSetDate);
			} while (offSetDate < -1000000 || offSetDate > 1000000);
			if (offSetDate > 0) {
				for (i = 0; i < offSetDate; i++) {
					if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
						if (day < 31) {
							day++;
						}
						else {
							month++;
							day = 1;
						}
					}
					else if (month == 4 || month == 6 || month == 9 || month == 11) {
						if (day < 30) {
							day++;
						}
						else {
							month++;
							day = 1;
						}
					}
					else if (month == 2) {
						if (year % 400 == 0) {
							if (day < 29) {
								day++;
							}
							else {
								month++;
								day = 1;
							}
						}
						else if (year % 100 == 0) {
							if (day < 28) {
								day++;
							}
							else {
								month++;
								day = 1;
							}
						}
						else if (year % 4 == 0) {
							if (day < 29) {
								day++;
							}
							else {
								month++;
								day = 1;
							}
						}
						else if (day < 28) {
							day++;
						}
						else {
							month++;
							day = 1;
						}
					}
					if (month == 13) {
						year++;
						month = 1;
					}


				}
				if (year > 9999) {
					day = 31;
					month = 12;
					year = 9999;
				}
			}
			else {
				for (i = offSetDate; i < 0; i++) {
					if (day == 1) {
						if (month == 1) {
							year--;
							month = 12;
							day = 31;
						}
						else {
							month--;
							if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
								day = 31;
							}
							else if (month == 4 || month == 6 || month == 9 || month == 11) {
								day = 30;
							}
							else if (month == 2) {
								if (year % 400 == 0) {
									day = 29;
								}
								else if (year % 100 == 0) {
									day = 28;
								}
								else if (year % 4 == 0) {
									day = 29;
								}
								else {
									day = 28;
								}
							}
						}
					}
					else {
						day--;
					}
				}
				if (year < 0) {
					day = 1;
					month = 1;
					year = 0;
				}
			}
			printf("The new date is: %02d.%02d.%4d\n", day, month, year);
		}
		//Matrix printing
		if (user == 3) {
			do {
				printf("Please enter the square odd height, range 5-21 :\n");
				scanf("%d", &height);
			} while (height < 5 || height > 21 || ((height % 2) == 0));
			do {
				printf("Please enter the square odd width, range 5-21 :\n");
				scanf("%d", &width);
			} while (width < 5 || width > 21 || ((width % 2) == 0));
			//Print the top
			numOfoHeight = 1;
			numOfmHeight = 1;
			numOfiHeight = 1;
			numOfoWidth = 1;
			numOfiWidth = 1;
			numOfmWidth = 1;
			tmp = width;
			while (tmp != 5) {
				if (tmp % 3 == 1) { // inc 'O'
					numOfoWidth++;
				}
				else if (tmp % 3 == 0) { //inc 'M'
					numOfmWidth++;
				}
				else if (tmp % 3 == 2) { //inv 'I'
					numOfiWidth++;
				}
				tmp = tmp - 2;
			}
			tmp = height;
			while (tmp != 5) {
				if (tmp % 3 == 1) { // inc 'O'
					numOfoHeight++;
				}
				else if (tmp % 3 == 0) { //inc 'M'
					numOfmHeight++;
				}
				else if (tmp % 3 == 2) { //inv 'I'
					numOfiHeight++;
				}
				tmp = tmp - 2;
			}

			
			for (i = 0; i < numOfoHeight; i++) {
				for (j = 0; j < width; j++) {
					printf("O");
				}
				printf("\n");
			}
			for (i = 0; i < numOfmHeight; i++) {
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				for (j = 0; j < (numOfmWidth * 2) + ((numOfiWidth * 2) - 1); j++) {
					printf("M");
				}
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				printf("\n");
			}

			for (i = 0; i < (numOfiHeight * 2) - 1; i++) {
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				for (j = 0; j < numOfmWidth; j++) {
					printf("M");
				}
				for (j = 0; j < numOfiWidth - 1; j++) {
					printf("I");
				}
				printf("I");
				for (j = 0; j < numOfiWidth - 1; j++) {
					printf("I");
				}
				for (j = 0; j < numOfmWidth; j++) {
					printf("M");
				}
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				printf("\n");
			}
			for (i = 0; i < numOfmHeight; i++) {
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				for (j = 0; j < (numOfmWidth * 2) + ((numOfiWidth * 2) - 1); j++) {
					printf("M");
				}
				for (j = 0; j < numOfoWidth; j++) {
					printf("O");
				}
				printf("\n");
			}
			for (i = 0; i < numOfoHeight; i++) {
				for (j = 0; j < width; j++) {
					printf("O");
				}
				printf("\n");
			}

		}




	}
}