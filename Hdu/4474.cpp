//����ʱ��һ���ͼ�ʧ��
//���³����˻�
//���޴����ǣ��ҿ���ջ����Ľ����Ȼû�������뵽��һ��
//������ʱ���˷����������õ��޸��ϡ���
//����δ���ʽڵ���ֵ��ѡ����Ҫ������
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int pre[MAXN], num[MAXN];
int que[MAXN];
bool fbd[10];
int n, m;
int casnum;
bool load() {
    if (EOF == scanf("%d%d", &n, &m))
        return false;
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        fbd[t] = true;
    }
    return true;
}
void init() {
    memset(fbd,0,sizeof(fbd));
    memset(pre,-1,sizeof(pre));
    memset(num,0,sizeof(num));
}
void out(int t) {
    if (pre[t])
        out(pre[t]);
    printf("%d", num[t]);
}
void work() {
    printf("Case %d: ", ++casnum);
    int head = 0, tail = 0;
    for (int i = 1; i < 10; ++i)
        if (!fbd[i] && 0 == i%n) {
            printf("%d\n", i);
            return ;
        }
    for (int i = 1; i < 10; ++i)
        if (!fbd[i]) {
            if (-1 == pre[i%n]) {
                pre[i%n] = 0;
                num[i%n] = i;
                que[tail++] = i%n;
            }
        }
    while (head < tail) {
        int u = que[head++];
        for (int i = 0; i < 10; ++i)
            if (!fbd[i]) {
                int v = (u*10+i)%n;
                if (0 == v) {
                    out(u);
                    printf("%d\n", i);
                    return ;
                }
                if (-1 == pre[v]) {
                    num[v] = i;
                    pre[v] = u;
                    que[tail++] = v;
                }
            }
    }
    printf("-1\n");
}
int main() {
    while (true) {
        init();
        if (!load())
            break;
        work();
    }
    return 0;
}
