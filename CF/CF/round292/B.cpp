#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cctype>
#include <bitset>
using namespace std;

const int MAXN = 2005;
char table[MAXN][MAXN];
char newtable[MAXN][MAXN];
int n, m;

bool mark()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] != '.') {
                continue;
            }
            if (table[i][j+1] == '.') {
                table[i][j] = '<';
                table[i][j+1] = '>';
                continue;
            }
            if (table[i+1][j] == '.') {
                table[i][j] = '^';
                table[i+1][j] = 'v';
                continue;
            }
            return false;
        }
    }
    return true;
}

bool remark()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (newtable[i][j] != '.') {
                continue;
            }
            if (newtable[i+1][j] == '.') {
                newtable[i][j] = '^';
                newtable[i+1][j] = 'v';
                continue;
            }
            if (newtable[i][j+1] == '.') {
                newtable[i][j] = '<';
                newtable[i][j+1] = '>';
                continue;
            }
            return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (newtable[i][j] != table[i][j]) {
                return false;
            }
        }
    }
    return true;
}

typedef pair<int, int> pi;
typedef pair<pi, int> pii;
queue<pii> que;
#define X first.first
#define Y first.second
#define Z second

pii mp(int a, int b, int c)
{
    return make_pair(make_pair(a,b),c);
}

int step[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

pi get(int x, int y)
{
    int ct = 0;
    int dir = -1;
    for (int i = 0; i < 4; ++i) {
        int nx = x+step[i][0];
        int ny = y+step[i][1];
        if (table[nx][ny] == '.') {
            ++ct;
            dir = i;
        }
    }
    return make_pair(ct, dir);
}

bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (table[i][j] != '.') {
                continue;
            }
            ++sum;
            pi tmp = get(i,j);
            if (tmp.first == 1) {
                que.push(mp(i, j, tmp.second));
            }
        }
    }
    while (que.size()) {
        pii tmp = que.front();
        que.pop();
        int nx = tmp.X+step[tmp.Z][0], ny = tmp.Y+step[tmp.Z][1];
        if (table[nx][ny] != '.') {
            continue;
        }
        sum -= 2;
        if (nx == tmp.X) {
            table[nx][min(tmp.Y, ny)] = '<';
            table[nx][max(tmp.Y, ny)] = '>';
        } else {
            table[min(tmp.X, nx)][ny] = '^';
            table[max(tmp.X, nx)][ny] = 'v';
        }
        for (int i = 0; i < 4; ++i) {
            int sx = nx+step[i][0], sy = ny+step[i][1];
            if (table[sx][sy] != '.') {
                continue;
            }
            pi delta = get(sx, sy);
            if (delta.first == 1) {
                que.push(mp(sx, sy, delta.second));
            }
        }
    }
    return sum == 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", table[i]+1);
    }
    memcpy(newtable, table, sizeof(table));
    if (check()) {
        for (int i = 1; i <= n; ++i) {
            puts(table[i]+1);
        }
    } else {
        puts("Not unique");
    }
}
