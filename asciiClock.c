#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


char* timeToString(hr,min,sec){
    char *str = malloc(8);
    str[0] = (hr/10)+'0';
    str[1] = hr%10 +'0';
    str[2] = ':';
    str[3] = (min/10)+'0';
    str[4] = min%10 +'0';
    str[5] = ':'; 
    str[6] = (sec/10)+'0';
    str[7] = sec%10 +'0';
    return str;
}

char one[5][5] = {
            {' ', ' ', '/', ' ',' '},
            {' ', '/', '|', ' ',' '},
            {' ', ' ', '|', ' ',' '},
            {' ', ' ', '|', ' ',' '},
            {' ', '-', '-', '-',' '}};
char two[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', ' ',' '},
            {' ', '-', '-', '-',' '}};
char three[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', '-', '-', '|',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', '-', '-', '-',' '}};
char four[5][5] = {
            {' ', '|', ' ', '|',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '-', '-', '|',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', ' ', ' ', '|',' '}};
char five[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', ' ',' '},
            {' ', '-', '-', '-',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', '-', '-', '-',' '}};
char six[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', ' ',' '},
            {' ', '|', '-', '-',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '-', '-', '-',' '}};
char seven[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', ' ', ' ', '/',' '},
            {' ', ' ', '/', ' ',' '},
            {' ', '/', ' ', ' ',' '}};
char eight[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '|', '-', '|',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '-', '-', '-',' '}};
char nine[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '-', '-', '|',' '},
            {' ', ' ', ' ', '|',' '},
            {' ', ' ', ' ', '|',' '}};
char zero[5][5] = {
            {' ', '-', '-', '-',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '|', ' ', '|',' '},
            {' ', '-', '-', '-',' '}};
char coll[5][5] = {
            {' ', ' ', '*', ' ',' '},
            {' ', ' ', '*', ' ',' '},
            {' ', ' ', '*', ' ',' '},
            {' ', ' ', '*', ' ',' '},
            {' ', ' ', '*', ' ',' '}};

void stringToAscii(char str[8], char out[5][41]){
    for(int row = 0; row < 5; row += 1){
        for(int col = 0; col < 40; col += 1){
            switch (str[col/5]) {
            case '1':
                out[row][col] = one[row][col%5];
                break;
            case '2':
                out[row][col] = two[row][col%5];
                break;
            case '3':
                out[row][col] = three[row][col%5];
                break;
            case '4':
                out[row][col] = four[row][col%5];
                break;
            case '5':
                out[row][col] = five[row][col%5];
                break;
            case '6':
                out[row][col] = six[row][col%5];
                break;
            case '7':
                out[row][col] = seven[row][col%5];
                break;
            case '8':
                out[row][col] = eight[row][col%5];
                break;
            case '9':
                out[row][col] = nine[row][col%5];
                break;
            case '0':
                out[row][col] = zero[row][col%5];
                break;
            default:
                out[row][col] = coll[row][col%5];
                break;
            }
        }
    }
}
/*
case '1':
                printf(one[row][col%5]);
                break;
            case '2':
                printf(two[row][col%5]);
                break;
            case '3':
                printf(three[row][col%5]);
                break;
            case '4':
                printf(four[row][col%5]);
                break;
            case '5':
                printf(five[row][col%5]);
                break;
            case '6':
                printf(six[row][col%5]);
                break;
            case '7':
                printf(seven[row][col%5]);
                break;
            case '8':
                printf(eight[row][col%5]);
                break;
            case '9':
                printf(nine[row][col%5]);
                break;
            case '0':
                printf(zero[row][col%5]);
                break;
            default:
                printf
*/

int main(int argc, char *argv[]) {
    int hr = 0;
    int min = 0;
    int sec = 0;
    time_t curtime;
    struct tm *now_tm;
    char out[5][41];
    out[0][40] = '\n';
    out[1][40] = '\n';
    out[2][40] = '\n';
    out[3][40] = '\n';
    out[4][40] = '\n';
    while(1){
        system("cls");
        curtime = time(NULL);
        now_tm = localtime(&curtime);
        sec = now_tm->tm_sec;
        min = now_tm->tm_min;
        hr  = now_tm->tm_hour;
        char* timestr = timeToString(hr,min,sec);
        stringToAscii(timestr,out);
        printf("\e[1;1H\e[2J");
        for (int i = 0; i < 5; i +=1){
            for (int j = 0; j < 41; j +=1){
                printf("%c",out[i][j]);
            }
        }
        sleep(1);
        
    }
}