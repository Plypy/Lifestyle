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

const int MAXN = 55;
typedef long long ll;
int ans[MAXN];
int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    ll l = 1, r = n;
    long long num = 1LL<<(n-2);
    for (int i = 1; i <= n; ++i) {
        if (m > num) {
            ans[r--] = i;
            m -= num;
        } else {
            ans[l++] = i;
        }
        num >>= 1;
    }
    cout << ans[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << ans[i];
    }
    cout << endl;
    return 0;
}
