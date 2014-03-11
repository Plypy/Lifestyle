/**
 * Description: Just check the lower right corner will be fun, since all operation influences this one.
 * Source: hdu 4642
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


int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int t = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &t);
            }
        if (t) {
            puts("Alice");
        } else {
            puts("Bob");
        }
    }
    return 0;
}