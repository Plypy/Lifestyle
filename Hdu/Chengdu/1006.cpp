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

const int MAXN = 100005;
const int MOD = 1000000007;
char a[MAXN];
char b[MAXN];
int num[MAXN];
int rzero, lsame;

int epos = 0;
void clear() {
    memset(num,0,sizeof(num));
    rzero = 0;
    lsame = 0;
    epos =0 ;
}
bool same(int i) {
    if (a[i] == '?')
        return true;
    if (b[i] == '?')
        return true;
    if (a[i] == b[i])
        return true;
    return false;
}
typedef long long ll;
int mult(ll a, ll b) {
    return (a*b)%MOD;
}
int add(ll a, ll b) {
    return (a+b)%MOD;
}
int pow2(int p) {
    if (0 == p)
        return 1;
    int ret = pow2(p>>1);
    ret = mult(ret,ret);
    if (p&1)
        ret = mult(ret,2);
    return ret;
}
int n;
int work() {
    n = strlen(a);
    for (int i = 0; i < n; ++i)
        if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
            lsame = i-1;
            break;
        }
    for (int i = n-1; i >= 0; --i) {
        if (('1' == a[i]) || ('1' == b[i])) {
            rzero = i+1;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i)
            num[i] = num[i-1];
        if (a[i] == b[i] && a[i] == '?')
            ++num[i];
    }
    int ect = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        if (!same(i)) {
            pos = i;
            ++ect;
            if (2 == ect) {
                return -1;
            }
        }
    }
    epos = pos;
    if (1 == ect) {
        if (pos+1 < n) {
            if ('0' == a[pos+1] || '0' == b[pos+1])
                return -1;
            if (pos+2 < rzero)
                return -1;
        }
        return pow2(num[pos-1]);
    }
    int ret = 0;
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '?' || b[i] == '?') {
            int delta = 0;
            if (i) {
                delta = num[i-1];
            }
            int tmp = pow2(delta);
            ret = add(ret,tmp);
        }
        if (a[i] == b[i] && a[i] == '?')
            ++ct;
    }
    return ret;
}
void load() {
    scanf("%s%s", a, b);
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        int tmp = work();
        printf("Case #%d:\n", i);
        // cout << epos << endl;
        if (-1 == tmp) {
            puts("Impossible");
        } else {
            if (1 == tmp) {
                if (epos) {
                    if (epos+1 < n) {
                        a[epos+1] = b[epos+1] = '1';
                    }
                }
                for (int i = 0; i < n; ++i) {
                    if (a[i] == '?' && b[i] != '?')
                        a[i] = b[i];
                    if (b[i] == '?' && b[i] != '?')
                        b[i] = a[i];
                    if (a[i] == '?' && b[i] == '?')
                        a[i] = b[i] = '0';
                }
                puts(a);
                puts(b);
            } else {
                printf("Ambiguous %d\n", tmp);
            }
        }
        clear();
    }
    return 0;
}