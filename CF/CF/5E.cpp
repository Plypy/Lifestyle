#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 1000005;
int r[MAXN], l[MAXN], c[MAXN];
int buf[MAXN];
int n, a[MAXN];

void load() {
    cin >> n;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > a[pos])
            pos = i;
    }
    buf[n] = a[pos];
    for (int i = 0; i < n; ++i)
        buf[i] = a[(pos+i)%n];
    memcpy(a,buf,sizeof(a));
}

void work() {
    r[n] = 0;
    for (int i = n-1; i >= 0; --i) {
        r[i] = i+1;
        while (r[i] < n && a[i] > a[r[i]])
            r[i] = r[r[i]];
        if (r[i] < n && a[i] == a[r[i]]) {
            c[i] = c[r[i]]+1;
            r[i] = r[r[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = i-1;
        while (l[i] > 0 && a[i] >= a[l[i]])
            l[i] = l[l[i]];
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += 2+c[i];
        if (l[i] == 0 && r[i] == n)
            --ans;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
