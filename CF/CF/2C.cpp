/*
求平面内一点到三个给定圆的张角相等，若存在多个，求出张角最大的
*/
/*
模拟退火：模拟退火的关键是构造一个评估函数，然后由此评估函数来模拟，
退火到最优值。
我的评估函数是点到三个圆张角的方差。然后先取其实点是三个圆圆心的中心点。
还有就是由于题目要求如果存在多解的话要张角越大越好，显然张角越大，点里圆越近，
所以初始偏移量delta要取初始点与三圆距离最近的那个距离。
然后就可以模拟退火了。代码很简单，也很短，而且不大容易出错。
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;
const double INF = 1e100;
struct Cir {
    double x, y, r;
} c[3], curP, bestP, l, r;
double curE, bestE;

double dis(const Cir &a, const Cir &b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double eval(const Cir &T) {
    if (T.x < l.x || T.x > r.x) return INF;
    if (T.y < l.y || T.y > r.y) return INF;
    double ratio[3] = {0}, avg = 0, ret = 0;
    for (int i = 0; i < 3; ++i) {
        avg += ratio[i] = c[i].r/dis(T,c[i]);
    }
    avg /= 3;
    for (int i = 0; i < 3; ++i)
        ret += pow(ratio[i]-avg,2)/3;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 3; ++i) {
        cin >> c[i].x >> c[i].y >> c[i].r;
        curP.x += c[i].x/3;
        curP.y += c[i].y/3;
    }
    l.x = r.x = c[0].x, l.y = r.y = c[0].y;
    for (int i = 1; i < 3; ++i) {
        l.x = min(l.x,c[i].x);
        r.x = max(r.x,c[i].x);
        l.y = min(l.y,c[i].y);
        r.y = max(r.y,c[i].y);
    }

    bestE = eval(curP);
    bestP = curP;

    double step = dis(curP,c[0]);
    for (int i = 1; i < 3; ++i)
        step = min(step,dis(curP,c[i]));

    for ( ; step > eps; step*=0.88)
        for (int k = 0; k < 20; ++k) {
            double delta = rand();
            Cir tmp;
            tmp.x = curP.x+step*cos(delta);
            tmp.y = curP.y+step*sin(delta);
            double ne = eval(tmp);
            if (bestE > ne) {
                bestP = curP = tmp;
                bestE = ne;
            }
        }
    cout << fixed << setprecision(5);
    if (bestE < eps)
        cout << bestP.x << ' ' << bestP.y << endl;
    return 0;
}
