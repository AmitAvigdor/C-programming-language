//עמית אביגדור 316178144 Amit Avigdor
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct serie {
	char serieName[20];
	int serieCode;
	int numSeasons;
	int* watchingDetails;
	int activeFlag;
	int rank;
}serie;

int unify_database_details(serie*);
void print_series_list_sorted_by_code(serie*);
void print_menu();
void unify_database();
void get_watching_details(serie*);
void initialize_flag(serie*);
void initialize_watching_list(serie*, int, int);
void show_all_watching_details(serie*);
void print_series_sorted_by_rank(serie*);
void make_series_file_sorted_by_rank(serie*);
void free_dynamic_arr(serie*);

void main() {
	struct serie arr[1001];
	int user;
	int flag_unify_database = 0;
	int flag_unify_database_ditails = 0;
	int num_of_s;
	do {
		print_menu();
		scanf("%d", &user);
		switch (user) {
		case 1:
			if (flag_unify_database == 0) {
				unify_database();
				printf("Unify Succeeded\n");
				flag_unify_database = 1;
			}
			else {
				printf("Unify Database Has Been Done Already !!!\n");
			}
			break;

		case 2:
			if (flag_unify_database == 1) {
				num_of_s = unify_database_details(arr);
				flag_unify_database_ditails = 1;
				printf("Get Unify Database Details Succeeded\n");
			}
			else {
				printf("You must unify database before using this option!!!\n");
			}
			break;

		case 3:
			if (flag_unify_database != 1) {
				printf("You must unify database before using this option!!!\n");
				break;
			}
			if (flag_unify_database_ditails != 1) {
				printf("You must Get Unify Database Details before using this option!!!\n");
				break;
			}
			print_series_list_sorted_by_code(arr);
			break;

		case 4:
			if (flag_unify_database != 1) {
				printf("You must unify database before using this option!!!\n");
				break;
			}
			if (flag_unify_database_ditails != 1) {
				printf("You must Get Unify Database Details before using this option!!!\n");
				break;
			}
			get_watching_details(arr);
			break;

		case 5:
			if (flag_unify_database != 1) {
				printf("You must unify database before using this option!!!\n");
				break;
			}
			if (flag_unify_database_ditails != 1) {
				printf("You must Get Unify Database Details before using this option!!!\n");
				break;
			}
			show_all_watching_details(arr);
			break;

		case 6:
			if (flag_unify_database != 1) {
				printf("You must unify database before using this option!!!\n");
				break;
			}
			if (flag_unify_database_ditails != 1) {
				printf("You must Get Unify Database Details before using this option!!!\n");
				break;
			}
			print_series_sorted_by_rank(arr);
			break;

		case 7:
			if (flag_unify_database != 1) {
				printf("You must unify database before using this option!!!\n");
				break;
			}
			if (flag_unify_database_ditails != 1) {
				printf("You must Get Unify Database Details before using this option!!!\n");
				break;
			}
			make_series_file_sorted_by_rank(arr);

			break;

		case 8:
			//free_dynamic_arr(arr);
			printf("End Of The Program...");
			exit(0);

			break;

		}

	} while (user != 8);
}


