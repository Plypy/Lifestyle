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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    int tot = m*(m-1)/2;
    printf("%d\n", tot);
    for (int i = 1; i <= m; ++i)
        for (int j = i+1; j <= m; ++j) {
            if (k) {
                printf("%d %d\n", j, i);
            } else {
                printf("%d %d\n", i, j);
            }
        }
}