#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

template<class T>
T sqr(const T &a) {
    return a*a;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n)
            break;
        int layer = int(sqrt(n));
        int ans1 = 0, ans2 = 0;
        if (sqr(layer) != n)
            ++layer;
        int inside = sqr(layer-1);
        int rest = n-inside;
        if (layer&1) {
            if (rest <= layer) {
                ans1 = layer;
                ans2 = rest;
            } else {
                ans2 = layer;
                ans1 = 2*layer-rest;
            }
        } else {
            if (rest <= layer) {
                ans2 = layer;
                ans1 = rest;
            } else {
                ans1 = layer;
                ans2 = 2*layer-rest;
            }
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
