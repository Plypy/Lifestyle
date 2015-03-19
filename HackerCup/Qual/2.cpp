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
#include <bitset>
#include <stack>
using namespace std;

#define A first
#define B second.first
#define C second.second

typedef pair<int, pair<int, int> > pi2;
inline pi2 make_pi2(int a, int b, int c)
{
    return make_pair(a,make_pair(b,c));
}


int gp, gc, gf;
set<pi2> has;
int n;
pi2 food[200];

void init()
{
    has.clear();
    has.insert(make_pi2(0,0,0));
}

bool find(int p, int c, int f)
{
    if (p < 0 || c < 0 || f < 0) {
        return false;
    }
    if (has.count(make_pi2(p,c,f))) {
        return true;
    }
    bool ret = false;
    for (int i = 1; i <= n; ++i) {
        if (find(p - food[i].A, c - food[i].B, f - food[i].C)) {
            ret = true;
            break;
        }
    }
    if (ret) {
        has.insert(make_pi2(p,c,f));
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        init();
        cin >> gp >> gc >> gf;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> food[j].A >> food[j].B >> food[j].C;
        }
        cout << "Case #" << i << ": ";
        if (find(gp, gc, gf)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
