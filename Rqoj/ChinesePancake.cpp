/*
  Name: ChinesePancake
  Author: Ply_py 
  Date: 10-03
  Description: None
*/
//‘› ±∏È÷√.. 
#include <stdio.h>
#define MAXN = 1000001;
char name[MAXN][4];
int bot, top;
void read(char *str)
{
    char ch;
    do
    {
        ch = getchar();
    } while(' ' == ch || '\n' == ch || '(' == ch || ')' == ch);
    while ('\n' != ch && ')' != ch)
    {
        *str++ = ch;
        ch = getchar();
    }
    *str = 0;
}
int main()
{
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    bot = 1, top = n;
    for (int i = n; i; --i)
        read(name[i]);
    
}
