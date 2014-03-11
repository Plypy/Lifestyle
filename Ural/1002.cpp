// dynamic programming function f[i] = exist(i-j,i)|min(f[i-j])+1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 110
#define MAXN 50010
#define INF 52111425
#define WORDL 52
char table[256];
char pat[MAXL];
char words[MAXN][WORDL];
int f[MAXL];
int lenth[MAXN];
int n;
int patl;
void init()
{
    table['i'] = table['j'] = '1';
    table['a'] = table['b'] = table['c'] = '2';
    table['d'] = table['e'] = table['f'] = '3';
    table['g'] = table['h'] = '4';
    table['k'] = table['l'] = '5';
    table['m'] = table['n'] = '6';
    table['p'] = table['r'] = table['s'] = '7';
    table['t'] = table['u'] = table['v'] = '8';
    table['w'] = table['x'] = table['y'] = '9';
    table['o'] = table['q'] = table['z'] = '0';
}
bool load()
{
    gets(pat);
    if ('-' == pat[0])
        return false;
    patl = strlen(pat);
    for (int i = 1; i <= patl; ++i)
        f[i] = INF;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i)
    {
        gets(words[i]);
        lenth[i] = strlen(words[i]);
    }
    return true;
}
int mem[MAXL];
bool check(int npos, int wordid)
{
    for (int i = 0; i < lenth[wordid]; ++i)
        if (pat[npos+i] != table[words[wordid][i]])
            return false;
    return true;
}
int ans[MAXL];
void work()
{
    for (int i = 0; i < patl; ++i)
        for (int j = 0; j < n; ++j)
            if (i+lenth[j] <= patl && f[i+lenth[j]] > f[i]+1 && check(i,j))
            {
                f[i+lenth[j]] = f[i]+1;
                mem[i+lenth[j]] = j;
            }
    if (f[patl] == INF)
        printf("No solution.\n");
    else
    {
        for (int pos = patl; pos; pos -= lenth[mem[pos]])
            ans[++ans[0]] = mem[pos];
        printf("%s", words[ans[ans[0]]]);
        for (int i = ans[0]-1; i; --i)
            printf(" %s", words[ans[i]]);
        printf("\n");
    }
}
int main()
{
    init();
    while (load())
        work();
    return 0;
}
