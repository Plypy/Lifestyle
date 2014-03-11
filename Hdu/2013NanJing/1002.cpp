/**
 * Description:
 * ProblemName: Poor Warehouse Keeper
 * Source: 2013 NanJing Onsite
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
const double eps = 1e-5;
int x, y;

int main(int argc, char const *argv[]) {
    while (EOF != scanf("%d%d", &x, &y)) {
        double n = x, s = y-x+1-eps;
        int ans = 0;
        if (s < 0) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= x; ++i) {
            double tmp = n/i;
            double p = s/tmp;
            int ip = floor(p);
            ans += ip;
            s -= ip*tmp;
        }
        ans += x-1;
        printf("%d\n", ans);
    }
    return 0;
}