// Dylan Parson, Kyle Sizemore, Frank Rodriquez, Chris Marquis
// Prof Hunchuck
// COP2220C-23863
// tonyandtheponies.c
// assignment 5
// FEB 5 2017

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Function list
void title();
int parsePossibilities(int probabilities[], int arraySize);
char mainMenu();
char atmMenu();
float withdraw(float*, float*);
float depositFunc(float*, float*);
void theBoard(int payout[], int arraySize);
float placeBets(float walletBalance);
void runRace();
void delay(double dly);

int main()
{
	// Variables declared
	char mainChoice, atmChoice;
	float walletBalance = 0, bankBalance = 300, bet;
	// Can also be accompished with a single 2D array?
	int horses[] = { 30, 10, 8, 6, 2, 4, 8, 10, 22 };
	// Looked for an algorithm for relationship between payouts and calculated odds? I did not have much luck.
	int payout[] = { 2 , 5, 10, 15, 50, 20, 10, 5, 3 };
	int pastWinners[] = { 0 };
	int contProgram = 1, contATM, winner, hopeful, raceNum = 0;

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
							withdraw(&bankBalance, &walletBalance);
							break;
						}
						case 'C': // deposit $
						{
							depositFunc(&bankBalance, &walletBalance);
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
					printf("OK, $%.2f on horse %i...", bet, hopeful);
					//Run the race
					runRace();
					// Calculate the winner
					winner = parsePossibilities(horses, 9);
					pastWinners[raceNum] = (winner + 1);
					++raceNum;
					if (winner + 1 == hopeful)
					{
						printf("You won!!\n\n");
						delay(2);
						walletBalance += (bet * payout[winner]);
						printf("\tHorse %i is the winner at %i-1 odds! Your payout is %.2f\n", winner + 1,payout[winner], (bet * payout[winner]));
						printf("You have $%.2f in your wallet now.", walletBalance);
					}
					else
					{
						printf("You lost!\n\n");
						delay(2);
						walletBalance -= bet;
						printf("\tHorse %i lost.  You now have $%.2f in your wallet", hopeful, walletBalance);
					}
					break;
				}
				else
				{
					printf("You need to go to the ATM and take out some $");
					break;
				}
			}
			case 'C': // Display past winners
			{

			}
			case 'D': // QUIT
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
	printf("C) Display past winners\n");
	printf("D) QUIT\n");
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

float withdraw(float *bankBalance, float* walletBalance)
{
	float withdrawl;
	printf("How much would you like to withdraw : $");
	scanf_s("%f", &withdrawl);
	getchar();
	if (withdrawl > *bankBalance || withdrawl < 0)
	{
		printf("\nThat amount will not work!\n");
	}
	else
	{
		*bankBalance -= withdrawl;
		*walletBalance += withdrawl;
	}
	printf("\n\tWallet Balance: $%.2f\n", *walletBalance);
	printf("\n\tBank Balance: $%.2f\n", *bankBalance);
}

float depositFunc(float* bankBalance, float* walletBalance)
{
	float deposit;
	printf("How much would you like to deposit? $");
	scanf_s("%f", &deposit);
	if (deposit > *walletBalance || deposit < 0)
	{
		printf("\tThat amount will not work!\n");
	}
	else
	{
		*walletBalance -= deposit;
		*bankBalance += deposit;
	}

}

void theBoard(int payout[], int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		printf("Horse #%2i pays out %2i to 1\n", i + 1, payout[i]);
	}
}

float placeBets(float walletBalance)
{
	float bet;
	printf("You have %.2f to wager.\nHow much are you betting on the horse?\n", walletBalance);
	printf(">> $");
	scanf_s("%f", &bet);
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
