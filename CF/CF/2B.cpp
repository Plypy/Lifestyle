// ���������д���0
// ��ôֻҪ�����ڲ�������׺0��·����ѡ����������0��·������
// ���Խ����е�0�滻��10��Ȼ����һ��𰸣���������һ��û�к�׺0��·������ô��ѡ���·��
// ���û�еĻ��͵�ѡ�Ǹ�����0��·��
//
// ���е����ݾ�Ϊ�������
// ���еĺ�׺0������2��5���������Ӵճɵģ��Һ�׺0�ĸ���Ϊ���˻���ʽ�ֽ���2��5����֮���С��һ��
// ��ô���Զ�������2������5�ֱ���һ��
// ���𰸾������н�С��һ��
// ���������ݶ�ά�������ʱ���������һά֮�����ȷ������ά�Ĵ�С
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int mat[MAXN][MAXN];
int n2[MAXN][MAXN], n5[MAXN][MAXN];
int n;
int getmp(int t, int b) {
    int ret = 0;
    while (0 == t%b) {
        ++ret;
        t /= b;
    }
    return ret;
}
bool zero;
int zx, zy;
void load() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> mat[i][j];
            if (0 == mat[i][j]) {
                mat[i][j] = 10;
                if (!zero) {
                    zero = true;
                    zx = i;
                    zy = j;
                }
            }
            n2[i][j] = getmp(mat[i][j],2);
            n5[i][j] = getmp(mat[i][j],5);
        }
}
int f2[MAXN][MAXN], f5[MAXN][MAXN];
void op(int f[][MAXN], int t[][MAXN]) {
    for (int i = 1; i <= n; ++i) {
        f[i][1] = f[i-1][1]+t[i][1];
        f[1][i] = f[1][i-1]+t[1][i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (f[i-1][j] < f[i][j-1])
                f[i][j] = t[i][j]+f[i-1][j];
            else
                f[i][j] = t[i][j]+f[i][j-1];
        }
    }
}
void out(int f[][MAXN], int i, int j) {
    if (1 == i) {
        if (j != 1) {
            out(f,i,j-1);
            putchar('R');
        }
    } else if (1 == j) {
        out(f,i-1,j);
        putchar('D');
    } else {
        if (f[i-1][j] < f[i][j-1]) {
            out(f,i-1,j);
            putchar('D');
        } else {
            out(f,i,j-1);
            putchar('R');
        }
    }
}
void work() {
    op(f2,n2);
    op(f5,n5);
    int mans = min(f2[n][n], f5[n][n]);
    if (zero && mans > 0) {
        printf("1\n");
        int i, j;
        for (i = 1; i < zx; ++i)
            putchar('D');
        for (j = 1; j < zy; ++j)
            putchar('R');
        for (; i < n; ++i)
            putchar('D');
        for (; j < n; ++j)
            putchar('R');
        putchar('\n');
    } else {
        printf("%d\n", mans);
        if (f2[n][n] < f5[n][n])
            out(f2,n,n);
        else
            out(f5,n,n);
    }
}
int main() {
    load();
    work();
    return 0;
}
