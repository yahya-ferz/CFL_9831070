#include <stdio.h>
#include <stdlib.h>

char Finished(char a[][3])
{
    int i,j=0;
    for (i = 0; i <3 ; ++i)
    {
        if((a[i][j]==a[i][j+1])&&(a[i][j+1]==a[i][j+2])) return a[i][j];
        if((a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i])) return a[j][i];
    }
    if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2])) return a[0][0];
    if((a[0][2]==a[1][1])&&(a[1][1]==a[2][0])) return a[1][1];
    return '0';
}
void PrintGame(char a[][3])
{
    int i,j;
    for (j = 0; j < 3; ++j)
    {
        for (i = 0; i <3 ; ++i)
        {
            if(a[i][j]>48&&a[i][j]<58)
                printf("-|");
            else
                printf("%c|",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j,l=0,p=0;
    char a[3][3],h;
    a[0][0]='1';a[1][0]='2';a[2][0]='3';
    a[0][1]='4';a[1][1]='5';a[2][1]='6';
    a[0][2]='7';a[1][2]='8';a[2][2]='9';
    PrintGame(a);
    printf("\n");
    while(p==0)
    {
        printf("Player X please enter your choice:\n");
        scanf(" %c",&h);
        for (j = 0; j <3 ; j++)
        {
            for (i= 0; i < 3; i++)
            {
                if(h==a[i][j])
                {
                    a[i][j] = 'X';
                    break;
                }
            }
        }
        if(Finished(a)=='O'||Finished(a)=='X')
        {
            p++;
            printf("player %c won!\n",Finished(a));
            PrintGame(a);
            break;
        }
        l++;
        if(l==5)break;
        PrintGame(a);
        printf("Player O please enter your choice:\n");
        scanf(" %c",&h);
        for (j = 0; j <3 ; j++)
        {
            for (i= 0; i < 3; i++)
            {
                if(h==a[i][j])
                {
                    a[i][j] = 'O';
                    break;
                }
            }
        }
        PrintGame(a);
        if(Finished(a)=='O'||Finished(a)=='X')
        {
            p++;
            printf("player %c won!\n",Finished(a));
            PrintGame(a);
            break;
        }
    }
    if(l==5)
    {
        printf("DRAW!");
        PrintGame(a);
        l++;
    }
     return 0;
}
