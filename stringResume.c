//Chris Marquis
// COP 2220 - C
// Prof Hunchuk
// string2.c
// FEB 8, 2017
// resume assignment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void getKeywords(char keyWords[][15]);
void getResumeWords(char resumeWords[][30]);
void compareWords(char keyWords[][15], char resumeWords[][30], int matched[][1]);
void outputMatches(int matched[][1], char keyWords[][15]);
void charsKeyToupper(char keyWords[][15]);
void charsResumeToupper(char resumeWords[][30]);
void printKeywords(char keyWords[][15]);
void printResumewords(char resumeWords[][30]);

int main()
{
	char keyWords[51][15] = { { 0 } };
	char resumeWords[2001][30] = { { 0 } };
	int matched[51][1] = { { 0 } };

	getKeywords(keyWords);

	getResumeWords(resumeWords);

	charsKeyToupper(keyWords);

	charsResumeToupper(resumeWords);

	compareWords(keyWords, resumeWords, matched);

	outputMatches(matched, keyWords);

	// printKeywords(keyWords);

	// printResumewords(resumeWords);
	
	system("pause");
}

void getKeywords(char keyWords[][15])
{
	//keywords should be saved in a comma seperated txt file.
	FILE *keywordsFile = fopen("C:/files/sampleKeywords.txt", "r");
	char buffer[750] = { 0 } ;

	char *token;
	int i = 0;

	fread(buffer, sizeof(char), 999, keywordsFile);
	// With C on OS X I can use strsep to acheive a very similar effect to strtok, but I do not have to set the token to NULL between passes.
	// Using stktok is an example of swap in place?
	token = strtok(buffer, ",");

	while (token != NULL)
	{
		//Parsed words are stored in the working array
		strcpy(keyWords[i], token);
		token = strtok(NULL, ",\n");
		++i;
	}
	fclose(keywordsFile);
}

void getResumeWords(char resumeWords[][30])
{
	FILE *resumeFile = fopen("C:/files/sampleResume2.txt", "r");
	char bufferTwo[5000] = { 0 };

	char *token;
	int i = 0;

	fread(bufferTwo, sizeof(char), 5000, resumeFile);
	token = strtok(bufferTwo, ",\n:- \(\)@");

	while (token != NULL)
	{
		//Parsed words are stored in the working array
		strcpy(resumeWords[i], token);
		token = strtok(NULL, ",\n:- \)\(@");
		++i;
	}
	fclose(resumeFile);
}

void charsKeyToupper(char keyWords[][15])
{
	for (int i = 0; i < 50; i++)
	{
		for (int h = 0; h < 15; h++)
		{
			keyWords[i][h] = toupper(keyWords[i][h]);
		}
	}
}

void charsResumeToupper(char resumeWords[][30])
{
	for (int i = 0; i < 800; i++)
	{
		for (int h = 0; h < 30; h++)
		{
			resumeWords[i][h] = toupper(resumeWords[i][h]);
		}
	}
}

void compareWords(char keyWords[][15], char resumeWords[][30], int matched[][1])
{
	//This function compares the words and returns the list of matched words
	int compare;
	int a;

	for (int i = 0; i < 50; i++)
	{
		a = 0;
		for (int h = 0; h < 400; h++)
		{
			compare = strcmp(keyWords[i], resumeWords[h]);
			if (compare == 0)
			{
				a++;
				matched[i][0] = a;
			}
		}
	}
}

void outputMatches(int matched[][1], char keyWords[][15])
{
	for (int g = 0; g < 50; g++)
	{
		if (matched[g][0] > 0)
		{
			printf("%-20s has %i matches\n\n", keyWords[g], matched[g][0]);
		}
	}
}

void printKeywords(char keyWords[][15])
{
	for (int i = 0; i < 50; i++)
	{
		printf("%i) %s\n", i, keyWords[i]);
	}
}

void printResumewords(char resumeWords[][30])
{
	for (int i = 0; i < 800; i++)
	{
		printf("%i=%s  ", i, resumeWords[i]);
	}
}
