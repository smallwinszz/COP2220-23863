// menuMath.c
// COP2220C-23863
//Prof. Hunchuck
//Chris Marquis 1/21/17

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void getIntegers(double *num1);
void displaySum(double a, double b, double c);
void displayProduct(double a, double b, double c);
void displayAverage(double a, double b, double c);
void displayLowest(double a, double b, double c);

int main()
{
	double int1 =0, int2 = 0, int3 = 0;
	int menuChoice;
	int finish = 0;
	char checkCorrect;

	do
	{
		printf("\n..oo00 Please choose by number from the following menu. 00oo..\n");
		printf("\t1) Enter three Integers between 0 and 1000000\n");
		printf("\t2) Display the sum\n");
		printf("\t3) Display the product\n");
		printf("\t4) Display the average\n");
		printf("\t5) Display the lowest of the three\n");
		printf("\t6) QUIT\n");
		printf(">>");
		scanf_s("%i", &menuChoice);

		switch (menuChoice)
		{
			case 1:
			{
				getchar();  //Need to clear the stdin, since scanf has left a \n.  
				printf("Enter the first integer:");
				getIntegers(&int1);
				printf("Enter the second integer:");
				getIntegers(&int2);
				printf("Enter the third integer:");
				getIntegers(&int3);
				//Tried to figure this out with recursion, but got bogged down pretty bad.
				printf("So, thats %.0lf, %.0lf, and %.0lf\n", int1, int2, int3);
				printf("Do these numbers look OK? (Y / N)\n");
				checkCorrect = getchar();
				if (toupper(checkCorrect) == 'Y')
				printf("Great, now you can operate on them, or renenter them at any time.\n");
				else
				{
					int1 = 0;
					int2 = 0;
					int3 = 0;
					printf("Returning to main menu, please try again...\n");
				} 
				break;
			}
			case 2:
			{
				displaySum(int1, int2, int3);
				break;
			}
			case 3:
			{
				displayProduct(int1, int2, int3);
				break;
			}
			case 4:
			{
				displayAverage(int1, int2, int3);
				break;

			}
			case 5:
			{
				displayLowest(int1, int2, int3);
				break;
			}
			case 6:
			{
				finish = 1;
			}
			default:
			{
				printf("This is not a valid entry, please try again.");
				break;
			}
		}
	} while (finish == 0);
	getchar();
}

void getIntegers(double *num1)
{
	char buffer[BUFSIZ];
	char *p;
	double number = 0;
	int continueInput = 1;

	do
	{
		// By error handling, I think you might have meant errno stuff?  I looked at it but I am not sure how to use it.
		// Otherwise, I have done some error checking for valid numbers, to exclude all characters.  
		if (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			number = strtod(buffer, &p);
			if (buffer[0] != '\n' && (*p == '\n' || *p == '\0'))
			{
				if (number >= 0 && number <= 1000000)
				{
					*num1 = number;
					continueInput = 0;
				}
				else //This prints out for a number out of range.
				{
					printf("Please enter an integer between 1 and a million.(oor)\n");
					continueInput = 1;
				}
			}
			// Prints out for a not a number error.
			else
			{
				printf("Error, please try again.(nan)\n");
				continueInput = 1;
			}
		}
		//Prints out if the error is a NULL return.  Cannot figure out how to return NULL, but the examples I found suggests this catch.
		else
		{
			printf("Error, please try again(nul)\n");
			continueInput = 1;
		}
	} while (continueInput == 1);
} 

void displaySum(double a, double b, double c)
{
	double answer;
	answer = (a + b + c);
	printf("The SUM is %.0lf", answer);
}

void displayProduct(double a, double b, double c)
{
	double answer;
	answer = (a * b * c);
	printf("The PRODUCT is %.0lf", answer);
}

void displayAverage(double a, double b, double c)
{
	double answer;
	answer = ((a + b + c)/3);
	printf("The AVERAGE is %.0lf", answer);
}

void displayLowest(double a, double b, double c)
{
	double answer;
	answer = a;
	if (b < a) answer = b;
	if (c < b) answer = c;
	printf("The LOWEST is %.0lf", answer);
};
