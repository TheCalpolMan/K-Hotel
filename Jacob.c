#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Jacob.h"

void strtoint(char source[], int dest[], int lengthofconversion){
    for (int i = 0; i < lengthofconversion; ++i) {
        dest[i] = (int) source[i];
    }
}

void inttostr(int source[], char dest[], int lengthofconversion){
    for (int i = 0; i < lengthofconversion; ++i) {
        dest[i] = (char) source[i];
    }
}

int geti(){
    char get[32];
    int dest = 0, negative = 0, started = 0, startpos = 0;

    gets(get);

    for (int i = 0; i < 32; ++i) {
        if ((get[i] < 48 || get[i] > 57) && started){
            break;
        }
        if (((get[i] > 47 && get[i] < 58) || get[i] == '-') && !started){
            started = 1;
            startpos = i;
            if (get[i] == '-'){
                negative = 1;
            }

        }

        if (started && i >= startpos + negative){
            dest = dest * 10 + (get[i] - 48);
            printf("%d\n", dest);
        }
    }

    if (negative){
        dest *= -1;
    }
    return dest;
}


int Tables[14][3];
int TableIDs[14][3];

int room1[4][50];
int room2[4][50];
int room3[4][50];
int room4[4][50];
int room5[4][50];
int room6[4][50];

