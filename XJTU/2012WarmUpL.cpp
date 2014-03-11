#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 1005;
bool is[MAXN];

int main() {
    for (int i = 1; i < 100; ++i)
        is[i] = true;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j) {
            int k = 2*j-i;
            if (k >= 0 && k < 10) {
                is[i*100+j*10+k] = true;
            }
        }
        
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (is[i])
            ++ans;
    printf("%d\n", ans);
    return 0;
}
