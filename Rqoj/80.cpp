#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 101;
struct Point {
    double x, y;
    friend bool operator<(const Point &a, const Point &b) {
        if (a.x < b.x)
            return true;
        else if (a.x == b.x && a.y < b.y)
            return true;
        return false;
    }
};

struct Line {
    int k, b;
    friend Point intersect(const Line &a, const Line &b) {
        Point ret;
        ret.x = double(b.b-a.b)/(a.k-b.k);
        ret.y = a.k*ret.x+a.b;
        return ret;
    }
} line[MAXN];
int n;

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &line[i].k, &line[i].b);
}

void work() {
    set<Point> table;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (line[i].k != line[j].k)
                table.insert(intersect(line[i],line[j]));
    if (table.size())
        printf("%d\n", table.size());
    else
        printf("No Fire Point.\n");
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
