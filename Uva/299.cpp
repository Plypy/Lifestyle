#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int MAXN = 55;
int ar[MAXN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", ar+i);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (ar[i] > ar[j]) {
                    swap(ar[i],ar[j]);
                    ++ans;
                }
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
    return 0;
}
