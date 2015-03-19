/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int T, n;
int ar[MAXN];

int lar[MAXN], rar[MAXN];

void init() {
    memset(lar, 0, sizeof lar);
    memset(rar, 0, sizeof rar);
}

int main() {

    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> ar[i];
        }

        init();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j)
                if (ar[j] > ar[i]) ++lar[i];
        }
        for (int i = n; i >= 0; --i) {
            for (int j = n; j > i; --j)
                if (ar[j] > ar[i])
                    ++rar[i];
        }


        for (int i = 1; i <= n; ++i) {
            ans += min(lar[i], rar[i]);
        }

        printf("Case #%d: %d\n", kase, ans);

    }
    return 0;
}
