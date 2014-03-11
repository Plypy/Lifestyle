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


const int MAXN = 80005;
bool notp[MAXN];
vector<int> plis;
int pnum;
int add[MAXN];
bool mult[MAXN];
void init() {
    notp[1] = true;
    for (int i = 2; i < MAXN; ++i) {
        if (notp[i])
            continue;
        plis.push_back(i);
        ++pnum;
        for (int j = i+i; j < MAXN; j += i) {
            notp[j] = true;
        }
        for (int j = 0; j < pnum; ++j) {
            if (i+plis[j] >= MAXN)
                break;
            ++add[i+plis[j]];
            if ((long long)i*plis[j] < MAXN)
                mult[i*plis[j]] = true;
        }
    }
    // pnum = plis.size();
}
int n;
bool load() {
    if (EOF == scanf("%d", &n))
        return false;
    return true;
}
int split1(int a) {
    int ret = 0;
    for (int i = 0; plis[i] <= a/3; ++i)
        for (int j = i; j < pnum; ++j) {
            int k = a-plis[i]-plis[j];
            if (k < plis[j])
                break;
            if (!notp[k])
                ++ret;
        }
    return ret;
}
int split2(int a) {
    int ret = 0;
    if (a%3 == 0 && !notp[a/3])
        ++ret;
    for (int i = 0; i < pnum; ++i) {
        if (plis[i] >= a)
            break;
        int j = a-plis[i];
        ret += add[j];

        if (j%2 == 0 && !notp[j/2])
            ++ret;
        // cout << ret << " after " << plis[i] << endl;
    }
    return ret;
}

void work() {
    int ans = 0;
    if (!notp[n])
        ++ans;
    // cout << "ans1 " << ans << endl;
    if (mult[n])
        ++ans;
    for (int i = 0; plis[i]*plis[i]*plis[i] <= n; ++i)
        if (n%plis[i] == 0 && mult[n/plis[i]]) {
            ++ans;
            break;
        }
    // cout << "ans1 " << ans << endl;
    for (int i = 0; i <= pnum; ++i) {
        if (plis[i] >= n)
            break;
        if (mult[n-plis[i]])
            ++ans;
    }
    // cout << "ans1 " << ans << endl;
    ans += add[n];

    // cout << "ans1 " << ans << endl;
    ans += split2(n)/3;
    printf("%d\n", ans);
}
void test() {
    // for (int i = 2; i <= 100; ++i)
    //     cout << i << ' ' << add[i] << endl;
    int n;
    while (cin >> n) {
        cout << split1(n) << ' ' << split2(n) << endl;
    }
}
int main(int argc, char const *argv[]) {
    init();
    // test();
    while (load()) {
        work();
    }
    return 0;
}