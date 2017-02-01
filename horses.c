// Chris Marquis, Kyle Sizemore, Dylan Parson, Frank Rodriguez
// Prof Hunchuck
// COP2220C-23863
// tonyandtheponies.c
// assignment 5

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Function list
void title();
int parsePossibilities(int probabilities[], int arraySize);
char mainMenu();
char atmMenu();
double withdraw(double bankBalance);
double depositFunc(double walletBalance);
void theBoard(int payout[], int arraySize);
double placeBets(double walletBalance);
void runRace();
void delay(double dly);

int main()
{
	// Variables declared
	char mainChoice, atmChoice;
	double walletBalance = 0, bankBalance = 300, withdrawl, deposit, bet;
	// Can also be accompished with a single 2D array?
	int horses[] = { 30, 10, 8, 6, 2, 4, 8, 10, 22 };
	// Looked for an algorithm for relationship between payouts and calculated odds? I did not have much luck.
	int payout[] = { 2 , 5, 10, 15, 50, 20, 10, 5, 3 };
	int contProgram = 1, contATM, winner, hopeful;

	//seeding rand() to create a more pleasing "random"
	srand(time(NULL));
	// I have read that it is good to call the rand() once after you seed it, otherwise it can do "less desirable things?"  Not sure how true this is..
	rand();
	title();
	getchar();
	system("cls");
	printf("You got paid today! Let's go blow it at the racetrack.\n\n", (bankBalance));
	while (contProgram == 1)
	{
		//The program will end if there is no $ left
		if (walletBalance == 0 && bankBalance == 0)
		{
			printf("\n\nYou are BROKE!  No reason to hang around here.  Bye.\n\n");
			contProgram = 0;
			getchar();
			break;
		}
		mainChoice = mainMenu();
		switch (mainChoice)
		{
			case 'A':  // ATM transactions
			{
				contATM = 1; // Reset contATM for when the program loops
				while (contATM == 1)
				{
					printf("\n\tYou have $%.2lf in your wallet.\n\n", walletBalance);
					atmChoice = atmMenu();
					switch (atmChoice)
					{
						case 'A': // get balance
						{
							printf("\n\tYour bank balance is $%.2lf\n", bankBalance);
							break;
						}
						case 'B': // withdraw $
						{
							withdrawl = withdraw(bankBalance);
							bankBalance -= withdrawl;
							walletBalance += withdrawl;
							break;
						}
						case 'C': // deposit $
						{
							deposit = depositFunc(walletBalance);
							bankBalance += deposit;
							walletBalance -= deposit;
							break;
						}
						case 'D': // quit ATM
						{
							contATM = 0;
							break;
						}
						default:
							printf("Invalid option. Try again");
							break;
					} // END menu switch
				} // END contATM
				break;

			}
			case 'B': // Place bets and run the race here
			{
				if (walletBalance > 0)
				{
					// Place bets
					printf("Choose a horse from the BIG BOARD:\n");
					theBoard(payout, 9);
					printf("What number horse do you choose: ");
					scanf_s(" %i", &hopeful);
					bet = placeBets(walletBalance);
					printf("OK, $%.2lf on horse %i...", bet, hopeful);
					//Run the race
					runRace();
					// Calculate the winner
					winner = parsePossibilities(horses, 9);
					if (winner + 1 == hopeful)
					{
						printf("You won!!\n\n");
						delay(2);
						walletBalance += (bet * payout[winner]);
						printf("\tHorse %i is the winner at %i-1 odds! Your payout is %.2lf\n", winner + 1,payout[winner], (bet * payout[winner]));
						printf("You have $%.2lf in your wallet now.", walletBalance);
					}
					else
					{
						printf("You lost!\n\n");
						delay(2);
						walletBalance -= bet;
						printf("\tHorse %i lost.  You now have $%.2lf in your wallet", hopeful, walletBalance);
					}
					break;
				}
				else
				{
					printf("You need to go to the ATM and take out some $");
					break;
				}
			}
			case 'C': // QUIT
			{
				printf("<ENTER> to close");
				contProgram = 0;
				break;
			}
		} // END switch
	} // END while contProgram
	printf("Hit <ENTER> to close");
	getchar();
} // END MAIN

void title()
{
	printf("\n\tTony and the Ponies\t\n");
	printf("\t~~~~~~~~~~~~~~~~~~~\t\n");
	printf("\n\n\n\n\n\t<Enter> to continue");
}

int parsePossibilities(int probabilities[], int arraySize)
{
	int i, total = 0, choice = 0, currentTick = 0, winner = -1;

	//Total all probabilities
	for (i = 0; i < arraySize; i++)
	{
		total += probabilities[i];
	}

	// Select winning number
	choice = rand() % total;

	//Match number with index
	for (i = 0; i < arraySize; i++)
	{
		currentTick += probabilities[i];

		if (choice < currentTick)
		{
			winner = i;
			// printf("winner is %i (value of %i)\n", winner, choice);
			break;
		}
	}
	return winner;
}

char mainMenu()
{
	char menuChoice;
	printf("\n\nWhat do you do?\n");
	printf("A) Go to the ATM\n");
	printf("B) Place a bet and watch the race\n");
	printf("C) QUIT\n");
	printf("Enter a choice: ");
	// get menu choice
	scanf_s( " %c", &menuChoice);
	getchar();	
	return toupper(menuChoice);
}

char atmMenu()
{
	char atmChoice;
	printf("\tATM MENU\n");
	printf("\tA) Get Balance\n");
	printf("\tB) Withdraw\n");
	printf("\tC) Depoisit\n");
	printf("\tD) Return to the track\n");
	printf("\tEnter a choice: ");
	// get menu choice
	scanf_s(" %c", &atmChoice);
	return toupper(atmChoice);
}

double withdraw(double bankBalance)
{
	double withdrawl;
	printf("How much would you like to withdraw : $");
	scanf_s("%lf", &withdrawl);
	getchar();
	if (withdrawl > bankBalance || withdrawl < 0)
	{
		printf("\nThat amount will not work!\n");
		withdrawl = 0;
		return withdrawl;
	}
	else
	{
		return withdrawl;
	}
}

double depositFunc(double walletBalance)
{
	double deposit;
	printf("How much would you like to deposit? $");
	scanf_s("%lf", &deposit);
	if (deposit > walletBalance || deposit < 0)
	{
		printf("\tThat amount will not work!\n");
		deposit = 0;
		return deposit;
	}
	else
	{
		
		return deposit;
	}

}

void theBoard(int payout[], int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		printf("Horse #%2i pays out %2i to 1\n", i + 1, payout[i]);
	}
}

double placeBets(double walletBalance)
{
	double bet;
	printf("You have %.2lf to wager.\nHow much are you betting on the horse?\n", walletBalance);
	printf(">> $");
	scanf_s("%lf", &bet);
	if (bet > walletBalance || bet < 0)
	{
		printf("\nThat amount won't work!\n");
		bet = 0;
		return bet;
	}
	else
	{
		return bet;
	}
}

void runRace()
{
	delay(2);
	system("cls");
	printf("\n\tThey're OFF!");
	delay(2.5);
	system("cls");
	printf("\n\n\tcoming around the bend...");
	delay(2.5);
	system("cls");
	printf("\n\n\n\tIt's a close finish!! AND...\n\n");
}

void delay(double dly) {
	// I have read that this function can have different results on 32 bit vs. 64 bit machines?  Not sure how true that is.
	// save start time
	const time_t start = time(NULL);

	time_t current;
	do {
		// get current time
		time(&current);

		// break loop when the requested number of seconds have elapsed
	} while (difftime(current, start) < dly);
}