// Every time that we call the function the menu will display on the screen.
void print_menu() {
	printf("**********Main Menu **************\n");
	printf("1. Unify Database.\n");
	printf("2. Get Unify Database Details.\n");
	printf("3. Print The Series List Sorted By Code.\n");
	printf("4. Get Watching Details.\n");
	printf("5. Show All Watching Details.\n");
	printf("6. Print Series Sorted By Rank.\n");
	printf("7. Make Series File Sorted By Rank.\n");
	printf("8. Exit.\n");
	printf("Enter Your Selection:");
}
// case 1 - the function will ask the use for the 2 files and unify them
void unify_database() {
	char first_file_name[20], second_file_name[20];
	FILE* first_file;
	FILE* second_file;
	FILE* unify_file;
	char scries_name1[20];
	int scries_c1;
	int scries_s1;
	char active1[2];
	char scries_name2[20];
	int scries_c2;
	int scries_s2;
	char active2[2];
	int eof_first_file = 4, eof_second_file = 4, cmp;
	do {
		printf("Enter First File Name:\n");
		scanf("%s", first_file_name);
		first_file = fopen(first_file_name, "r");
		if (first_file == NULL) {
			printf("error in opening file %s !!!\n", first_file_name);
		}
	} while (first_file == NULL);
	do {
		printf("Enter Second File Name:\n");
		scanf("%s", second_file_name);
		second_file = fopen(second_file_name, "r");
		if (second_file == NULL) {
			printf("error in opening file %s !!!\n", second_file_name);
		}
	} while (second_file == NULL);
	unify_file = fopen("series.txt", "w");
	if (!unify_file)
		printf("Can't open the file\n");
	eof_first_file = fscanf(first_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name1, &scries_c1, &scries_s1, active1);
	eof_second_file = fscanf(second_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name2, &scries_c2, &scries_s2, active2);
	while (eof_first_file > 0 || eof_second_file > 0) {
		if (eof_first_file <= 0) {
			while (eof_second_file > 0) {
				if (active2[0] == 'Y') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name2, scries_c2, scries_s2);
				}
				eof_second_file = fscanf(second_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name2, &scries_c2, &scries_s2, active2);
			}
		}
		else if (eof_second_file <= 0) {
			while (eof_first_file > 0) {
				if (active1[0] == 'Y') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name1, scries_c1, scries_s1);
				}
				eof_first_file = fscanf(first_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name1, &scries_c1, &scries_s1, active1);
			}
		}
		else {


			while (scries_c1 < scries_c2 && eof_first_file > 0) {
				if (active1[0] == 'Y') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name1, scries_c1, scries_s1);
				}
				eof_first_file = fscanf(first_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name1, &scries_c1,
					&scries_s1, active1);
			}
			while (scries_c2 < scries_c1 && eof_second_file > 0) {
				if (active2[0] == 'Y') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name2, scries_c2, scries_s2);
				}
				eof_second_file = fscanf(second_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name2, &scries_c2,
					&scries_s2, active2);
			}
			if (scries_c1 == scries_c2) {
				if (active1[0] == 'Y' && active2[0] == 'N') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name1, scries_c1, scries_s1);
				}
				else if (active1[0] == 'N' && active2[0] == 'Y') {
					fprintf(unify_file, "%s,%d,%d\n", scries_name2, scries_c2, scries_s2);
				}
				else if (active1[0] == 'Y' && active2[0] == 'Y') {
					if (scries_s1 > scries_s2) {
						fprintf(unify_file, "%s,%d,%d\n", scries_name1, scries_c1, scries_s1);
					}
					else {
						fprintf(unify_file, "%s,%d,%d\n", scries_name2, scries_c2, scries_s2);
					}
				}

				eof_first_file = fscanf(first_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name1, &scries_c1, &scries_s1, active1);
				eof_second_file = fscanf(second_file, "%20[^,]%*c%d%*c%d%*c%c%*c", scries_name2, &scries_c2, &scries_s2, active2);
			}
		}
	}
	fclose(unify_file);
	fclose(first_file);
	fclose(second_file);
}
//case 2 - the function will crate a struct data base, case on the file from case 1
int unify_database_details(serie* arr) {
	FILE* tmp;
	char scrie_name[20];
	int scrie_code;
	int num_seasons;
	int eof_tmp;

	initialize_flag(arr);
	tmp = fopen("series.txt", "r");
	eof_tmp = fscanf(tmp, "%20[^,]%*c%d%*c%d&*c&*c%*c", scrie_name, &scrie_code, &num_seasons);
	while (eof_tmp > 0) {
		if (scrie_name[0] == '\n')
			memmove(scrie_name, scrie_name + 1, strlen(scrie_name));
		strcpy(arr[scrie_code].serieName, scrie_name);
		arr[scrie_code].serieCode = scrie_code;
		arr[scrie_code].numSeasons = num_seasons;
		initialize_watching_list(arr, num_seasons, scrie_code);
		arr[scrie_code].activeFlag = 1;
		eof_tmp = fscanf(tmp, "%20[^,]%*c%d%*c%d%*c", scrie_name, &scrie_code, &num_seasons);
	}
	fclose(tmp);

}

