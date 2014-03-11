// ������һ�����������ʾ���һ�����ı��һ����С���丸���ı�ŵ� 
// ���û��������ʵĻ��Ͳ���ֱ�����ö�̬�滮�ˣ����Ȱ��������������� 
// ������������һ�ֲ���������������Ǹ���һ������
// ��������Ϊ����������е�

// Note: ��ܿ��£����á����� �����Ǻ꺯����һ��Ҫ��ÿ��������������������
// ��Ϊ��ֻ�Ǽ򵥵���Ԥ�����ʱ������滻���� 
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


int f[MAXN], id[MAXN];//����Լ��Ǵ��ĸ����ת������ 
int g[MAXN];//�γ��� 
int h[MAXN];
int anslist[2]; // ���Ա�֤���ֻ���������� 

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
    } // ��Ҷ������ϸ��½� 
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
    } // �Ӹ�������¸��½� 
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
