#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int MAXD = 10005;
const int MAXT = 10000;
struct Data {
    int id;
    int ct;
    bool operator<(const Data&T) const {
        if (ct != T.ct)
            return ct>T.ct;
        return id<T.id;
    }
} ct[MAXD];
int n, m;
bool load() {
    cin >> n >> m;
    if (n == 0 && m == 0)
        return false;
    for (int i = 1; i <= MAXT; ++i)
        ct[i].id = i, ct[i].ct = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int a;
            cin >> a;
            ++ct[a].ct;
        }
    return true;
}
void work() {
    sort(ct+1,ct+MAXT+1);
    int i = 0;
    for (i = 2; ct[i].ct == ct[1].ct; ++i)
        continue;
    int tmp = i;
    bool flag = true;
    for ( ; ct[i].ct == ct[tmp].ct; ++i) {
        if (flag)
            flag = false;
        else
            cout << ' ';
        cout << ct[i].id;
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
    }
    return 0;
}
