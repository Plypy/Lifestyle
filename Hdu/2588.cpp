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

const int MAXN = 1000000005;
const int BD = 100005;

int pnum;
vector<int> plis;
bool notp[BD];
void prep() {
    for (int i = 2; i < BD; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = 2*i; j < BD; j += i)
                notp[j] = true;
        }
    pnum = plis.size();
}

int phi(int n) {
    int ret = n;
    for (int i = 0; i < pnum; ++i) {
        int p = plis[i];
        if (p*p > n)
            break;
        if (n%p == 0) {
            ret = ret/p*(p-1);
            while (n%p == 0)
                n /= p;
        }
    }
    if (n > 1)
        ret = ret/n*(n-1);
    return ret;
}

void test() {
    for (int i = 1; i <= 100; ++i)
        cout << i << ' ' << phi(i) << endl;
}
int main(int argc, char const *argv[]) {
    int T;
    prep();
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans = n;
        if (m != 1) {
            ans = 0;
            for (int d = 1; d*d <= n; ++d) {
                if (n%d == 0) {
                    if (d >= m)
                        ans += phi(n/d);
                    if (d*d != n) {
                        if (n/d >= m)
                            ans += phi(d);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}