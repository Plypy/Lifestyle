#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 45;
int d[MAXN];
int pat[10];
char syb[4] = {' ', '.', 'x', 'W'};
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(d,0,sizeof(d));
        memset(pat,0,sizeof(pat));
        d[20] = 1;
        for (int i = 0; i < 10; ++i)
            cin >> pat[i];
        int tmp[MAXN] = {0};
        for (int i = 0; i < 50; ++i) {
            for (int j = 1; j <= 40; ++j)
                cout << syb[d[j]];
            cout << endl;
            for (int j = 1; j <= 40; ++j)
                tmp[j] = d[j-1]+d[j]+d[j+1];
            for (int j = 1; j <= 40; ++j)
                d[j] = pat[tmp[j]];
        }
        if (t)
            cout << endl;
    }
    return 0;
}
