#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 105;
int color[MAXN][MAXN];
int ct[MAXN];
int out[MAXN];
int n, k;
int main()
{
    cin >> n >> k;
    int mi = 100;
    for (int i = 1; i <= n; ++i) {
        cin >> ct[i];
        if (ct[i] < mi) {
            mi = ct[i];
        }
    }
    bool yes = true;
    for (int i = 1; i <= n; ++i) {
        if (mi + k < ct[i]) {
            yes = false;
            break;
        }
        for (int j = 1; j <= mi; ++j) {
            color[i][j] = 1;
        }
        for (int j = 1; mi+j <= ct[i]; ++j) {
            color[i][j+mi] = j;
        }
    }
    puts(yes ? "YES" : "NO");
    if (yes) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < ct[i]; ++j) {
                cout << color[i][j] << ' ';
            }
            cout << color[i][ct[i]] << endl;
        }
    }
}
