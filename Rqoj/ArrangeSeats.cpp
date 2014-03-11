#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 1005;
struct line
{
    int id;
    int num;
    line():id(0),num(0){}
} row[MAXN], col[MAXN];
int n, m, k, l, d;
int cmp(const void *a, const void *b)
{
    int x, y;
    x = ((line *)a)->num;
    y = ((line *)b)->num;
    return y-x;
}
int cmp1(const void *a, const void *b)
{
    int x, y;
    x = ((line *)a)->id;
    y = ((line *)b)->id;
    return x-y;
}
int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
//    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
    cin >> m >> n >> k >> l >> d;
    for (int i = 1; i < m; i++)
        row[i].id = i;
    for (int i = 1; i < n; i++)
        col[i].id = i;
    int x1, y1, x2, y2;
    for (int i = 1; i <= d; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
            col[min(y1,y2)].num++;
        else if (y1 == y2)
            row[min(x1,x2)].num++;
    }
    qsort(row+1, m, sizeof(line), cmp);
    qsort(col+1, n, sizeof(line), cmp);
    qsort(row+1, k, sizeof(line), cmp1);
    qsort(col+1, l, sizeof(line), cmp1);
    for (int i = 1; i < k; i++)
        cout << row[i].id << ' ';
    cout << row[k].id << endl;
    for (int i = 1; i < l; i++)
        cout << col[i].id << ' ';
    cout << col[l].id << endl;
    return 0;
}
