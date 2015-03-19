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
int n,m;
int g[MAXN][MAXN];
string str[MAXN];

void load() {
    scanf("%d%d", &n, &m);
}
void work() {

}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        load();
        work();
        printf("Case #%d:", t);
    }
}
