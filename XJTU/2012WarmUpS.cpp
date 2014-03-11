#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 8;
int main() {
    int ct = 0;
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j) {
            char ch;
            cin >> ch;
            if (!((i+j)&1) && 'F' == ch)
                ++ct;
        }
    printf("%d\n", ct);
    return 0;
}
