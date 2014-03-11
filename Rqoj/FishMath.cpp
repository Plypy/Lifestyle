#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
const int MAXN = 20001;
int ar[MAXN];
int n;
inline void read(int &t)
{
    char ch;
    int signal = 1;
    for (ch = getchar(); isspace(ch);ch = getchar())
        continue;
    if (ch == '-')
    {
        signal = -1;
        ch = getchar();
    }
    int tmp = 0;
    do {
        tmp *= 10;
        tmp += ch-'0';
        ch = getchar();
    } while (isdigit(ch));
    t = tmp*signal;
}
int main()
{
    read(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        read(ar[i]);
        for (int j = 1; j < i; j++)
            if (ar[j]>ar[i])
                ans++;
    }
    printf("%d", ans);
    return 0;
}

