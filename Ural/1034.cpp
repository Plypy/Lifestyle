#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 55;
int n;
int h[MAXN], v[MAXN];

bool check() {
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
                if (abs(h[i]-h[j]) == abs(v[i]-v[j]))
                    return false;
    return true;
}
void change(int i, int j, int k) {
    int t = h[i];
    h[i] = h[j];
    h[j] = h[k];
    h[k] = t;
}

int ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i] >> v[i];
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            for (int k = j+1; k <= n; ++k) {
                change(i,j,k);
                if (check())
                    ++ans;
                change(i,j,k);
                if (check())
                    ++ans;
                change(i,j,k);
            }
    cout << ans << endl;
//    system("pause");
    return 0;
}
