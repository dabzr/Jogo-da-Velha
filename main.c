#include <stdio.h>
#include "jogodavelha.h"

int main (){
    const char XO[3]= "X0";
    char pos[10] = "         ";
    char winner = ' ';
    while(winner==' '){
        for (int j=0;j<2;j++){
            clear();
            UpdatePosition(pos, XO[j]);
            winner = VerifyWinner(pos);
            if (winner != ' ') {break;}
        }
    }
    clear();
    table(pos);
    (winner == 'E') ? printf("Fim de jogo! Empate!\n") : printf("Fim de jogo! O vencedor foi o %c.\n", winner);
}
