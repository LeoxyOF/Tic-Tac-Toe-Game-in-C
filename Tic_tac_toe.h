#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void ChooseFirstPlayer(char Players[2]);
void Display(char Placements[3][3]);
char CheckWin(char Placements[3][3], char Players[2]);
void GetPlayerResponse(char Placements[3][3], char Players[2], char PlayersScore[2]);

#endif