//  carSales.c
//  COP_2220C-23863
//  Prof. HUNCHUCK
//  Chris Marquis 1/9/17

#include <stdio.h>
#include <ctype.h>

double enterNewSale();
double monthDiscount(double monthDisc);
double firstBuyDiscount(double firstBuyDisc);
double studentDiscountYESfirst(double studentYDisc);
double studentDiscountNOfirst(double studentNDisc);
double vetDiscount(double vetDisc);

int main()
{
	int menuChoice, totalNumSold = 0;
	double avgPrice = 0, totalRevenue = 0, newSale = 0;

	while (totalNumSold <= 50000)
	{
		printf("Please choose from the following menu:\n");
		printf("1) Enter a NEW car sale\n");
		printf("2) Total cars sold\n");
		printf("3) Average car sold price\n");
		printf("4) Total revenue collected\n");
		printf("5) EXIT\n");
		printf(">> ");
		scanf_s("%i", &menuChoice);
		switch (menuChoice)
		{
		case 1:
		{
			newSale = enterNewSale();

			if (newSale == 0) break;

			newSale = monthDiscount(newSale);
			newSale = firstBuyDiscount(newSale);
			//The student discount function is called inside the first buyer function.
			newSale = vetDiscount(newSale);

			//If there is an entry, all updates are handled here.
			if (newSale > 0)
			{
				++totalNumSold;
				totalRevenue += newSale;
				avgPrice = (totalRevenue / totalNumSold);
			}
			else printf("\nThere seems to be an error, we won't count this one!\n\n");
			break;
		}
		case 2: // totalNumSold()
			printf("\nTotal number sold is: %i\n", totalNumSold);
			break;
		case 3: // avgPrice()
			printf("\nThe average price is: $%.2lf\n", avgPrice);
			break;
		case 4: // totalRevenue()
			printf("\nThe total revenue so far is: $%.2lf\n", totalRevenue);
			break;
		case 5: // EXIT
		{
			printf("\nThanks for using CARMAXXX\n");
			totalNumSold = 50001;
		}
		}
	}
}

double enterNewSale()
{
	char stickerCheck;
	double stickerPrice;
	printf("What is the Sticker Price you are paying for the car?\n$");
	scanf_s("%lf", &stickerPrice);
	printf("$%.2lf, is this correct?\n(Y/N)", stickerPrice);
	scanf_s(" %c", &stickerCheck);
	if (toupper(stickerCheck) == 'Y')
	{
		return stickerPrice;
	}
	else
	{
		printf("This entry will not be counted.\n");
		return 0;
	}
}


double monthDiscount(double monthDisc)
{
	char monthCheck;
	printf("Is it the last day of the month?\n(Y/N)");
	scanf_s(" %c", &monthCheck);
	if (toupper(monthCheck) == 'Y')
	{
		monthDisc = (monthDisc - (monthDisc * .05));
		printf(">>$%.2lf<<\n", monthDisc);
		return monthDisc;
	}
	else
	{
		return monthDisc;
	}

}

double firstBuyDiscount(double firstBuyDisc)
{
	char firstBuyCheck;
	printf("Is this your first car purchase?\n(Y/N)");
	scanf_s(" %c", &firstBuyCheck);
	if (toupper(firstBuyCheck) == 'Y')
	{
		firstBuyDisc = (firstBuyDisc - 500);
		printf(">>$%.2lf<<\n", firstBuyDisc);
		firstBuyDisc = studentDiscountYESfirst(firstBuyDisc);
		return firstBuyDisc;
	}
	else
	{
		firstBuyDisc = studentDiscountNOfirst(firstBuyDisc);
		return firstBuyDisc;
	}

}

// This function is called from inside the firstBuyDiscount func.
double studentDiscountYESfirst(double studentYDisc)
{
	char studentCheck;
	printf("First time buyer, are you also a student?\n(Y/N)");
	scanf_s(" %c", &studentCheck);
	if (toupper(studentCheck) == 'Y')
	{
		studentYDisc = (studentYDisc - 1200);
		printf(">>$%.2lf<<\n", studentYDisc);
		return studentYDisc;
	}
	else
	{
		studentYDisc = studentYDisc;
		return studentYDisc;
	}

}

// This function is called from inside the firstBuyDiscount func.
double studentDiscountNOfirst(double studentNDisc)
{
	char studentCheck;
	printf("Are you a student?\n(Y/N)");
	scanf_s(" %c", &studentCheck);
	if (toupper(studentCheck) == 'Y')
	{
		studentNDisc = (studentNDisc - 700);
		printf("$>>%.2lf<<\n", studentNDisc);
		return studentNDisc;
	}
	else
	{
		studentNDisc = studentNDisc;
		return studentNDisc;
	}

}

double vetDiscount(double vetDisc)
{
	char vetCheck;
	printf("Are you a veteran?\n(Y/N)");
	scanf_s(" %c", &vetCheck);
	if (toupper(vetCheck) == 'Y')
	{
		vetDisc = (vetDisc - (vetDisc * .01));
		printf("$>>%.2lf<<\n", vetDisc);
		return vetDisc;
	}
	else
	{
		vetDisc = vetDisc;
		return vetDisc;
	}

}

