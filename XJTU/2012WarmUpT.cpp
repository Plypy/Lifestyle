//算法可以再改进...
//我只是优化了一下常数 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1000005;
int n;
double a[MAXN];

inline void myread(double &t) {
    char ch;
    t = 0.0;
    while (true) {
        ch = getchar();
        if (isdigit(ch) || '.' == ch)
            break;
    }
    while (isdigit(ch)) {
        t *= 10;
        t += ch-'0';
        ch = getchar();
    }
    ch = getchar();
    double div = 0.1;
    while (isdigit(ch)) {
        t += (ch-'0')*div;
        div *= 0.1;
        ch = getchar();
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        myread(a[i]);
    sort(a,a+n);
    double mem = a[0];
    int ct = 1;
    int half = (n>>1);
    for (int i = 1; i < n; ++i) {
        if (a[i] != mem) {
            ct = 1;
            mem = a[i];
        } else {
            if (++ct > half) {
                printf("%.2lf\n", mem);
                break;
            }
        }
    }
//    system("pause");
    return 0;
}
