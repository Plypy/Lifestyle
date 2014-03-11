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
int sc[5];
int n, l;
int main() {
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        if (-1 == v) {
            ++sc[u];
        } else if (v > l) {
            sc[u] += 3;
        } else {
            sc[u] += 2;
        }
    }
    cout << sc[1] << ":" << sc[2] << endl;
    return 0;
}

