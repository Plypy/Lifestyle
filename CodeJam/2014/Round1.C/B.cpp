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

const int MAXN = 300;
const int MOD  = 1000000007;

typedef long long ll;
int n;
string str[MAXN];
int hct[MAXN], tct[MAXN];
int act[MAXN], mct[MAXN];
int fact[MAXN];
int mod(ll a, ll b) {
    return (a+b)%MOD;
}
int mult(ll a, ll b) {
    return (a*b)%MOD;
}
void prec() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = mult(i,fact[i-1]);
    }
}
void init() {
    memset(hct,0,sizeof(hct));
    memset(tct,0,sizeof(tct));
    memset(act,0,sizeof(act));
    memset(mct,0,sizeof(mct));
}
void load() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
}

int work() {
    for (int i = 0; i < n; ++i) {
        string &tstr = str[i];
        int len = tstr.size();
        int j = 1;
        for (j = 1; j < len; ++j) {
            if (tstr[j] != tstr[j-1])
                break;
        }
        if (j == len) {
            ++act[tstr[0]];
        } else {
            ++hct[tstr[0]];
            ++tct[tstr[len-1]];
            for (++j; j < len; ++j) {
                if (tstr[j] != tstr[j-1]) {
                    ++mct[tstr[j-1]];
                }
            }
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (hct[i] > 1 || tct[i] > 1 || mct[i] > 1)
            return 0;
        if (hct[i] || tct[i] || act[i]) {
            if (mct[i])
                return 0;
        }
    }
    int ret = 1;
    for (int i = 'a'; i <= 'z'; ++i) {
        ret = mult(ret,fact[act[i]]);
    }
    // cout << "ret1 " << ret << endl;
    int con = 26;
    bool flag = true;
    int single = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (!(hct[i] || tct[i] || act[i] || mct[i])) {
            --con;
            continue;
        }
        if (mct[i]) {
            --con;
            continue;
        }
        if (hct[i] && tct[i]) {
            --con;
            continue;
        }
        if (hct[i] || tct[i]) {
            --con;
            ++single;
        }
        flag = false;
    }
    con += single/2;
    // cout << "con " << con << endl;
    if (0 == con && flag)
        return 0;
    ret = mult(ret,fact[con]);
    // cout << "ret2 " << ret << endl;
    return ret;
}
int main() {
    int T;
    scanf("%d", &T);
    prec();
    for (int t = 1; t <= T; ++t) {
        init();
        load();
        int ans = work();
        printf("Case #%d: %d\n", t, ans);
    }
}
