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

int n;
int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p , q;
        scanf("%d%d", &p, &q);
        if (q-p >= 2) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}
