#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = ceil(log(b)/log(4));
        if (b == 1)
            ans = max(ans,a+1);
        else
            ans = max(ans,a+p);
    }
    printf("%d\n", ans);
}
