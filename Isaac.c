#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



        void CheckOut();
int main(){



        char bookingIDU[40];
        float RoomsP1 = 0;
        float RoomsP2 = 0;
        float RoomsP3 = 0;
        float RoomsP4 = 0;
        float RoomsP5 = 0;
        float RoomsP6 = 0;
        float RoomsT;
        float RoomD = 0;
        float boardC = 0;
        float boardP = 0;
        float boardD = 0;
        float boardT;
        float RBcost;
        int DWC;
        float RBDWCcost;
        int age;
        float RBDWCAcost;



//Ask for booking ID
            printf("If you wish to checkout then please enter your booking ID:\n  ");
            gets(bookingIDU);


//Introduction to the Bill calculator
            printf("Welcome to the bill calculator,\n Below you will find a list of prices, Please enter the ones which correspond to the room/s which you have stayed in,\n");
            printf("Just a heads up, if you attempt any foul play, there will be consequences :)\n");
            printf("\nHere are the room prices: \n----------------- \nRoom1: 100 pounds \n----------------- \nRoom2: 100 pounds \n----------------- \nRoom3: 85 pounds \n----------------- \nRoom4: 75 pounds \n----------------- \nRoom5: 75 pounds \n----------------- \nRoom6: 50 pounds \n-----------------");
            printf("\nPlease enter the  price of the room/s you stayed in\n");
            fflush(stdin);

//Take in the input of their rooms
            scanf("%f,%f,%f,%f,%f,%f", &RoomsP1, &RoomsP2, &RoomsP3, &RoomsP4, &RoomsP5, &RoomsP6);
            fflush(stdin);

//Days stayed in room
            printf("Please enter the length of your stay:\n");
            scanf("%f", &RoomD);
            fflush(stdin);

// Calculate room total and store as a variable
            printf("Your Room cost total is: %f pounds\n",
                   (RoomsP1 + RoomsP2 + RoomsP3 + RoomsP4 + RoomsP5 + RoomsP6) * RoomD);
            RoomsT = (RoomsP1 + RoomsP2 + RoomsP3 + RoomsP4 + RoomsP5 + RoomsP6) * RoomD;
            fflush(stdin);

//Gather their board meals data
            printf("\nWe will now calculate the total cost of your board meals:\n");
            printf("Here are all of the Board Meal options:\n ");
            printf("Full Board(FB): 20 pounds\n Half board(HB): 15 pounds\n Bed and Breakfast(BB): 5 pounds\n");
            printf("Please enter the price/s of your Board Meals:\n");
            scanf("%f", &boardC);
            fflush(stdin);

//Gather the amount of people
            printf("Please enter the amount of people who had board meals:\n");
            scanf("%f", &boardP);
            fflush(stdin);

//Gather how many days they stayed
            printf("Please enter the length of your stay:\n");
            scanf("%f", &boardD);

//Calculate the Board Meal total and store as a variable
            printf("The total cost for your board meal/s is %f pounds\n", boardC * boardD * boardP);
            boardT = boardC * boardD * boardP;
            fflush(stdin);

//Add room total and board total, to store as new variable
            printf("\nYour new total is:\n ");
            printf("%f pounds\n", RoomsT + boardT);
            RBcost = RoomsT + boardT;
            fflush(stdin);

//Check if they had wake up call
            printf("\nDaily wake up call: 5 pounds \nNo daily wake up call: 0 pounds");
            printf("\nIf you had daily wake up calls then enter (5), if not then enter(0):\n");
            scanf("%d", &DWC);
            if (DWC == 5) {
                printf("Your updated total is %f pounds\n", RBcost + 5);
                RBDWCcost = RBcost + 5;
            }
            if (DWC == 0) {
                printf("Your updated total is %f pounds\n", RBcost + 0);
                RBDWCcost = RBcost + 0;
            }

//ask for age and apply suitable discount
            printf("Please enter your age:\n ");
            scanf("%d", &age);
            fflush(stdin);
            if (age > 65 && age <= 100) {
                printf("Your new total is %f pounds\n", RBDWCcost - (RBDWCcost / 10));
                RBDWCAcost = RBDWCcost - (RBDWCcost / 10);
            } else if (age < 18 && age > 0) {
                printf("Your new total is %f pounds\n", RBDWCcost / 2);
                RBDWCAcost = RBDWCcost / 2;
            } else {
                printf("Your new price is %f pounds\n", RBDWCcost);
                RBDWCAcost = RBDWCcost;
            }
//Final bill
            printf("Thank you for bearing with us, here is your final bill:\n");
            printf("\nHere is your booking ID: ");
            puts(bookingIDU);
            printf(" \n--------------------------------------------\n");
            printf("\nTotal cost of rooms used is: %f pounds\n", RoomsT);
            printf(" \n-----------------------------------------------\n");
            printf("\nTotal cost of party's board is: %f pounds\n", boardT);
            printf(" \n--------------------------------------------------------------------------\n");
            printf("\nRoom total and Board total w/s Daily wake up call cost is: %f pounds\n", RBDWCcost);
            printf(" \n------------------------------------------------------\n");
            printf("\nAge discount cost applied to total is: %f pounds\n", RBDWCAcost);
            printf(" \n--------------------\n");
            printf("\nYour final total is:\n");
            printf(" \n------------------\n");
            printf("\n%f pounds\n", RBDWCAcost);
            printf(" \n------------------------------\n");
            printf("We hope you enjoyed your stay!\n");

        }
