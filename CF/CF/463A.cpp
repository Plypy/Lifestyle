/**
 * Description: Easy problem
 * ProblemName:
 * Source:  Codeforces
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, s;
int main() {
    cin >> n >> s;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y > 0) {
            ++x;
        }
        if (x > s) {
            continue;
        }
        int change = (100-y)%100;
        if (change > ans) {
            ans = change;
        }
    }
    cout << ans << endl;
}
