#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Jacob.h"

int room1[4][50];
int room2[4][50];
int room3[4][50];
int room4[4][50];
int room5[4][50];
int room6[4][50];


void Checkin();
//int main() {
//    for (int i = 0; i < 4; ++i) {
//        for (int x = 0; x < 50; ++x) {
//            room1[i][x] = 0;
//            room2[i][x] = 0;
//            room3[i][x] = 0;
//            room4[i][x]=0;
//            room5[i][x]=0;
//            room6[i][x]=0;
//        }
//    }
//    Checkin();
//    return 0;
//}


void Checkin() {
    char surname[35];
    int dob;
    int numberofguests;
    int boardtype;
    int wakeupcall;
    int val = 0;
    srand(time(NULL));
    int r = rand();
    char bookingid[40];
    int lengthofstay;
    int check = 0;
    bool check1=true;
    bool check2 = true;
    bool check3= true;
    bool check4 = true;
    bool check5=true;
    bool checksur=true;
    int i=0;
    while(check!=6){
        if ((i !=0)){
            printf("\nThere was :  ");
            if(checksur==true){
                printf("\nSomething Wrong with your surname");
            }
            if(check1==true){
                printf("\nSomething wrong with your date of birth");
            }
            if(check2==true){
                printf("\nSomething wrong with your board type");
            }
            if(check3==true){
                printf("\nSomething wrong with your length of stay");
            }
            if (check4==true){
                printf("\nSomething wrong with your daily Wakeup Call");
            }
            if(check5==true){
                printf("\nSomething wrong with the amount of guests staying");
            }
            printf("\nPlease Enter again");
        }
        check = 0;
        int surlen=0;
        printf("\nEnter your surname  :   ");
        gets(surname);
        surlen=strlen(surname);
        if ((surlen > 0)&&(surlen<35)){
            check++;
            checksur=false;
        }
        snprintf(bookingid, 50, "%s%d", surname, r);
        printf("\nEnter your Date of Birth in the format (ddmmyy)   : ");
        if (scanf("%d", &dob)==1 &&(dob>0)&&(dob<999999)){
            check++;
            check1=false;
        }
        fflush(stdin);
        printf("\nWhat board type?(1=Full Board , 2 = Half Board , 3 = Bed and Breakfast)  : ");
        if((scanf("%d", &boardtype)==1)&&((boardtype<=3)&&(boardtype>=1))){
            check++;
            check2=false;
        }
        fflush(stdin);
        printf("\nHow long will you be staying for?  : ");
        if (scanf("%d", &lengthofstay)==1 &&(lengthofstay >0)&&(lengthofstay<365)){
            check++;
            check3=false;
        }
        fflush(stdin);
        printf("\nDo you want a Daily wakeup call? (answer with 1 for yes , 0 for no)  : ");
        if ((scanf("%d", &wakeupcall)==1)&&((wakeupcall==0)||(wakeupcall==1))){
            check++;
            check4=false;
        }
        fflush(stdin);
        printf("\nEnter how many guests are staying  : ");
        if(scanf("%d", &val)==1 && (val<19)){
            check++;
            check5=false;
        }
        fflush(stdin);
        i++;
    }
    numberofguests=val;
    while (val > 0) {
        int roomchoice=0;
        printf("\nThere are currently %d rooms available:\n", (room1[0][0] == 0) + (room2[0][0] == 0) + (room3[0][0] == 0) + (room4[0][0] == 0) + (room5[0][0] == 0) +(room6[0][0] == 0));
        if (room1[0][0] == 0) {
            printf("\nRoom 1, which houses 4 guests for $100 per night\n");
        }
        if (room2[0][0] == 0) {
            printf("\nRoom 2, which houses 4 guests for $100 per night\n");
        }
        if (room3[0][0] == 0) {
            printf("\nRoom 3, which houses 4 guests for $85 per night\n");
        }
        if (room4[0][0] == 0) {
            printf("\nRoom 4, which houses 2 guests for $75 per night\n");
        }
        if (room5[0][0] == 0) {
            printf("\nRoom 5, which houses 2 guests for $75 per night\n");
        }
        if (room6[0][0] == 0) {
            printf("\nRoom 6, which houses 2 guests for $60 per night\n");
        }
        if((room6[0][0]==1) && (room5[0][0]==1) && (room4[0][0]==1) && (room3[0][0]==1) && (room2[0][0]==1) && (room2[0][0]==1) && (room1[0][0]==1)){
            printf("\nSorry We are fully booked");
            printf("\nWe do not have the capacity for %d more guest/s",val);
            break;

        }
        check1=0;
        while((check1==0)||(roomchoice<1)||(roomchoice>6)){
            printf("Enter which room you would like to take?  :  ");
            check1=scanf("%d",&roomchoice);
            fflush(stdin);
        }
        if ((roomchoice==1)&&(room1[0][0]==0)){
            printf("You have booked room 1 and your booking id is :  ");
            puts(bookingid);
            room1[0][0]=1;
            strtoint(surname,room1[1],20);
            strtoint(bookingid,room1[2],50);
            room1[3][0]=dob;
            room1[3][1]=boardtype;
            room1[3][2]=lengthofstay;
            room1[3][3]=wakeupcall;
            room1[3][4]=numberofguests;
            val = val-4;
        }
        if ((roomchoice==2)&&(room2[0][0]==0)){
            printf("You have booked room 2 and your booking id is :  ");
            puts(bookingid);
            room2[0][0]=1;
            strtoint(surname,room2[1],20);
            strtoint(bookingid,room2[2],50);
            room2[3][0]=dob;
            room2[3][1]=boardtype;
            room2[3][2]=lengthofstay;
            room2[3][3]=wakeupcall;
            room2[3][4]=numberofguests;
            val = val-4;
        }
        if ((roomchoice==3)&&(room3[0][0]==0)){
            printf("You have booked room 3 and your booking id is :  ");
            puts(bookingid);
            room3[0][0]=1;
            strtoint(surname,room3[1],20);
            strtoint(bookingid,room3[2],50);
            room3[3][0]=dob;
            room3[3][1]=boardtype;
            room3[3][2]=lengthofstay;
            room3[3][3]=wakeupcall;
            room3[3][4]=numberofguests;
            val = val-4;
        }
        if ((roomchoice==4)&&(room4[0][0]==0)){
            printf("You have booked room 4 and your booking id is :  ");
            puts(bookingid);
            room4[0][0]=1;
            strtoint(surname,room4[1],20);
            strtoint(bookingid,room4[2],50);
            room4[3][0]=dob;
            room4[3][1]=boardtype;
            room4[3][2]=lengthofstay;
            room4[3][3]=wakeupcall;
            room4[3][4]=numberofguests;
            val = val-2;
        }
        if ((roomchoice==5)&&(room5[0][0]==0)){
            printf("You have booked room 5 and your booking id is :  ");
            puts(bookingid);
            room5[0][0]=1;
            strtoint(surname,room5[1],20);
            strtoint(bookingid,room5[2],50);
            room5[3][0]=dob;
            room5[3][1]=boardtype;
            room5[3][2]=lengthofstay;
            room5[3][3]=wakeupcall;
            room5[3][4]=numberofguests;
            val = val-2;
        }
        if ((roomchoice==6)&&(room6[0][0]==0)){
            printf("You have booked room 6 and your booking id is :  ");
            puts(bookingid);
            room6[0][0]=1;
            strtoint(surname,room6[1],20);
            strtoint(bookingid,room6[2],50);
            room6[3][0]=dob;
            room6[3][1]=boardtype;
            room6[3][2]=lengthofstay;
            room6[3][3]=wakeupcall;
            room6[3][4]=numberofguests;
            val = val-2;
        }
    }
}
