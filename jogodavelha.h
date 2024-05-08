#include <stdio.h>
#include <stdlib.h>

#define INVALID_POS 9
void clear();
void table(char p[10]);
int pos_num(char n[3], char p[10]);
char VerifyWinner(char pos[10]);
void UpdatePosition(char pos[10], char XO);
