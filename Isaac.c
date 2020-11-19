#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void CheckOut();
int main(){


char bookingIDU[50];
int RoomsP1 = 0;
int RoomsP2 = 0;
int RoomsP3 = 0;
int RoomsP4 = 0;
int RoomsP5 = 0;
int RoomsP6 = 0;
int RoomsT;
int RoomD = 0;
int boardC = 0;
int boardP = 0;
int boardD = 0;
int boardT;
int RBcost;
int DWC;
int RBDWCcost;
int age;
int RBDWCAcost;



//Ask for booking ID
printf("If you wish to checkout then please enter your booking ID:\n  ");
scanf("%s", &bookingIDU[50]);


//Introduction to the Bill calculator
printf("Welcome to the bill calculator, you may refer to me as B.I.L.L.K;\n Below you will find a list of prices, Please enter the ones which correspond to the room/s which you have stayed in,\n");
printf("Just a heads up, if you attempt any foul play you'll pay with something that you hold dear to yourself :)\n");
printf("\nHere are the room prices: \n***************** \nRoom1: 100 pounds \n***************** \nRoom2: 100 pounds \n***************** \nRoom3: 85 pounds \n***************** \nRoom4: 75 pounds \n***************** \nRoom5: 75 pounds \n***************** \nRoom6: 50 pounds \n*****************");
printf("\nPlease enter the  price of the room/s you stayed in\n");
fflush(stdin);

//Take in the input of their rooms
scanf("%d,%d,%d,%d,%d,%d", &RoomsP1, &RoomsP2, &RoomsP3, &RoomsP4, &RoomsP5, &RoomsP6);
fflush(stdin);

//Days stayed in room
printf("Please enter the length of your stay:\n");
scanf("%d", &RoomD);
fflush(stdin);

// Calculate room total and store as a variable
printf("Your Room cost total is: %d pounds\n",
(RoomsP1 + RoomsP2 + RoomsP3 + RoomsP4 + RoomsP5 + RoomsP6) * RoomD);
RoomsT = (RoomsP1 + RoomsP2 + RoomsP3 + RoomsP4 + RoomsP5 + RoomsP6) * RoomD;
fflush(stdin);

//Gather their board meals data
printf("\nWe will now calculate the total cost of your board meals:\n");
printf("Here are all of the Board Meal options:\n ");
printf("Full Board(FB): 20 pounds\n Half board(HB): 15 pounds\n Bed and Breakfast(BB): 5 pounds\n");
printf("Please enter the price/s of your Board Meals:\n");
scanf("%d", &boardC);
fflush(stdin);

//Gather the amount of people
printf("Please enter the amount of people who had board meals:\n");
scanf("%d", &boardP);
fflush(stdin);

//Gather how many days they stayed
printf("Please enter the length of your stay:\n");
scanf("%d", &boardD);

//Calculate the Board Meal total and store as a variable
printf("The total cost for your board meal/s is %d pounds\n", boardC * boardD * boardP);
boardT = boardC * boardD * boardP;
fflush(stdin);

//Add room total and board total, to store as new variable
printf("Your new total is:\n ");
printf("\n %d pounds", RoomsT + boardT);
RBcost = RoomsT + boardT;
fflush(stdin);

//Check if they had wake up call
printf("\nDaily wake up call: 5 pounds \nNo daily wake up call: 0 pounds");
printf("\nIf you had daily wake up calls then enter (5), if not then enter(0):\n");
scanf("%d", &DWC);
if (DWC == 5) {
printf("Your updated total is %d pounds\n", RBcost + 5);
RBDWCcost = RBcost + 5;
}
if (DWC == 0) {
printf("Your updated total is %d pounds\n", RBcost + 0);
RBDWCcost = RBcost + 0;
}

//ask for age and apply suitable discount
printf("Please enter your age:\n ");
scanf("%d", &age);
fflush(stdin);
if (age > 65 && age <= 100) {
printf("Your new total is %d pounds\n", RBDWCcost - (RBDWCcost / 10));
RBDWCAcost = RBDWCcost - (RBDWCcost / 10);
} else if (age < 18 && age > 0) {
printf("Your new total is %d pounds\n", RBDWCcost / 2);
RBDWCAcost = RBDWCcost / 2;
} else {
printf("Your new price is %d pounds\n", RBDWCcost);
RBDWCAcost = RBDWCcost;
}
//Final bill
printf("Thank you for bearing with us, here is your final bill:\n");
printf("\n%s\n", bookingIDU);
printf(" \n*****************\n");
printf("\nTotal cost of rooms used is %d pounds\n", RoomsT);
printf(" \n*****************\n");
printf("\nTotal cost of party's board is %d pounds\n", boardT);
printf(" \n*****************\n");
printf("\nRoom total and Board total w/s Daily wake up call cost is %d pounds\n", RBDWCcost);
printf(" \n*****************\n");
printf("\nAge discount cost applied to total is %d pounds\n", RBDWCAcost);
printf(" \n*****************\n");
printf("\nYour final total is:\n");
printf(" \n*****************\n");
printf("\n%d pounds\n", RBDWCAcost);
printf(" \n*****************\n");

}
