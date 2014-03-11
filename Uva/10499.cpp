#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    while (true) {
        double n;
        scanf("%lf", &n);
        if (n < 0)
            break;
        if (1 == n)
            printf("0%%\n");
        else {
            printf("%lld%%\n", (long long)(100.0*n/4+0.5));
        }
    }
    return 0;
}
