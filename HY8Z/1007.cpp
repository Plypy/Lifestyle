//���㼸�Ρ�����ƽ���ཻ����
//��ϰSTL 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
struct Line {
    int a, b;
    int id;
    friend bool operator<(const Line &p, const Line &q) {
        if (p.a < q.a)
            return true;
        if (p.a == q.a && q.b < p.b)
            return true;
        return false;
    }
    double operator*(const Line &t) {
        return double(b-t.b)/(t.a-a);
    }
};
Line ar[MAXN];
int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &ar[i].a, &ar[i].b);
        ar[i].id = i;
    }
}
int st[MAXN];
int top;
bool in[MAXN];
void work() {
    sort(ar+1,ar+n+1);
    for (int i = 1; i <= n; ++i) {
        if (ar[i].a == ar[i-1].a)
            continue;
        while (top>1 && ar[i]*ar[st[top]] <= ar[st[top]]*ar[st[top-1]])
                                    // �жϽ������λ�ã�����ͼ�ͺ������� 
            --top;
        st[++top] = i;
    }
    for (int i = 1; i <= top; ++i)
        in[ar[st[i]].id] = true;
    bool first = true;
    for (int i = 1; i <= n; ++i)
        if (in[i]) {
            if (first)
                first = false;
            else
                printf(" ");
            printf("%d", i);
        }
    printf("\n");
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
} 
