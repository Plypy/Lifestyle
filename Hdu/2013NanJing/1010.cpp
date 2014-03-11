/**
 * Description:
 * ProblemName:Ball
 * Source:2013 NanJing onsite "Ball"
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
typedef long long ll;
ll a[3];
int main(int argc, char const *argv[]) {
    while (EOF != scanf("%I64d%I64d%I64d", a, a+1, a+2)) {
        ll ans = 0;
        sort(a,a+3);
        int lst = -1;
        int del = 0;
        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < 3; ++i) if (a[i]) {
                if (true) {
                    --a[i];
                    ans += del;
                    ++del;
                    lst = i;
                }
            }
        ans += del*(a[0]+a[1]+a[2]);
        printf("%I64d\n", ans);
    }
    return 0;
}