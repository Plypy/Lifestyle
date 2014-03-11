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
const int MAXN = 40005;
bool notp[MAXN];
int n;
void init() {
    int bd = n+10;
    notp[1] = true;
    for (int i = 2; i <= bd; ++i) {
        if (!notp[i]) {
            for (int j = i+i; j <= bd; j += i)
                notp[j] = true;
        }
    }
}
int main() {
    cin >> n;
    init();
    for (int i = 2; i <= n; ++i) {
        if (notp[i+1] || notp[i-1])
            continue;
        cout << i << endl;
    }
    return 0;
}
