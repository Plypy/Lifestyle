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
const int MAXN = 1000005;
const int BUFSIZE = MAXN*5;
int n;
int buf[BUFSIZE];
int *cur = buf;
int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cur[i] = i+1;
    for (int k = 2; k <= n; ++k) {
        int pre = cur[0];
        for (int i = 0; i+k <= n; i += k) {
            int tmp = cur[i+k];
            cur[i+k] = pre;
            pre = tmp;
        }
        if (n % k)
            cur[n] = pre;
        ++cur;
    }
    cout << cur[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << cur[i];
    }
    cout << endl;
    return 0;
}

