#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

inline int clac(int s) {
    if (!s)
        return 0;
    int n = int(ceil((-1+sqrt(1+4*s))/2));
    int t = n*n;
    if (s <= t)
        return 2*n-1;
    return 2*n;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", clac(y-x));
    }
    return 0;
}
