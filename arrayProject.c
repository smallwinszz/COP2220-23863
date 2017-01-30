// Chris Marquis
// Prof Hunchuck
// COP 2220C
// 1/26/17
// arrayProject.c

#define RECORDS 1000
#define SCORES 2

#include <stdio.h>
#include <ctype.h>

void mainMenu();

int main()
{
	int gameRecord[RECORDS][SCORES] = { { 0 } };
	int recordNum = 0, myTeamscore = 0, opponentScore = 0, i, contProg = 1;
	char select, checkInput;

	while (contProg == 1)
	{
		mainMenu();
		scanf_s("%c", &select);

		switch (toupper(select))
		{
			case 'A': // ENTER A GAME RECORD
			{
				if (recordNum < RECORDS)
				{
					
					printf("Please enter game record #%i\n", recordNum + 1);
					printf("Score for our Heroes: ");
					scanf_s("%i", &myTeamscore);
					gameRecord[recordNum][0] = myTeamscore;
					printf("Score for the Opponent: ");
					scanf_s("%i", &opponentScore);
					gameRecord[recordNum][1] = opponentScore;
					printf("Match %i was\n\tUS:   %i\n\tTHEM: %i\n", recordNum + 1, myTeamscore, opponentScore);
					// The array is updated and we check with the user to verify to "save" it.
					printf("Does this look OK? (Y/N)");
					scanf_s(" %c", &checkInput);
					getchar();
					if (toupper(checkInput) == 'Y')
					{
						++recordNum; 
						// Without increment, the rest of the program will not see the record. It will be overwritten with the next entry
						break;
					}
					else
					{
						printf("\n\nOK, that entry is not counted.\n\n");
						break;
					}
				} 
				else
				{
					printf("\n\nMAXIMUM NUMBER of GAMES INPUT!\n\n");
					getchar();
					break;
				}
			}
			case 'B': // CURRENT WINS/LOSSES
			{
				int wins = 0, losses = 0, ties = 0;
				for (i = 0; i < recordNum; i++)
				{
					if (gameRecord[i][0] > gameRecord[i][1])
					{
						++wins;
					}
					else if (gameRecord[i][0] < gameRecord[i][1])
					{
						++losses;
					}
					else
					{
						++ties;
					}
				}
				printf("WINS:   %i\n", wins);
				printf("LOSSES: %i\n", losses);
				if (ties > 0) // Included a case for ties
				{
					printf("TIED: %i\n", ties);
				}
				getchar();
				break;
			}
			case 'C': // GAMES WON
			{
				for (i = 0; i < recordNum; i++)
				{
					if (gameRecord[i][0] > gameRecord[i][1])
					{
						printf("We WON game %i! US:%3i THEM:%3i\n", i + 1, gameRecord[i][0], gameRecord[i][1]);
					}
				}
				getchar();
				break;
			}
			case 'D': // ALL GAMES
			{
				for (i = 0; i < recordNum; i++)
				{
					printf("Game %i US:%3i THEM: %3i\n", i + 1, gameRecord[i][0], gameRecord[i][1]);
				}
				getchar();
				break;
			}
			case 'E': //QUIT
			{
				contProg = 0;
				break;
			}
			default:
			{
				printf("\nINVALID SELECTION\n");
				getchar();
			}
		}  //END switch
	} //END while for progCont
} //END main

void mainMenu()
{
	printf("\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.\n");
	printf("\t Game Time Main Menu \t  please select by letter\n");
	printf("\t *.*.*.*.*.*.*.*.*.*. \t  *.*.*.*.*.*.*.*.*.*.*.*.\n");
	printf("\t A) Enter game results\n");
	printf("\t B) Current Record (# of wins and # of losses)\n");
	printf("\t C) Display ALL results from all games WON\n");
	printf("\t D) Display ALL results\n");
	printf("\t E) Quit\n");
	printf("\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.\n");
	printf(">> ");
}
