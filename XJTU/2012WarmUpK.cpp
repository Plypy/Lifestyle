#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 5;
const int INF = 1000000000;
int a[MAXN];
inline int gcd(int a, int b) {
    while (b) {
       int c = a;
       a = b;
       b = c%b;
    }
    return a;
}
inline int lcm(int a, int b) {
    return a*b/gcd(a,b);
} 

int main() {
    for (int i = 0; i < MAXN; ++i)
        scanf("%d", a+i);
    int ans = INF;
    for (int i = 0; i < MAXN-2; ++i)
        for (int j = i+1; j < MAXN-1; ++j) {
            int p = lcm(a[i],a[j]);
            for (int k = j+1; k < MAXN; ++k) {
                int q = lcm(a[k],p);
                if (ans > q)
                    ans = q;
            }
        }
    printf("%d\n", ans);
//    system("pause");
    return 0;
}