//case 3 - print the file from case 2 sorted
void print_series_list_sorted_by_code(serie* arr) {
	int i, tmp = 0;
	printf("Series List\n");
	for (i = 1; i < 1000; i++) {
		if (strlen(arr[i].serieName) != 0 && arr[i].activeFlag == 1) {
			printf("%03d-%s(%d)\n", arr[i].serieCode, arr[i].serieName, arr[i].numSeasons);
			tmp++;

		}
	}
}
//case 4 - get from the user watching list and update the struct
void get_watching_details(serie* arr) {
	int user_serie_code;
	int user_watch;
	FILE* watch_file;
	printf("Insert Serie Code:");
	scanf("%d", &user_serie_code);
	while (arr[user_serie_code].activeFlag != 1) {
		printf("wrong serie code, try again!!!\n");
		scanf("%d", &user_serie_code);
	}
	printf("Insert Season Number (1 - %d):", arr[user_serie_code].numSeasons);
	scanf("%d", &user_watch);
	while (user_watch < 1 || user_watch > arr[user_serie_code].numSeasons) {
		printf("wrong season number, try again!!!\n");
		scanf("%d", &user_watch);
	}
	printf("series: %d, season: %d accepted!!!\n", arr[user_serie_code].serieCode, user_watch);
	watch_file = fopen("watching.txt", "a");
	fprintf(watch_file, "%03d,%d\n", arr[user_serie_code].serieCode, user_watch);
	fclose(watch_file);
	arr[user_serie_code].watchingDetails[user_watch - 1] ++;
	arr[user_serie_code].rank++;

}
// initialize the flag in the struct so we know that id there is a serice in the currect postion
void initialize_flag(serie* arr) {
	int i;
	for (i = 0; i <= 1001; i++) {
		arr[i].activeFlag = 0;
		arr[i].rank = 0;
	}
}
// initialize the dynamic arr of the watching list
void initialize_watching_list(serie* arr, int num_seasons, int scrie_code) {
	int i;
	arr[scrie_code].watchingDetails = (int*)malloc(num_seasons * sizeof(int));
	for (i = 0; i < num_seasons; i++) {
		arr[scrie_code].watchingDetails[i] = 0;

	}

}

//case 5 - print the watching list from case 4
void show_all_watching_details(serie* arr) {
	FILE* watching_file;
	int series_code, season_number;
	int eof = 4;
	watching_file = fopen("watching.txt", "r");
	if (watching_file == NULL) {
		printf("error in opening file %s !!!\n", watching_file);
	}
	printf("Watching Details\n");
	while (eof > 0) {
		eof = fscanf(watching_file, "%d%*c%d%*c", &series_code, &season_number);
		if (eof <= 0) {
			break;
		}
		printf("Series Code:%03d, Season Number:%d\n", series_code, season_number);
	}
	fclose(watching_file);

}

//case 6 - print the same whathing list sort ny rank
void print_series_sorted_by_rank(serie* arr) {
	int max_rank = 0;
	int i, j, k;
	for (i = 0; i < 1001; i++) {
		if (arr[i].rank > max_rank)
			max_rank = arr[i].rank;
	}
	for (i = max_rank; i >= 0; i--) {
		printf("RANK %d\n", i);
		for (j = 0; j < 1001; j++) {
			if (arr[j].rank == i && arr[j].activeFlag == 1) {
				printf("%03d-%s\n", arr[j].serieCode, arr[j].serieName);
				for (k = 0; k < arr[j].numSeasons; k++) {
					printf("Season %d:%d\n", k + 1, arr[j].watchingDetails[k]);
				}
			}
		}
	}
}

//case 7 - print to file like case 6
void make_series_file_sorted_by_rank(serie* arr) {
	int max_rank = 0;
	int i, j, k;
	FILE* series_rank_file;
	series_rank_file = fopen("seriesRank.txt", "a");
	for (i = 0; i < 1001; i++) {
		if (arr[i].rank > max_rank)
			max_rank = arr[i].rank;
	}
	for (i = max_rank; i >= 0; i--) {
		for (j = 0; j < 1001; j++) {
			if (arr[j].rank == i) {
				fprintf(series_rank_file, "%03d(Rank:%d)-%s\n", arr[j].serieCode, arr[j].rank, arr[j].serieName);
			}
		}
	}
	fclose(series_rank_file);
}

//Free the dynamic arr of the watching list
void free_dynamic_arr(serie* arr) {
	int i;
	for (i = 1; i < 1001; i++) {
		if (arr[i].activeFlag = 1)
			free(arr[i].watchingDetails);
	}
}



