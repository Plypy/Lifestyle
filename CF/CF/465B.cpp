/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int ans = 0;
    bool first = true;
    int last = 1;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t) {
            if (last || first) {
                ++ans;
            } else {
                ans += 2;
            }
            first = false;
        }
        last = t;
    }
    printf("%d\n", ans);
}
