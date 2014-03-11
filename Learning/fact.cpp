/**
 * Description:
 * Source:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
int solve(int n) {
    int ret = 0;
    int d = 5;
    while (d <= n) {
        ret += n/d;
        d *= 5;
    }
    return ret;
}
int main() {
    while (cin >> n) {
        cout << solve(n) << endl;
    }
}