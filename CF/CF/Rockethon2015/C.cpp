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
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 7;
const double eps = 1e-10;
int l[MAXN], r[MAXN];
int n;

int get_num(int val, int idx)
{
    int ret = min(val, r[idx]) - l[idx] + 1;
    ret = max(ret, 0);
    return ret;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    cout << fixed << setprecision(10);
    double tot = 1;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        tot *= (r[i]-l[i]+1);
    }
    int min_bid = l[0], max_bid = r[0];
    for (int i = 1; i < n; ++i) {
        min_bid = min(min_bid, l[i]);
        max_bid = max(max_bid, r[i]);
    }
    double num = 0;
    for (int p = min_bid; p <= max_bid; ++p) {
        for (int i = 0; i < n; ++i) {
            double base = p*max(0, r[i] - max(p, l[i]-1));

            double tmp1 = 1, tmp2 = 1;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                tmp1 *= get_num(p, j);
                tmp2 *= get_num(p-1, j);
            }
            num += base * (tmp1-tmp2);
        }

        int ubd = 1<<n;
        for (int mask = 1; mask < ubd; ++mask) {
            if (__builtin_popcount(mask) < 2) {
                continue;
            }
            double tmp = p * 1;
            for (int i = 0; i < n; ++i) {
                int bit = 1<<i;
                if (!(mask & bit)) {
                    tmp *= get_num(p-1, i);
                } else if (p < l[i] || p > r[i]) {
                    tmp = 0;
                    break;
                }
            }
            num += tmp;
        }
    }
    cout << num / tot << endl;
    return 0;
}
