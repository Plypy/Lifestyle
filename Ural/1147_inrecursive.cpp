// 这个是非递归版本的矩形切割，是可以ac的，不过由于我的构造函数做了很多无用操作
// 悲剧超时- -，只要把这些构造函数换成普通的赋值就能过了 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct Rectangle {
    int llx, lly;
    int urx, ury;
    int col;
    Rectangle() { }
    Rectangle(int illx, int illy, int iurx, int iury, int icol):
        llx(illx), lly(illy), urx(iurx), ury(iury), col(icol) { }
} Rect;

Rect table[700000];
int top;

void cut(int pos, const Rect &upper) {
    if (table[pos].llx >= upper.urx || table[pos].urx <= upper.llx ||
        table[pos].lly >= upper.ury || table[pos].ury <= upper.lly )
        return ;
    if (table[pos].llx < upper.llx) {
        table[++top] = Rect(table[pos].llx, table[pos].lly, upper.llx, table[pos].ury, table[pos].col);
        table[pos].llx = upper.llx;
    }
    if (table[pos].urx > upper.urx) {
        table[++top] = Rect(upper.urx, table[pos].lly, table[pos].urx, table[pos].ury, table[pos].col);
        table[pos].urx = upper.urx;
    }
    if (table[pos].lly < upper.lly)
        table[++top] = Rect(table[pos].llx, table[pos].lly, table[pos].urx, upper.lly, table[pos].col);
    if (table[pos].ury > upper.ury)
        table[++top] = Rect(table[pos].llx, upper.ury, table[pos].urx, table[pos].ury, table[pos].col);
    table[pos] = table[top--];
}
int area[2501];
void work() {
    int k;
    ++top;
    scanf("%d%d%d", &table[top].urx, &table[top].ury, &k);
    table[top].col = 1;
    Rect tmp;
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d%d%d%d", &tmp.llx, &tmp.lly, &tmp.urx, &tmp.ury, &tmp.col);
        for (int j = top; j; --j)
            cut(j,tmp);
        table[++top] = tmp;
    }
    for (int i = 1; i <= top; ++i) {
        area[table[i].col] += (table[i].urx-table[i].llx)*(table[i].ury-table[i].lly);
    }
}

void output() {
    for (int i = 1; i <= 2500; ++i)
        if (area[i])
            printf("%d %d\n", i, area[i]);
//    system("pause");
}

int main() {
    work();
    output();
    return 0;
}
