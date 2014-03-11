#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int ct = 0;
    while (true) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if (!a)
            break;
        long long sum = a*(a-1)*b*(b-1)/4;
        printf("Case %d: %lld\n", ++ct, sum);
    }
    return 0;
}
