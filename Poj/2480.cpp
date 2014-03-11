/**
 * Description: Number theory, Compute the sum of gcd(1,n),gcd(2,n),...,gcd(n,n)
 * Source: POJ 2480
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

int phi(int n) {
    int m = (int)sqrt(n+0.5);
    int ret = n;
    for (int i = 2; i <= m; ++i)
        if (0 == n%i) {
            ret = ret/i*(i-1);
            while (0 == n%i)
                n /= i;
        }
    if (n > 1)
        ret = ret/n*(n-1);
    return ret;
}

const int MAXN = 70000;
vector<int> plis;
bool notp[MAXN+10];
int num;
void init() {
    for (int i = 2; i <= MAXN; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i+i; j <= MAXN; j += i)
                notp[j] = true;
        }
    num = plis.size();
}

ll eval(ll p, ll k) {
    ll pn = 1;
    for (int i = 1; i <= k; ++i)
        pn *= p;
    ll ret = 0;
    ll t = 1;
    for (int i = 0; i <= k; ++i) {
        ret += t*phi(pn/t);
        t *= p;
    }
    return ret;
}

int main() {
    init();
    int n;
    while (EOF != scanf("%d", &n)) {
        ll ret = 1;
        for (int i = 0; i < num; ++i) {
            if (plis[i] > n)
                break;
            if (0 == n%plis[i]) {
                int t = 0;
                while (0 == n%plis[i]) {
                    ++t;
                    n /= plis[i];
                }
                ret *= eval(plis[i],t);
            }
        }
        if (n > 1) {
            ret *= eval(n,1);
        }
        printf("%lld\n", ret);
    }
}