void booktable(){
    char bookingid[50] = "", idtocompare[50] = "", sitat[8] = "";
    int tableprinted = 0, valid = 0, rooms[6] = {0, 0, 0, 0, 0, 0}, tosit = 0, tablesneeded = 0, sittingat[3] = {0, 0, 0}, validboard = 1, booktime = 0, day = 0, inroom = 0;

    char days[7][10] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
    };

    srand(time(NULL));
    day = rand() % 7;

    printf("Today's %s!\n", days[day]);

    printf("Please enter your booking ID: ");
    gets(bookingid);

    // checking if the booking ID is registered to any of the rooms

    inttostr(room1[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[0] = 1;
        inroom = 1;
        tosit = room1[3][4];
        if (room1[3][1] == 3){
            validboard = 0;
        }
    }

    inttostr(room2[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[1] = 1;
        inroom = 2;
        tosit = room2[3][4];
        if (room2[3][1] == 3){
            validboard = 0;
        }
    }

    inttostr(room3[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[2] = 1;
        inroom = 3;
        tosit = room3[3][4];
        if (room3[3][1] == 3){
            validboard = 0;
        }
    }

    inttostr(room4[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[3] = 1;
        inroom = 4;
        tosit = room4[3][4];
        if (room4[3][1] == 3){
            validboard = 0;
        }
    }

    inttostr(room5[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[4] = 1;
        inroom = 5;
        tosit = room5[3][4];
        if (room5[3][1] == 3){
            validboard = 0;
        }
    }

    inttostr(room6[2], idtocompare, 50);
    if (strcmp(bookingid, idtocompare) == 0){
        valid = 1;
        rooms[5] = 1;
        inroom = 6;
        tosit = room6[3][4];
        if (room6[3][1] == 3){
            validboard = 0;
        }
    }

    // kicking the user out if they entered an invalid ID
    if (!valid){
        printf("You didn't enter a valid booking ID\n");
        return;
    }

    if (!validboard){
        printf("You've booked a B&B meal plan, hence you cannot book a table for an evening meal, sorry\n");
        return;
    }

    fflush(stdin);

    // checking if there are enough seats
    if (tosit > (Tables[0 + day * 2][0] + Tables[0 + day * 2][1] + Tables[0 + day * 2][2]) * 4 && tosit > (Tables[1 + day * 2][0] + Tables[1 + day * 2][1] + Tables[1 + day * 2][2]) * 4 ){
        printf("We don't have enough tables for you today, sorry\n");
        return;
    }

    printf("We have %d tables available at 7: ", Tables[0 + day * 2][0] + Tables[0 + day * 2][1] + Tables[0 + day * 2][2]);

    if (Tables[0 + day * 2][0]){
        printf("Endor");
        tableprinted = 1;
    }

    if (Tables[0 + day * 2][1]){
        if (tableprinted){
            printf(", ");
        }

        printf("Naboo");
        tableprinted = 1;

    }

    if (Tables[0 + day * 2][2]){
        if (tableprinted){
            printf(", ");
        }

        printf("Tatooine");
        tableprinted = 1;
    }

    printf("\n");
    tableprinted = 0;

    printf("We have %d tables available at 9: ", Tables[1 + day * 2][0] + Tables[1 + day * 2][1] + Tables[1 + day * 2][2]);

    if (Tables[1 + day * 2][0]){
        printf("Endor");
        tableprinted = 1;
    }

    if (Tables[1 + day * 2][1]){
        if (tableprinted){
            printf(", ");
        }

        printf("Naboo");
        tableprinted = 1;

    }

    if (Tables[1 + day * 2][2]){
        if (tableprinted){
            printf(", ");
        }

        printf("Tatooine");
        tableprinted = 1;
    }

    printf("\nWhat time would you like to book for?");
    booktime = geti();
    while (booktime != 7 && booktime != 9){
        printf("Please enter a valid time (either 7 or 9) %d\n", booktime);
        fflush(stdin);
        booktime = geti();
    }

    if (tosit > (Tables[booktime == 9 + day * 2][0] + Tables[booktime == 9 + day * 2][1] + Tables[booktime == 9 + day * 2][2]) * 4){
        printf("We don't have enough tables for you at %d, sorry\n", booktime);
        return;
    }

    tablesneeded = tosit / 4 + (tosit % 4 != 0);
    if (tablesneeded == 1){
        printf("You need to book 1 table, however you may book more. Enter ");
    } else{
        printf("You need to book %d tables. Enter ", tablesneeded);
    }

    if (Tables[booktime == 9 + day * 2][0] == 1){
        printf("1 for Endor");
        tableprinted = 1;
    }

    if (Tables[booktime == 9 + day * 2][1] == 1){
        if (tableprinted){
            printf(", ");
        }

        printf("2 for Naboo");
        tableprinted = 1;

    }

    if (Tables[booktime == 9 + day * 2][0] == 1){
        if (tableprinted){
            printf(", ");
        }

        printf("3 for Tatooine");
        tableprinted = 1;
    }

    printf(" in a space delimited fashion (1 2 3): ");

    fflush(stdin);
    gets(sitat);
    valid = 1;

    for (int i = 0; i < 8; ++i) {
        if (sitat[i] > 48 && sitat[i] < 52){
            sittingat[sitat[i] - 49] = 1;

            if (Tables[booktime == 9 + day * 2][sitat[i] - 49] == 0){
                valid = 0;
            }
        }
    }

    if (valid == 0){
        printf("You entered a table that's already been booked for %dpm\n", booktime);
        return;
    }

    if ((sittingat[0] + sittingat[1] + sittingat[2]) * 4 >= tosit){
        printf("Your tables have been booked for %dpm today!\n", booktime);
        for (int i = 0; i < 3; ++i) {
            if (sittingat[i]) {
                Tables[booktime == 9 + day * 2][i] = 0;
                TableIDs[booktime == 9 + day * 2][i] = inroom;
            }
        }
    } else{
        printf("You haven't submitted enough tables\n");
        return;
    }
}

void CheckOut() {
    char tempID[50], bookingID[50], currentdate[9];
    int inrooms[6], valid = 0, (*roomptr)[50], dates[2][3] = {0, 0, 0, 0, 0, 0}, temp = 0, dayshift = 0;
    int monthlens[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    double time1 = 0, time2 = 0, age = 0;

    float cost = 0, oldcost = 0;
    struct tm *info;
    time_t rawtime;

    time(&rawtime);
    info = localtime(&rawtime);
    strftime(currentdate, 9, "%x", info);

    // I didn't use a struct you saw nothing :)

    for (int i = 0; i < 50; ++i) {
        tempID[i] = 0;
        bookingID[i] = 0;
    }

    for (int i = 0; i < 6; ++i) {
        inrooms[i] = 0;
    }

    printf("Please enter your booking ID\n");
    scanf("%s", bookingID);

    // checking which rooms they're in

    inttostr(room1[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[0] = 1;
        valid = 1;
        roomptr = room1;
        cost += 100;
    }

    inttostr(room2[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[1] = 1;
        valid = 2;
        roomptr = room2;
        cost += 100;
    }

    inttostr(room3[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[2] = 1;
        valid = 3;
        roomptr = room3;
        cost += 85;
    }

    inttostr(room4[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[3] = 1;
        valid = 4;
        roomptr = room4;
        cost += 75;
    }

    inttostr(room5[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[4] = 1;
        valid = 5;
        roomptr = room5;
        cost += 75;
    }

    inttostr(room6[2], tempID, 50);

    if (strcmp(tempID, bookingID) == 0) {
        inrooms[5] = 1;
        valid = 6;
        roomptr = room6;
        cost += 50;
    }

    // checking if they entered a valid booking ID

    if (!valid) {
        printf("You didn't enter a valid booking ID\n");
        return;
    }

    printf("Your booking ID is: %s", bookingID);

    cost *= roomptr[3][2];

    // calculating user's age

    for (int i = 0; i < 9; ++i) {
        if (currentdate[i] > 47 && currentdate[i] < 58) {
            temp = (currentdate[i] - 48);
            temp += temp * (9 * (i % 3 == 0));

            dates[1][2 - (i / 3)] += temp;
        }
    }

    // age is being used as a temporary holder for date data
    age = dates[1][1];
    dates[1][1] = dates[1][2];
    dates[1][2] = age;
    age = 0;

    itoa(roomptr[3][0], currentdate, 10);

    if (currentdate[5] == 0) {
        dayshift = 1;
    }

    for (int i = 0; i < 6 - dayshift; ++i) {
        if (currentdate[i] > 47 && currentdate[i] < 58) {
            temp = (currentdate[i] - 48);
            temp += temp * (9 * ((i - dayshift) % 2 == 0));

            dates[0][2 - ((i - dayshift) / 2)] += temp;
        }
    }


    time1 += dates[0][2];
    for (int i = 0; i < dates[0][1]; ++i) {
        time1 += monthlens[i];
    }
    time1 += dates[0][0] * 365;

    if (dates[0][0] < dates[1][0]) {
        time1 += 365 * 100;
    }

    time2 += dates[1][2];
    for (int i = 0; i < dates[1][1]; ++i) {
        time2 += monthlens[i];
    }
    time2 += dates[1][0] * 365.25;


    time2 += 365.25 * 100;

    age = time2 - time1;

    if (age >= (double) 65 * 365.25) {
        cost = cost * 0.9;
    }

    oldcost = cost;
    printf("\nYour room cost is $%f", oldcost);

    // adding board cost

    if (roomptr[3][1] == 1) {
        cost += 20 * roomptr[3][4] * roomptr[3][2];
    } else if (roomptr[3][1] == 2) {
        cost += 15 * roomptr[3][4] * roomptr[3][2];
    } else {
        cost += 5 * roomptr[3][4] * roomptr[3][2];
    }

    printf("\nYour board cost is $%f", cost - oldcost);
    oldcost = cost;

    // adding wake up call cost

    cost += roomptr[3][3] * 5;

    if (oldcost != cost) {
        printf("\nYour wake up call cost is $5");
    }

    printf("\n\nThe total cost was $%f.\n\nWe hope you enjoyed your stay!\n", cost);

    // resetting table and room data in accordance with which tables/rooms the guests used

    for (int i = 0; i < 14; ++i) {
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 6; ++y) {
                if (TableIDs[i][x] == y && inrooms[y]) {
                    TableIDs[i][x] = 0;
                    Tables[i][x] = 1;
                }
            }
        }
    }

    if (inrooms[0]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room1[i][x] = 0;
            }
        }
    }
    if (inrooms[1]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room2[i][x] = 0;
            }
        }
    }
    if (inrooms[2]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room3[i][x] = 0;
            }
        }
    }
    if (inrooms[3]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room4[i][x] = 0;
            }
        }
    }
    if (inrooms[4]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room5[i][x] = 0;
            }
        }
    }
    if (inrooms[5]) {
        for (int i = 0; i < 4; ++i) {
            for (int x = 0; x < 50; ++x) {
                room6[i][x] = 0;
            }
        }
    }
}

//int main(){
//    for (int i = 0; i < 4; ++i) {
//        for (int x = 0; x < 50; ++x) {
//            room1[i][x] = 0;
//            room2[i][x] = 0;
//            room3[i][x] = 0;
//            room4[i][x] = 0;
//            room5[i][x] = 0;
//            room6[i][x] = 0;
//        }
//    }
//
//    for (int i = 0; i < 14; ++i) {
//        for (int x = 0; x < 3; ++x) {
//            Tables[i][x] = 1;
//        }
//    }
//
//    room1[2][0] = 119;
//    room1[2][1] = 104;
//    room1[2][2] = 97;
//    room1[2][3] = 114;
//    room1[2][4] = 116;
//    room1[2][5] = 111;
//    room1[2][6] = 110;
//    room1[2][7] = 49;
//    room1[2][8] = 50;
//    room1[2][9] = 51;
//    room1[2][10] = 52;
//    room1[2][11] = 53;
//
//    room1[3][4] = 3;
//
//    booktable();
//
//    return 0;
//}
