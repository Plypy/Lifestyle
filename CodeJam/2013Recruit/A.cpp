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

const int MAXM = 105;
const int MAXN = 2*MAXM;

int m;
map<string,int> table;
string query[MAXM][2];
int ct;
int cal(int a, int b) {
    return 2*a+b;
}
int inv(int a) {
    if (a&1)
        return a-1;
    return a+1;
}
const int MAXV = 2*MAXN;
int f[MAXV];
void clear() {
    ct = 0;
    table.clear();
}
int find(int a) {
    if (f[a] == a)
        return a;
    return f[a] = find(f[a]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    f[a] = b;
}
bool work() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            string &name = query[i][j];
            if (0 == table.count(name)) {
                table[name] = ct++;
            }
        }
    }
    for (int i = 0; i < 2*ct; ++i)
        f[i] = i;
    for (int i = 0; i < m; ++i) {
        int a = table[query[i][0]];
        int b = table[query[i][1]];
        merge(cal(a,0),cal(b,1));
        merge(cal(a,1),cal(b,0));
    }
    for (int i = 0; i < 2*ct; i += 2) {
        if (find(i) == find(i+1)) {
            return false;
        }
    }
    return true;
}

void load() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> query[i][0] >> query[i][1];
    }
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        load();
        cout << "Case #" << i << ": ";
        if (work()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}