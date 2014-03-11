/**
 * Description:
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

int power(int a, int b, int c) {
    int ret = 1;
    for (;b; b >>= 1) {
        if (b&1) {
            ret *= a;
            ret %= c;
        }
        a *= a;
        a %= c;
    }
    return ret;
}
int main() {
    int n, m, y;
    cin >> n >> m >> y;
    bool flag = false;
    for (int i = 0; i < m; ++i)
        if (power(i,n,m) == y) {
            flag = true;
            cout << i << ' ';
        }
    if (!flag) {
        cout << -1;
    }
    cout << endl;
}
