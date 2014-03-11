#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int SCALE = 15;
int n;
int ix, iy;
bool loadtype() {
    // true for coordinates, flase, otherwise.
    cin >> n;
    char c = cin.get();
    if ('\n' == c)
        return true;
    ix = n;
    cin >> iy;
    return false;
}
bool map[SCALE][SCALE];
bool vis[SCALE][SCALE];
struct Point {
    int x, y;
    Point() {
        x = y = 0;
    }
    Point(int ix, int iy): x(ix), y(iy) { }
    
    friend bool operator<(const Point &a, const Point &b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
    friend ostream& operator<<(ostream &os, const Point &t) {
        os << t.x << ' ' << t.y;
        return os;
    }
};
int mov[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
char dir[4] = {
    'R', 'T', 'L', 'B'
};
void work1() {
    cin >> ix >> iy;
    Point ipt = Point(ix,iy);
    cout << ipt << endl;
    queue<Point> que;
    que.push(ipt);
    
    for (int i = 2; i <= n; ++i) {
        int tx, ty;
        cin >> tx >> ty;
        map[tx][ty] = true;
    }
    bool first = true;
    while (que.size()) {
        if (first)
            first = false;
        else
            cout << ',' << endl;
        Point tpt = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = tpt.x+mov[i][0], ty = tpt.y+mov[i][1];
            if (map[tx][ty] && !vis[tx][ty]) {
                cout << dir[i];
                vis[tx][ty] = true;
                que.push(Point(tx,ty));
            }
        }
    }
    cout << '.' << endl;
}

void work2() {
    int ct = 1;
    Point ipt = Point(ix,iy);
    queue<Point> que;
    vector<Point> plis;
    que.push(ipt);
    plis.push_back(ipt);
    while (que.size()) {
//        cout << ct << endl;
        Point tpt = que.front();
        que.pop();
        while ('\n' != cin.get())
            continue;
//        cout << "Can you see me?" << endl;
        while (true) {
            char c = cin.get();
            ++ct;
            switch (c) {
                case 'R':
                    que.push(Point(tpt.x+1,tpt.y));
                    plis.push_back(Point(tpt.x+1,tpt.y));
                    break;
                case 'T':
                    que.push(Point(tpt.x,tpt.y+1));
                    plis.push_back(Point(tpt.x,tpt.y+1));
                    break;
                case 'L':
                    que.push(Point(tpt.x-1,tpt.y));
                    plis.push_back(Point(tpt.x-1,tpt.y));
                    break;
                case 'B':
                    que.push(Point(tpt.x,tpt.y-1));
                    plis.push_back(Point(tpt.x,tpt.y-1));
                    break;
                default:
                    --ct;
                    goto outside;
            }
        }
    outside:
        ;
    }
    sort(plis.begin(), plis.end());
    cout << ct << endl;
    for (int i = 0; i < ct; ++i)
        cout << plis[i] << endl;
}

int main() {
    if (loadtype()) {
        work1();
    } else {
        work2();
    }
    //system("pause");
    return 0;
}
