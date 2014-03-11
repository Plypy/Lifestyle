// 这题有一个隐含的性质就是一个结点的编号一定是小于其父结点的编号的 
// 如果没有这个性质的话就不能直接套用动态规划了，得先按结点的深度排序才行 
// 不过还存在另一种不依赖序的做法就是根据一个定理
// 树的中心为树上最长链的中点

// Note: 宏很可怕，慎用。。。 尤其是宏函数，一定要把每个变量都用括号括起来
// 因为宏只是简单的在预处理的时候进行替换而已 
#include <stdio.h>
#include <stdlib.h>
#define MAXN 10005
#define INF 52111425
int max(int a, int b) {
    return a>b?a:b;
}

int p[MAXN];
int n;

void load() {
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i)
        scanf("%d", p+i);
}


int f[MAXN], id[MAXN];//最长的以及是从哪个结点转移来的 
int g[MAXN];//次长的 
int h[MAXN];
int anslist[2]; // 可以保证最多只有两个中心 

void work() {
    for (int i = n; i > 1; --i) {
        int pa = p[i];
        if (f[i]+1 > f[pa]) {
            id[pa] = i;
            g[pa] = f[pa];
            f[pa] = f[i]+1;
        } else if (f[i]+1 > g[pa]) {
            g[pa] = f[i]+1;
        }
    } // 从叶结点向上更新解 
//    for (int i = 1; i <= n; ++i)
//        printf("%d %d\n", f[i], g[i]);
//    putchar('\n');
    
    for (int i = 2; i <= n; ++i) {
        int pa = p[i];
        if (id[pa] != i) {
            h[i] = max(h[pa],f[pa])+1;
        } else {
            h[i] = max(h[pa],g[pa])+1;
        }
    } // 从根结点向下更新解 
//    for (int i = 1; i <= n; ++i)
//        printf("%d %d\n", f[i], h[i]);
//    putchar('\n');
    
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        f[i] = max(f[i],h[i]);
        if (f[i] < ans) {
            anslist[0] = i;
            ans = f[i];
        }
        else if (f[i] == ans) {
            anslist[1] = i;
        }
    }
//    for (int i = 1; i <= n; ++i)
//        printf("%d ", f[i]);
//    putchar('\n');
}

void output() {
    printf("%d", anslist[0]);
    if (f[anslist[1]] == f[anslist[0]])
        printf(" %d", anslist[1]);
    putchar('\n');
}

int main() {
    load();
    work();
    output();
//    system("pause");
    return 0;
}
