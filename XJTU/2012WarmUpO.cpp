#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int a, b;
    while (EOF != scanf("%d%d", &a, &b)) {
        printf("%d\n", b-(a-1));
        while (b--) {
            int t;
            scanf("%d%d", &t, &t);
        }
    }
    return 0;
}
