#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        if (a > 2)
            printf("%d\n", a-2);
        else
            puts("0");
    }
    return 0;
}
