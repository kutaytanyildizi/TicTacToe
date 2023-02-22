#include <stdio.h>
#include <stdbool.h>

void printGameInfo(void);
void gameScreen(char Arr[3][3]);
bool controlChoice(char choice);
char getChoice(int counter);
void playOnBoard(int counter, char choice, char gameArr[3][3]);
bool checkForWin(char gameArr[3][3]);


int main()
{   
    int counter = 0;
    int cnt;
    char choice;
    bool gameStatus = false;
    char gameArr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    while(gameStatus == false)
    {
        printf("\e[1;1H\e[2J");
        printGameInfo();    
        gameScreen(gameArr);
        choice = getChoice(counter);
        playOnBoard(counter, choice, gameArr);
        gameStatus = checkForWin(gameArr);
        counter++;
    }
    printf("\e[1;1H\e[2J");
    printGameInfo();    
    gameScreen(gameArr);
    return 0;
}

bool checkForWin(char gameArr[3][3])
{
    if(gameArr[0][0] == gameArr[0][1] && gameArr[0][0] == gameArr[0][2])
    {
        return true;
    }
    else if(gameArr[0][0] == gameArr[1][0] && gameArr[0][0] == gameArr[2][0])
    {
        return true;
    }
    else if(gameArr[0][0] == gameArr[1][1] && gameArr[0][0] == gameArr[2][2])
    {
        return true;
    }
    else if(gameArr[0][1] == gameArr[1][1] && gameArr[0][1] == gameArr[2][1])
    {
        return true;
    }
    else if(gameArr[0][2] == gameArr[1][2] && gameArr[0][2] == gameArr[2][2])
    {
        return true;
    }
    else if(gameArr[1][0] == gameArr[1][1] && gameArr[1][0] == gameArr[1][2])
    {
        return true;
    }
    else if(gameArr[0][2] == gameArr[1][1] && gameArr[0][2] == gameArr[2][0])
    {
        return true;
    }
    else if(gameArr[2][0] == gameArr[2][1] && gameArr[2][0] == gameArr[2][2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printGameInfo(void)
{   
    printf("          Tic Tac Toe\n");
    printf("\nPlayer 1 (X)   -   Player 2 (Y)\n");
}

void gameScreen(char Arr[3][3])
{
    printf("             |   |   \n");
    printf("           %c | %c | %c \n" , Arr[0][0] , Arr[0][1], Arr[0][2]);
    printf("          ___|___|___\n");
    printf("             |   |   \n");
    printf("           %c | %c | %c \n" , Arr[1][0] , Arr[1][1] , Arr[1][2]);
    printf("          ___|___|___\n");
    printf("             |   |   \n");
    printf("           %c | %c | %c \n" , Arr[2][0] , Arr[2][1] , Arr[2][2]);
    printf("             |   |   \n");
}

void playOnBoard(int counter, char choice, char gameArr[3][3])
{
    if(counter % 2 == 0)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(choice == gameArr[i][j])
                {
                    gameArr[i][j] = 'X';
                }
            }
        }
    }
    else if(counter % 2 != 0)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(choice == gameArr[i][j])
                {
                    gameArr[i][j] = 'O';
                }
            }
        }
    }
}

char getChoice(int counter) 
{
    char choice = 'S';
    int cnt = 0;

    while(!(controlChoice(choice)))
    {
        if(cnt != 0)
        {
            if(counter % 2 == 0)
            {
                printf("Player 1 entered an invalid value.\n");
            }
            else if(counter % 2 != 0)
            {
                printf("Player 2 entered an invalid value.\n");
            }
        }
        if(counter % 2 == 0)
        {
            printf("Player 1, enter a number: ");
        }
        else if(counter % 2 != 0)
        {
            printf("Player 2, enter a number: ");
        }

        scanf("%c" , &choice);
        cnt = cnt + 1; 
    }
    return choice;
}

bool controlChoice(char choice)
{
    if((choice <= '9' && '0' <= choice))
    {
        return true;
    }
    
    return false;
}
