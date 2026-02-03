#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void ChooseFirstPlayer(char Players[2]){
    int FirstPlayer = rand() % 2;
    printf("The first player is %c\n", (FirstPlayer == 0) ? 'O' : 'X');
    if(FirstPlayer == 0){
        Players[0] = 'O';
        Players[1] = 'X';
    }
    else{
        Players[0] = 'X';
        Players[1] = 'O';
    }

    for(int i = 0; i < 2; i++){
        printf("Player %d: %c\n", i+1, Players[i]);
    }
}

void Display(char Placements[3][3]){
    
    printf("\n  %c    |      %c      |    %c   \n"
          "-------|-------------|------- \n"
          "       |             |      \n"
          "  %c    |      %c      |    %c   \n"
          "       |             |      \n"
          "-------|-------------|------- \n"
          "       |             |      \n"
          "  %c    |      %c      |    %c     \n",
          Placements[0][0], Placements[0][1], Placements[0][2],
          Placements[1][0], Placements[1][1], Placements[1][2],
          Placements[2][0], Placements[2][1], Placements[2][2]
    );
}

char CheckWin(char Placements[3][3], char Players[2]){
    char P1_C = Players[0];
    char P2_C = Players[1];
    char Winner = '\0';

    // Checking Horizontal
    for(int j = 0; j < 3; j++){
        int P1 = 0;
        int P2 = 0;
        for(int i = 0; i < 3; i++){  
            if(Placements[j][i] == P1_C){
                P1+=1;
            }
            else if(Placements[j][i] == P2_C){
                P2+=1;
            }
        if(P1 == 3){
            Winner = P1_C;
            break;
        }
        else if(P2 == 3){
            Winner = P2_C;
            break;
        
        }
      }
    }

    // Checking Vertical
    for(int j = 0; j < 3; j++){
        int P1 = 0;
        int P2 = 0;
        for(int i = 0; i < 3; i++){  
            if(Placements[i][j] == P1_C){
                P1+=1;
            }
            else if(Placements[i][j] == P2_C){
                P2+=1;
            }
        if(P1 == 3){
            Winner = P1_C;
            break;
        }
        else if(P2 == 3){
            Winner = P2_C;
            break;
        
        }
      }
    }

    // Checking Diagonal Left -> Right
    int P1 = 0;
    int P2 = 0;
    for(int i = 0; i < 3; i++){
        if(Placements[i][i] == P1_C){
            P1+=1;
        }
        else if(Placements[i][i] == P2_C){
            P2+=1;
        }       
        if(P1 == 3){
            Winner = P1_C;
            break;
        }
        else if(P2 == 3){
            Winner = P2_C;
            break;
        
        }
    }

    // Checking Diagonal Right -> Left
    if(Placements[0][2] == P1_C && Placements[1][1] == P1_C && P1_C == Placements[2][0]){
        Winner = P1_C;
    }
    else if(Placements[0][2] == P2_C && Placements[1][1] == P2_C && P2_C == Placements[2][0]){
        Winner = P2_C;
    }       

    if(Winner != '\0'){
        return Winner;
    }
    else{
        return 'C'; // C from Continue
    }

}

void GetPlayerResponse(char Placements[3][3], char Players[2], char PlayersScore[2]){
char GameWinner = '\0';
int CheckDraw = 0;
    while(true){

        for(int i = 0; i < 2; i++){

            int RowChoice = 0;
            int ColumnChoice = 0;
            bool CheckPosition = false;
            bool CheckValidity = false;

            while(CheckPosition == false || CheckValidity == false){
                printf("\n--- Player %c ---\n", Players[i]);
                printf("Row: ");
                scanf("%d", &RowChoice);
                RowChoice-=1;

                printf("Column: ");
                scanf("%d", &ColumnChoice);
                ColumnChoice-=1;

                if(RowChoice < 0 || RowChoice > 2 || ColumnChoice < 0 || ColumnChoice > 2){
                    printf("\nEnter a Valid Response!\n");
                    CheckValidity = false;
                    continue;
                }
                else{
                    CheckValidity = true;
                }

                if(Placements[RowChoice][ColumnChoice] == 'X' || Placements[RowChoice][ColumnChoice] == 'O'){
                    printf("\nThis position is already taken!\n");
                    CheckPosition = false;
                }
                else{
                    Placements[RowChoice][ColumnChoice] = Players[i];
                    CheckPosition = true;
                    CheckDraw+=1;
                }

            }

            Display(Placements);
            GameWinner = CheckWin(Placements, Players);

            if (GameWinner != 'C'){
                PlayersScore[i] +=1;
                if(PlayersScore[1] > PlayersScore[0]){

                    int tempScore = PlayersScore[0];
                    PlayersScore[0] = PlayersScore[1];
                    PlayersScore[1] = tempScore;

                    int tempPlayer = Players[0];
                    Players[0] = Players[1];
                    Players[1] = tempPlayer;

                }
                printf("\n----> %c Won! <----\n", GameWinner);
                return;
            }
            else if(CheckDraw == 9){
                printf("\nIt's a Tie!\n");
                return;
            }
        }
    }
}

int main(){

    srand(time(NULL));

    char Players[2] = {' ',' '};
    char PlayersScore[2] = {0, 0};

    int Continue = 0;

    printf("----- Welcome to Tic Tac Toe! -----\n");
    ChooseFirstPlayer(Players);

    do{
    char Placements[3][3] = {{' ',' ',' '},
                             {' ',' ',' '},
                             {' ',' ',' '}};
    Display(Placements);    
    GetPlayerResponse(Placements, Players, PlayersScore);
    printf("\nPlayer %c: %d", Players[0], PlayersScore[0]);
    printf("\nPlayer %c: %d\n", Players[1], PlayersScore[1]);
    printf("\n1 - Continue Playing\n2 - Exit\n");

        do {

        printf("\nEnter an option: ");
        scanf(" %d", &Continue);
        if(Continue != 1 && Continue != 2){
            printf("\nEnter a valid option!\n");
        }

        } while(Continue != 1 && Continue != 2);

    } while(Continue != 2);

    return 0;
}