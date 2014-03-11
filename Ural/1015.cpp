#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAXN 10005
using namespace std;

struct Lnode {
    Lnode *nxt;
    int val;
    Lnode(int ival = 0, Lnode *inxt = 0):
        val(ival), nxt(inxt) { }
} head[MAXN];
bool vis[MAXN];

// initial order
// left right top forward bottom backward
const int tran[7][7] = {
    {0,0,0,0,0,0,0},
    {0,1,2,3,4,5,6},
    {0,2,1,3,6,5,4},
    {0,5,3,1,4,2,6},
    {0,6,4,3,1,5,2},
    {0,3,5,2,4,1,6},
    {0,4,6,3,2,5,1}
}; // - -·Ñ¾¢ 
const int mov[5][5] = {
    {0,0,0,0,0},
    {0,3,4,5,6},
    {0,6,3,4,5},
    {0,5,6,3,4},
    {0,4,5,6,3}
}; // ¸ü·Ñ¾¢ 
const int fac[7] = {1,1,2,6,24,120,720};
int table[720];
int cantor(int a[]) {
    int ret = 0;
    static bool used[7];
    memset(used,0,sizeof(used));
    for (int i = 1; i < 6; ++i) {
        used[a[i]] = true;
        int t = a[i]-1;
        for (int j = 1; j < a[i]; ++j)
            if (used[j])
                --t;
        ret += t*fac[6-i];
    }
    return ret;
}
void change(int a[]) {
    int pos1;
    for (int i = 1; i <= 6; ++i)
        if (1 == a[i]) {
            pos1 = i;
            break;
        }
    int tmp[7];
    for (int i = 1; i <= 6; ++i)
        tmp[tran[pos1][i]] = a[i];
    int mpos = 3;
    for (int i = 4; i <= 6; ++i)
        if (tmp[i] < tmp[mpos])
            mpos = i;
    a[1] = tmp[1];
    a[2] = tmp[2];
    mpos -= 2;
    for (int i = 3; i <= 6; ++i)
        a[mov[mpos][i-2]] = tmp[i];
}
    
int n;
int main() {
    scanf("%d", &n);
    int tdie[7] = {0};
    int tsche = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = Lnode(i,0);
        for (int j = 1; j < 7; ++j)
            scanf("%d", tdie+j);
        change(tdie);
        int pos = cantor(tdie);
        if (table[pos])
            head[table[pos]].nxt = head+i;
        else
            ++tsche;
        table[pos] = i;
    }
    
    printf("%d\n", tsche);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            int j = i;
            while (true) {
                vis[j] = true;
                printf("%d", j);
                if (!head[j].nxt)
                    break;
                putchar(' ');
                j = head[j].nxt->val;
            }
            putchar('\n');
        }
//    system("pause");
    return 0;
}
