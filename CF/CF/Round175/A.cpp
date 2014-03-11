#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        printf("%d", n-i+1);
        if (i != n)
            putchar(' ');
        else
            putchar('\n');
    }
    for (int i = 1; i <= n-k; ++i) {
        printf("%d", i);
        if (i != n-k)
            putchar(' ');
        else
            putchar('\n');
    }
    return 0;
}
