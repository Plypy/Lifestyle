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

const int MAXN = 105;
char number[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", number);
    int ans = 0;
    while (number[ans] == '1' && ans < n) {
        ++ans;
    }
    if (n != ans) {
        ++ans;
    }
    printf("%d\n", ans);
}
