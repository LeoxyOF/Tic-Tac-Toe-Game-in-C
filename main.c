#include "Tic_tac_toe.c"


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
