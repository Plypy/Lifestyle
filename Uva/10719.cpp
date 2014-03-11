#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int k;
    while (cin >> k) {
        printf("q(x):");
        int t = 0, b = 0;
        while (true) {
            scanf("%d", &b);
            char ch = getchar();
            b += t;
            if (' ' != ch)
                break;
            printf(" %d", b);
            t = k*b;
        }
        printf("\nr = %d\n\n", b);
    }
    return 0;
}
