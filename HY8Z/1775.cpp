/* TODO (#1#): �������ı�������
               ����һ��1007���㼸�������о�һ��*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 100010;
int n, v;
int f[MAXN], g[MAXN];
inline int max(int a, int b) {
    return a>b?a:b;
}
int main() {
    scanf("%d%d", &n, &v);
    int mwt, num;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &mwt, &num);
        for (int j = mwt; j <= v; ++j)
            g[j] = f[j-mwt];
        int pr, val;
        for (int j = 1; j <= num; ++j) {//�������Ʒ���н���һ��01���� 
            scanf("%d%d", &pr, &val);
            for (int k = v; k >= pr+mwt; --k)
                g[k] = max(g[k],g[k-pr]+val);
        }
        for (int j = mwt; j <= v; ++j)
            f[j] = max(f[j],g[j]);
    }
    printf("%d\n", f[v]);
//    system("pause");
    return 0;
}
