#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n)
            break;
        int r = 0;
        for (int i = 1; i <= n; ++i) {
            int a;
            scanf("%d", &a);
            a += r;
            if (a < 128) {
                putchar('0');
                r = a-0;
            } else {
                putchar('1');
                r = a-255;
            }
        }
        putchar('\n');
    }
    return 0;
}
