/**
 * Description:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n, m, k;
int main(int argc, char const *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    int ans = 0;
    int b = m, p = k;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (1 == a) {
            if (b) {
                --b;
            } else {
                ++ans;
            }
        } else {
            if (p) {
                --p;
            } else {
                if (b) {
                    --b;
                } else {
                    ++ans;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}