// ��ɢ�������״����
// Note Ϊʲô��������״�����أ� ��Ϊ�����������ֻ��Ҫ����֮��Ĵ�С��ϵ
// Ҳ����˵����֮����򣬶����ݵľ����ֵ������ν�ģ����ԾͿ��Կ�����ɢ��
// Ȼ���ٲ�����״������⣬���������Ļ��㷨��Ȼ�����ߵģ���ʵ���л��ǲ�������Ҫ��
// �����㷨���ÿ�����ƽ�������߶���֮��� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 15005;
typedef class TreeArray {
private:
    int ar[MAXN];
    int lowbit(int a) {
        return a&-a;
    }
    int size;
public:
    TreeArray(int initsize) {
        size = initsize;
        memset(ar,0,sizeof(ar));
    }
    void insert(int a) {
        for (; a <= size; a += lowbit(a) )
            ++ar[a];
    }
    int get(int a) {
        int ret = 0;
        for (; a; a -= lowbit(a) )
            ret += ar[a];
        return ret;
    }
} Tarray;
struct Data {
    int val;
    int id;
    friend bool operator<(const Data &a, const Data &b) {// sort��С�ں�Ĭ���ų��ֵ���priority_queue����Ĭ���ų����ֵ��� 
        if (a.val != b.val)                         // Ҳ����˵sortĬ������ priority_queueĬ�Ͻ��� ������μ� 
            return a.val < b.val;
        return a.id < b.id;
    }
} data[MAXN];
int n;
void load() {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &data[i].val, &tmp);
        data[i].id = i;
    }
}
int ans[MAXN];
void work() {
    sort(data+1,data+n+1);
    for (int i = 1; i <= n; ++i)
        data[data[i].id].val = i;
    Tarray tree(n);
    for (int i = 1; i <= n; ++i) {
        ++ans[tree.get(data[i].val)];
        tree.insert(data[i].val);
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
//    system("pause");
}
int main() {
    load();
    work();
}
