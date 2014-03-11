#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 20;

struct Vector {
    int x, y;
    Vector(int ix = 0, int iy = 0): x(ix), y(iy) { }
    int operator*(const Vector &T) const {
        return x*T.y-T.x*y;
    }
    Vector operator-(const Vector &T) const {
        return Vector(x-T.x,y-T.y);
    }
} pt[MAXN];

struct Triangle {
    int point[3];
    int area;
    bool operator<(const Triangle &T) const {
        return area<T.area;
    }
    void compute() {
        area = abs((pt[point[2]]-pt[point[0]])*(pt[point[1]]-pt[point[0]]));
    }
    bool isin(const Vector &T) const {/* 点恰在多边形上这种情况要特别判定，靠点积或者坐标判断 
        int sd = (T-pt[point[2]])*(T-pt[point[0]]);
        if ((T-pt[point[0]])*(T-pt[point[1]]) * sd < 0)
            return false;
        if ((T-pt[point[1]])*(T-pt[point[2]]) * sd < 0)
            return false;
        return true;*/
        int s1 = abs((T-pt[point[2]])*(T-pt[point[0]]));
        int s2 = abs((T-pt[point[0]])*(T-pt[point[1]]));
        int s3 = abs((T-pt[point[1]])*(T-pt[point[2]]));
        if (area == s1+s2+s3)
            return true;
        return false;
    }
} tri[20*19*3];
int tct;
int n;

int main() {
    while (true) {
        scanf("%d", &n);
        tct = 0;
        if (!n)
            break;
        for (int i = 1; i <= n; ++i) {
            char ch;
            while (getchar() != '\n')
                continue;
            scanf("%c%d%d", &ch, &pt[i].x, &pt[i].y);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i+1; j <= n; ++j)
                for (int k = j+1; k <= n; ++k) {
                    ++tct;
                    tri[tct].point[0] = i;
                    tri[tct].point[1] = j;
                    tri[tct].point[2] = k;
                    tri[tct].compute();
                }
        sort(tri+1,tri+1+tct);
                
        int ans = 1;
        for (int i = tct; i; --i) {
            bool flag = true;
            for (int j = 1; j <= n; ++j)
                if (j != tri[i].point[0] && j != tri[i].point[1] && j != tri[i].point[2]) {
                    if (tri[i].isin(pt[j])) {
                        flag = false;
                        break;
                    }
                }
            if (flag) {
                ans = i;
                break;
            }
        }
        for (int i = 0; i < 3; ++i)
            putchar('A'+tri[ans].point[i]-1);
        puts("");
    }
    return 0;
}
