#include <iostream>
#include <stdio.h>
using namespace std;
void check(int l, int r)
{
    if(l == 1)
    {
        printf("1\n");
        return ;
    }
    if(l == r)
    {
        printf("%d\n", l);
        return ;
    }
    double ans = 10000000, res, m;
    int t, i, j;
    for(i = r; i >= l; i --)
    {
        res = 0;
        for(j = 2; j*j <= i; j ++)
        {
            if(i%j == 0)
            {
                m = i/j;
                res += m+j;
                if(m == j) res -= m;
            }
        }
        res /= i*1.0;
        if(res < ans)
        {
            ans = res;
            t = i;
        }
        if(res == 0)
        {
            printf("%d\n", i);
            return ;
        }
    }
    printf("%d\n", t);
}
int main()
{
    int l, r, i, j, ans;
    while(scanf("%d%d", &l, &r) != EOF) check(l, r);
    return 0;
}
