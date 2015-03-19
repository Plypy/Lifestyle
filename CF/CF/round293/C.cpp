#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int id[MAXN];
int ord[MAXN];
int n, m, k;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> id[i];
        ord[id[i]] = i;
    }
    long long ans = 0;
    while (m--) {
        int a;
        cin >> a;
        ans += (ord[a]+k-1)/k;
        if (ord[a] == 1) {
            continue;
        }
        int b = id[ord[a]-1];
        swap(id[ord[a]], id[ord[b]]);
        swap(ord[a], ord[b]);
    }
    cout << ans << endl;
    return 0;
}
