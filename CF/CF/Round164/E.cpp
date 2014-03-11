#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 50005;
struct Song {
    int len;
    double poss;
    bool operator<(const Song &t) const {
        double a = len*poss*(1-t.poss);
        double b = t.len*t.poss*(1-poss);
        return a > b;
    }
} s[MAXN];;
int n;

void load() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].len >> s[i].poss;
        s[i].poss /= 100;
    }
}
double sp[MAXN];
double ans;
void work() {
    sort(s,s+n);
    for (int i = n-1; i; --i)
        sp[i] = sp[i+1]+1-s[i].poss;
    for (int i = 0; i < n; ++i) {
        ans += s[i].len;
    }
    for (int i = 0; i < n; ++i) {
        ans += s[i].len*s[i].poss*sp[i+1];
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(9);
    load();
    work();
    return 0;
}
