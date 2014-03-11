#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 205;
int n;
int x[MAXN], y[MAXN];

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x+i, y+i);
}

bool check(int i, int j, int k) {
    int a = x[i]-x[j];
    int b = y[i]-y[j];
    int c = x[i]-x[k];
    int d = y[i]-y[k];
    if (a*d-b*c)
        return false;
    return true;
}

void work() {
    int ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            int t = 2;
            for (int k = 1; k <= n; ++k)
                if (k != i && k != j && check(i,j,k))
                    ++t;
            if (ans < t)
                ans = t;
        }
    cout << ans << endl;
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
