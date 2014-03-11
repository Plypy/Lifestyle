#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 1005;
int n;
int s[MAXN];
int g[MAXN];
int main() {
    int ct = 0;
    while (true) {
        cin >> n;
        if (!n)
            break;
        cout << "Game " << ++ct << ':' << endl;
        for (int i = 1; i <= n; ++i)
            cin >> s[i];
        while (true) {
            int a = 0, b = 0;
            bool used[MAXN] = {0};
            for (int i = 1; i <= n; ++i) {
                cin >> g[i];
                if (g[i] == s[i]) {
                    ++a;
                    used[i] = true;
                    g[i] = -1;
                }
            }
            if (!g[1])
                break;
            for (int i = 1; i <= n; ++i)
                if (!used[i]) {
                    for (int j = 1; j <= n; ++j)
                        if (s[i] == g[j]) {
                            ++b;
                            g[j] = -1;
                            break;
                        }
                        
                }
            cout << "    " << '(' << a << ',' << b << ')' << endl;
        }
    }
    return 0;
}
