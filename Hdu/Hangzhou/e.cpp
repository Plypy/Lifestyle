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

const int MAXN = 500005;
const int MAXP = 20;

int n, m, p;

void init() {

}

int work() {
    if (p >= MAXP) {
        return n*m;
    }
}

void load() {
    scanf("%d%d%d", &n, &m, &p);
}
int main(int argc, char const *argv[]) {

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        work();
    }
    return 0;
}