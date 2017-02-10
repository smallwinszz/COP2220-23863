// Chris Marquis
// COP 2220 - C
// Prof Hunchuk
// Feb 6, 2017



// Cannot use the scanf_s with a literal length in the format specfier.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

void getString(char string[]);
void validateString(char string[], int *contProgram);
void printString(char string[]);
void revString(char string[]);
void printStringVertical(char string[]);
void printTriangleA(char string[]);
void printTriangleB(char string[]);
void printfTriangleC(char string[]);
void contQuestion(int *contProgram);

int main()
{
	char string[SIZE] = { 0 }, ch;
	int contProgram = 1;

	while (contProgram == 1)
	{
		getString(string);

		validateString(string, &contProgram);

		printString(string);

		// The string is evaluated and the length of the string is returned.
		printf("The string length is %i.\n\n\tThis does not count the NULL char at the end of a string.\n\tAn array without the NULL at the end is just an array of chars.\n\n", strlen(string));

		// Alternative string reverse.
		// Not sure if _strrev is acceptable, but it compiled and ran so I left it as a comment.
		// It DOES physically reverse the array, not just print it in reverse.
		// printf("%s is the string reversed.\n", _strrev(string));

		revString(string);

		printf("\nThis is the string reversed.\n\n\t");
		printString(string);

		printf("\nNow let's turn it on its side.\n\n");
		printStringVertical(string);

		revString(string);

		printf("Now some triangles maybe?\n\n");
		printTriangleA(string);

		printTriangleB(string);

		printfTriangleC(string);

		contQuestion(&contProgram);

	}

	system("cls");

	printf("Thank you, come again.\n\n");

	system("pause");


}

void getString(char string[])
{
	printf("Enter a string up to %i characters.\nAny characters over the limit will be discarded.\n>>", SIZE - 1);
	// The fomat specifier is set to 100.  Needs to match (SIZE -1) to avoid faults.
	scanf("%100[^\n]s", string);
	system("cls");
}

void validateString(char string[], int *contProgram)
{
	if (strlen(string) == 0)
	{
		printf("This is not a valid length string, please try again.");
		system("pause");
		getString(string);
	}
}

void printString(char string[])
{
	int h = 0;
	while (string[h] != '\0')
		putchar(string[h++]);
	printf("\n\n");
}

void revString(char string[])
{
	char temp, *end, *start;

	// Find start and stop values
	start = string;
	end = start + strlen(string) - 1;
	
	//reverse. This phsically changes the memory values locations in the string, as opposed to only outputting them backward.
	while (end > start)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		++start;
		--end;
	}
}

void printStringVertical(char string[])
{
		int h = 0;
		printf("\t");
		while (string[h] != '\0')
		{
			putchar(string[h++]);
			printf("\n\t");
		}
		printf("\n");
}

void printTriangleA(char string[])
{
	int g, h;

	printf("This triangle reads left to right and vertically.\n\n");
	for (int g = 0; g < strlen(string); g++)
	{
		printf("\t");
		for (int h = g; h < strlen(string); h++)
		{
			printf("%c", string[h]);
		}
		printf("\n");
	}
	printf("\n");
}

void printTriangleB(char string[])
{
	// ==================================
	//Print Triangle
	//Looking for this.  Can't find the logic.  I have lots of failures though.
	/*
	input: hello
		  l
	   e   l
	h        o
	*/

	printf("Here is an attempt that prints a string in an open triangle pattern\n\n");
	int f = 0, rows = (strlen(string) / 2 + 1);
	int space, ch = 0;

	for (int i = 1; i <= rows; i++)
	{
		printf("\t");
		// Print spaces
		for (space = 1; space <= rows - i; space++)
		{
			printf(" ");
		}
		// Print chars	
		while (ch != (2 * i - 1))
		{
			
			if (ch == 0 || ch == 2 * i - 2)
			{
				printf("%c", string[f]);
				++f;
			}
			else
				printf(" ");
			ch++;
		}
		ch = 0;
		// move to next row
		printf("\n");
	}
}

void printfTriangleC(char string[])
{
	int length = strlen(string);

	printf("\nThis triangle is made using printf format specifiers.\n");
	for (int i = 0; i <= length; ++i)
	{
		printf("\t%.*s\n", i, string);
	}
	printf("\n");
}

void contQuestion(int *contProgram)
{
	char answer;
	printf("\n\nWould you like to enter another string? (Y/N)\n>> ");
	scanf(" %c", &answer);
	getchar();
	if (toupper(answer) == 'Y')
	{
		*contProgram = 1;
		system("cls");
		return;
	}
	if (toupper(answer) == 'N')
	{
		*contProgram = 0;
		return;
	}
	else
	{
		printf("\nInvalid entry\n");
		*contProgram = 1;
		return;
	}
}

/*
Write a program that will read in a string up to 100 characters.

The program will then display the following :
*The String DONE
* The String Reversed DONE
* The Length of the String DONE
* The String written vertical DONE
* The string written as a triangle DONE

* The program will allow the user to do all above again or quit.
* Remember to turn in your code and design tool
*/
