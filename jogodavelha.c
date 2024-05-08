#include <stdio.h>
#include <stdlib.h>

#define INVALID_POS 9

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
void table(char p[10]){
    printf("  1   2   3\nA %c | %c | %c\n  -----------\nB %c | %c | %c\n  -----------\nC %c | %c | %c\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]);
}
int pos_num(char n[3], char p[10]){
    char test[8] = "abc123 ";
    int number = 4, temp;
    for (int i = 1; i < 4; i++) {
        if(n[1]==test[i+2]) {number = i;break;}
    }
    if (number==4) {return INVALID_POS;}
    if (!((number < 4) && (number > 0))){return INVALID_POS;}
    if ((n[0] != test[0]) && (n[0] != test[1]) && (n[0] != test[2])){return INVALID_POS;}
    if ((n[1] != test[3]) && (n[1] != test[4]) && (n[1] != test[5])){return INVALID_POS;}
    if (n[0] == test[0]){temp = -1;}
    else if(n[0] == test[1]){temp = 2;}
    else if (n[0] == test[2]){temp = 5;}
    int position = temp + number;
    if (p[position] != test[6]){return INVALID_POS;}
    return position;
}
char VerifyWinner(char pos[10]){
    if ((pos[0] == pos[1]) && (pos[1] == pos[2]) && (pos[0] != ' ')) {return pos[0];}
    if ((pos[3] == pos[4]) && (pos[4] == pos[5]) && (pos[3] != ' ')) {return pos[3];}
    if ((pos[6] == pos[7]) && (pos[7] == pos[8]) && (pos[6] != ' ')) {return pos[6];}
    if ((pos[0] == pos[3]) && (pos[3] == pos[6]) && (pos[6] != ' ')) {return pos[6];}
    if ((pos[1] == pos[4]) && (pos[4] == pos[7]) && (pos[7] != ' ')) {return pos[7];}
    if ((pos[2] == pos[5]) && (pos[5] == pos[8]) && (pos[8] != ' ')) {return pos[8];}
    if ((pos[0] == pos[4]) && (pos[4] == pos[8]) && (pos[0] != ' ')) {return pos[0];}
    if ((pos[2] == pos[4]) && (pos[4] == pos[6]) && (pos[2] != ' ')) {return pos[2];}
    int count = 0;
    for (int i = 0; i < 9; i++)
      if (pos[i] != ' ') {count++;}

    return (count == 9) ? 'E' : ' ';
}
void UpdatePosition(char pos[10], char XO) {
    char num[3];
    int a = INVALID_POS;
    while (a==INVALID_POS){
        table(pos);
        printf("Jogador %c insira a posição: ", XO);
        scanf("%2s", num);
        a = pos_num(num, pos);
        if (a==INVALID_POS){printf("Jogada inválida. Jogue novamente.\n");}
    }
    pos[a] = XO;
} 
int main (){
    char XO[3]= "X0";
    char pos[10] = "         ";
    char num[3];
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
