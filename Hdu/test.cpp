#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
int f[MAXN];
void compute() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        f[i] = 3*f[i-1]+f[i-2];
}
    
int main() {
    int t;
    compute();
    while (cin >> t) {
        for (int i = 1; i <= t; ++i)
            cout << f[i] << endl;
        cout << endl;
    }
    return 0;
}
