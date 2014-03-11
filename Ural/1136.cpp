//水题，相当于给了后序和中序，再按要求输出 

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 3010;

int n;
int back[MAXN], mid[MAXN];


void work(int a, int b, int c, int d) {
    int chair = back[b];
    int all = b-a+1;
    int lct = 0, rct = 0;
    for (int i = c; i <= d; ++i, ++lct)
        if (chair == mid[i])
            break;
    rct = all-lct-1;
    if (rct)
        work(a+lct,a+lct+rct-1,c+lct+1,c+lct+rct);
    if (lct)
        work(a,a+lct-1,c,c+lct-1);
    printf("%d ", chair);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", back+i);
        mid[i] = back[i];
    }
    sort(mid+1,mid+n+1);
    work(1,n,1,n);
//    system("pause");
    return 0;
} 
