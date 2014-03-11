#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 10005;
int s[MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", s+i);
        s[i] += s[i-1];
    }
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", s[b]-s[a-1]);
    }
    return 0;
}
