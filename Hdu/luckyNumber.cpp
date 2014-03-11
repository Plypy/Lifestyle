/**
 * Description: LuckyNumber
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
int a[20] = {0,4,7,44,47,74,77,444,447,474,477,744,747,774,777};
bool check(int t) {
    for (int i = 1; i <= 14; ++i) {
        if (0 == t%a[i])
            return true;
    }
    return false;
}
int main() {
    int n;
    while (cin >> n) {
        if (check(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
