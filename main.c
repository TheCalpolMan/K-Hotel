#include <stdio.h>
#include <string.h>
#include "Arjun.h"
#include "Jacob.h"

int room1[4][50];
int room2[4][50];
int room3[4][50];
int room4[4][50];
int room5[4][50];
int room6[4][50];

int Tables[14][3];
int TableIDs[14][3];

int main() {
    int (*debugroomptr)[50];

    // initialising all gobals

    for (int i = 0; i < 4; ++i) {
        for (int x = 0; x < 50; ++x) {
            room1[i][x] = 0;
            room2[i][x] = 0;
            room3[i][x] = 0;
            room4[i][x] = 0;
            room5[i][x] = 0;
            room6[i][x] = 0;
        }
    }

    for (int i = 0; i < 14; ++i) {
        for (int x = 0; x < 3; ++x) {
            Tables[i][x] = 1;
            TableIDs[i][x] = 0;
        }
    }


    while (1){
        int choice;
        char readin[4] = "";

        fflush(stdin);
        printf("Would you like to:\n1. Check in\n2. Book a table for dinner\n3. Check out\n4. Halt the program\n");
        gets(readin);
        fflush(stdin);

        if (strcmp(readin, "254") == 0){
            choice = 254;
        } else{
            choice = readin[0] - 48;
        }

        if (choice == 1){
            Checkin();
        } else if (choice == 2){
            booktable();
        } else if (choice == 3){
            CheckOut();
        } else if (choice == 4){
            printf("Are you sure? This will remove all data currently in the program. Enter 1 for yes\n");
            scanf("%d", &choice);
            if (choice == 1){
                break;
            }
        } else if (choice == 254){
            for (int i = 0; i < 6; ++i) {
                if (i == 0){
                    debugroomptr = room1;
                } else if (i == 1){
                    debugroomptr = room2;
                } else if (i == 2){
                    debugroomptr = room3;
                } else if (i == 3){
                    debugroomptr = room4;
                } else if (i == 4){
                    debugroomptr = room5;
                } else if (i == 5){
                    debugroomptr = room6;
                }

                printf("Room %d\n\n", i + 1);

                for (int j = 0; j < 4; ++j) {
                    for (int x = 0; x < 50; ++x) {
                        printf("%d ", debugroomptr[j][x]);
                    }
                    printf("\n");
                }
                printf("\n");
            }

            printf("\nTables\n");

            for (int i = 0; i < 14; ++i) {
                for (int x = 0; x < 3; ++x) {
                    printf("%d ", Tables[i][x]);
                }
                printf("\n");
            }

            printf("\nTableIDs\n");

            for (int i = 0; i < 14; ++i) {
                for (int x = 0; x < 3; ++x) {
                    printf("%d ", TableIDs[i][x]);
                }
                printf("\n");
            }
            printf("\n");

        } else{
            printf("You didn't enter a valid choice\n\n");
        }

    }
    return 0;
}
