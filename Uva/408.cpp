#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

inline int gcd(int a, int b) {
    while (b) {
        int c = a;
        a = b;
        b = c%b;
    }
    return a;
}
int main() {
    int a, b;
    while (cin >> a >> b) {
        printf("%10d%10d", a, b);
        if (1 == gcd(a,b))
            printf("    Good Choice\n\n");
        else
            printf("    Bad Choice\n\n");
    }
    return 0;
}
