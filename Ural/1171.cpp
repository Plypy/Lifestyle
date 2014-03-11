/**
 * Todo
 * Description: A dp problem from Hardest set
 * Solution
 * Author: Ply_py
 */
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
#include <cmath>
using namespace std;

const int MAXN =17;
const int MAXL = 66000;
int f[MAXN][MAXL][4][4];

int food[MAXN][4][4];
bool down[MAXN][4][4];
int n;
void work() {

}
void load() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x < 4; ++x)
            for (int y = 1; y < 4; ++y)
                cin >> food[i][x][y];
    }
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x < 4; ++x)
            for (int y = 1; y < 4; ++y)
                cin >> down[i][x][y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}

