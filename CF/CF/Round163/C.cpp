#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1005;
const int MAXM = 10005;

int fst[MAXN];
int row[MAXN], col[MAXN];
int x[MAXN], y[MAXN];
int n;
bool cmpR(int a, int b) {
    return row[a] < row[b];
}
bool cmpC(int a, int b) {
    return fst[a] < fst[b];
}

void load() {
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> x[i] >> y[i];
}
int pr[MAXN], rp[MAXN];
int pc[MAXN];
int ans;
int a1[MAXM], a2[MAXM], a3[MAXM];
void add(int a, int b, int c) {
    ++ans;
    a1[ans] = a;
    a2[ans] = b;
    a3[ans] = c;
}
bool cflag[MAXN], rflag[MAXN];
void work() {
    for (int i = 1; i < n; ++i)
        ++row[x[i]];
    for (int i = 1; i <= n; ++i)
        pr[i] = pc[i] = i;
    sort(pr+1,pr+n+1,cmpR);
    for (int i = 1; i <= n; ++i)
        rp[pr[i]] = i;

    for (int i = 1; i <= n; ++i)
        fst[i] = MAXN;
    for (int i = 1; i < n; ++i)
        if (fst[y[i]] > rp[x[i]])
            fst[y[i]] = rp[x[i]];
    sort(pc+1,pc+n+1,cmpC);

    for (int i = 1; i <= n; ++i) {
        if (!rflag[i]) {
            int t = i;
            rflag[t] = true;
            while (!rflag[pr[t]]) {
                add(1,t,pr[t]);
                t = pr[t];
                rflag[t] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!cflag[i]) {
            int t = i;
            cflag[t] = true;
            while (!cflag[pc[t]]) {
                add(2,t,pc[t]);
                t = pc[t];
                cflag[t] = true;
            }
        }
    }

}
void print() {
    cout << ans << endl;
    for (int i = 1; i <= ans; ++i)
        cout << a1[i] << ' ' << a2[i] << ' ' << a3[i] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    print();
    return 0;
}
