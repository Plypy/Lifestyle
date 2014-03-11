#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
const int BOUND = 1<<10;
const int INF = 1<<20;
const double INFS = 1e-6;
bool notp[BOUND];
vector<int> plis;
int pnum; 
void init() {
    for (int i = 2; i < BOUND; ++i) {
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i*2; j < BOUND; j += i)
                notp[j] = true;
        }
    }
    pnum = plis.size();
}

const int MAXP = 25;
int ipow(int b, int p) {
    int ret = 1;
    for (int i = 1; i <= p; ++i)
        ret *= b;
    return ret;
}
int getdnum(int nbound, int div) {
    int ret = 0;
    int mp = int(log(nbound)/log(div));
    for (int i = mp; i; --i) {
        ret += nbound/ipow(div,i);
    }
    return ret;
}

int main() {
    init();
    int n, base;
    while (EOF != scanf("%d %d", &n, &base)) {
        if (!n)
            n = 1;
        int ans1 = INF, ans2 = 0;
        int t = base;
        for (int i = 0; i < pnum; ++i) {
            int p = 0;
            while (0 == t%plis[i]) {
                ++p;
                t /= plis[i];
            }
            if (p) {
                int tot = getdnum(n,plis[i])/p;
                if (ans1 > tot)
                    ans1 = tot;
            }
        }
        if (t > 1) {
            int tmp = getdnum(n,t);
            if (ans1 > tmp)
                ans1 = tmp;
        }
        double tmp = 0;
        for (int i = 2; i <= n; ++i)
            tmp += log(i)/log(base);
        if (abs(tmp-int(tmp)) < INFS)
            tmp = tmp+1;
        ans2 = int(ceil(tmp));
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
