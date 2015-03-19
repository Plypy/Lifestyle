#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 105;
ll mat[MAXN][MAXN];
ll a[MAXN];
ll b[MAXN];
ll n, m;
ll k;

bool check()
{
    for (int i = 1; i < n; ++i) {
        ll d0 = -1;             // positive delta
        ll d1 = 1;              // negative delta
        for (int j = 1; j <= m; ++j) {
            ll tmp = mat[i+1][j]-mat[i][j];
            if (tmp < 0) {
                if (d1 != 1 && tmp != d1) {
                    return false;
                }
                d1 = tmp;
            } else {
                if (d0 != -1 && tmp != d0) {
                    return false;
                }
                d0 = tmp;
            }
        }
        if (d0 != -1 && d1 != 1) {
            ll tk = d0-d1;
            if (k != 0 && k != tk) {
                return false;
            }
            k = tk;
        }
        if (d0 != -1) {
            a[i+1] = d0;
        } else if (d1 != 1) {
            a[i+1] = d1;
        }
    }
    for (int i = 1; i < m; ++i) {
        ll d0 = -1;             // positive delta
        ll d1 = 1;              // negative delta
        for (int j = 1; j <= n; ++j) {
            ll tmp = mat[j][i+1]-mat[j][i];
            if (tmp < 0) {
                if (d1 != 1 && tmp != d1) {
                    return false;
                }
                d1 = tmp;
            } else {
                if (d0 != -1 && tmp != d0) {
                    return false;
                }
                d0 = tmp;
            }
        }
        if (d0 != -1 && d1 != 1) {
            ll tk = d0-d1;
            if (k != 0 && k != tk) {
                return false;
            }
            k = tk;
        }
        if (d0 != -1) {
            b[i+1] = d0;
        } else if (d1 != 1) {
            b[i+1] = d1;
        }
    }
    if (0 == k) {
        k = 1e10+7;
        return true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mat[i][j] >= k) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }
    if (!check()) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        a[1] = 0;
        for (int i = 2; i <= n; ++i) {
            a[i] += a[i-1];
            if (a[i] >= k) {
                a[i] -= k;
            } else if (a[i] < 0) {
                a[i] += k;
            }
        }
        b[1] = mat[1][1];
        for (int i = 2; i <= m; ++i) {
            b[i] += b[i-1];
            if (b[i] >= k) {
                b[i] -= k;
            } else if (b[i] < 0) {
                b[i] += k;
            }
        }
        cout << k << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << (i != n ? ' ' : '\n');
        }
        for (int i = 1; i <= m; ++i) {
            cout << b[i] << (i != m ? ' ' : '\n');
        }
    }
}
