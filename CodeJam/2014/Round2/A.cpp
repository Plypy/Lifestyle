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


const int MAXN = 10010;
int T, x, N, ar[MAXN];

int main() {

    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> x;
        for (int i = 0; i < N; ++i)
            cin >> ar[i];

        sort(ar, ar + N);
        int ans = 0;

        int l = 0, r = N-1;
        while (r >= l) {
            ++ans;
            if (l == r) {
                break;
            }
            if (ar[l] + ar[r] <= x) {
                ++l;
                --r;
            } else {
                --r;
            }

        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
