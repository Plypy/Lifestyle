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
int A, B, K;
void load() {
    cin >> A >> B >>K;
}
long long ans = 0;
void work() {
    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j) {
            if ((i&j) < K)
                ++ans;
        }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        ans = 0;
        load();
        work();
        printf("Case #%d: %d\n", t, ans);
    }
}
