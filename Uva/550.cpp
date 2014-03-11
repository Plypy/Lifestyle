#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int base, lastd, factor;
    while (cin >> base >> lastd >> factor) {
        int t = 0;
        int now = lastd;
        int nxt;
        int ct = 0;
        while (++ct) {
            now = now*factor+t;
            t = now/base;
            now %= base;
            if (!t && now == lastd)
                break;
        }
        cout << ct << endl;
    }
    return 0;
}
