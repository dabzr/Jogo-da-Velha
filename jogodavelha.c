#include <stdio.h>
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
    int number;
    if (n[1]==test[3]){number = 1;}
    else if (n[1]==test[4]){number = 2;}
    else if (n[1]==test[5]){number = 3;}
    else {
        number = 4;
        return 9;}
    if ((number < 4) && (number > 0)){
        if ((n[0] != test[0]) && (n[0] != test[1]) && (n[0] != test[2])){return 9;}
        else{
            if ((n[1] != test[3]) && (n[1] != test[4]) && (n[1] != test[5])){return 9;}
            else{
                int temp;
                if (n[0] == test[0]){temp = -1;}
                else if(n[0] == test[1]){temp = 2;}
                else if (n[0] == test[2]){temp = 5;}
                //int temp2 = n[1];
                int position = temp + number;
                if (p[position] != test[6]){return 9;}
                else{return position;}
                }}}
    else{return 9;}}
int main (){
    char XO[3]= "X0";
    char pos[10] = "         ";
    char num[3];
    char space[2] = " ";
    char winner;
    int end = 0;
    int j;
    while(end==0){
        for (j=0;j<2;j++){
            clear();
            int a = 9;
            while (a==9){
                table(pos);
                printf("Jogador %c insira a posição: ", XO[j]);
                scanf("%s", num);
                a = pos_num(num, pos);
               if (a==9){printf("Jogada inválida. Jogue novamente.\n");}
            }
                pos[a] = XO[j] ;
        if ((pos[0] == pos[1]) && (pos[1] == pos[2]) && (pos[0] != space[0])) {end = 1;winner = pos[0];break;}
        else if ((pos[3] == pos[4]) && (pos[4] == pos[5]) && (pos[3] != space[0])) {end = 1;winner = pos[3];break;}
        else if ((pos[6] == pos[7]) && (pos[7] == pos[8]) && (pos[6] != space[0])) {end = 1;winner = pos[6];break;}
        else if ((pos[0] == pos[3]) && (pos[3] == pos[6]) && (pos[6] != space[0])){end = 1;winner = pos[6];break;}
        else if ((pos[1] == pos[4]) && (pos[4] == pos[7]) && (pos[7] != space[0])){end = 1;winner = pos[7];break;}
        else if ((pos[2] == pos[5]) && (pos[5] == pos[8]) && (pos[8] != space[0])){end = 1;winner = pos[8];break;}
        else if ((pos[0] == pos[4]) && (pos[4] == pos[8]) && (pos[0] != space[0])){end = 1;winner = pos[0];break;}
        else if ((pos[2] == pos[4]) && (pos[4] == pos[6]) && (pos[2] != space[0])){end = 1;winner = pos[2];break;}
        else if ((pos[0] != space[0]) && (pos[1] != space[0]) && (pos[2] != space[0]) && (pos[3] != space[0]) && (pos[4] != space[0]) && (pos[5] != space[0]) && (pos[6] != space[0]) && (pos[7] != space[0]) && (pos[8] != space[0]))
        {end = 2;break;}
            }    
    }
    clear();
    if (end == 1){
        table(pos);
        printf("Fim de jogo! O vencedor foi o %c.\n", winner);}
    else{
        table(pos);
        printf("Fim de jogo! Empate!\n");}
}
