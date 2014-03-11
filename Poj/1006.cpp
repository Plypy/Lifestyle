#include <stdio.h>
#define P_P 23
#define P_E 28
#define P_I 33
int main() {
    int p, e, i, d;
    for (int ct = 1; true; ++ct) {
        scanf("%d%d%d%d", &p, &e, &i, &d); 
        if (-1 == p)
            break;
        // 算出各自的生理顶峰第一次出现的时间 
        p %= P_P;
        e %= P_E;
        i %= P_I;
        
        // 简单的推导一下就好了
        // 设x为所求日期 那么有
        // x-p|23, x-e|28, x-i|33
        // 可将其重写为 x = 23*L+p(1), x = 28*n+e(2), x = 33*m+i(3)
        // 由(2)-(1)得 0 = 23*(n-L)+5n+e-p
        // 整理可得 23*(L-n) = 5*n+e-p
        // 然后可由此枚举n算5*n+e-p是否为23的倍数，若是则能满足要求 
        int t = e-p;
        int n = 0;
        while (t%P_P != 0) {
            ++n;
            t += 5;
        }
        t = 28*n+e;
        
        int r = t-i;
        n = 0;
        while (r%P_I != 0) {
            ++n;
            r += 611;
        }
        t = n*644+t;
        if (t > d)
            t = t-d;
        else
            t = t+21252-d;
        printf("Case %d: the next triple peak occurs in %d days.\n",ct,t);
    }
    return 0;
}
