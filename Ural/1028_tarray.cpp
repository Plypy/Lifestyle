// 离散化后搞树状数组
// Note 为什么可以用树状数组呢， 因为这道题中我们只需要数据之间的大小关系
// 也就是说数据之间的序，而数据的具体的值是无所谓的，所以就可以考虑离散化
// 然后再采用树状数组求解，不过这样的话算法必然是离线的，在实际中还是不能满足要求
// 在线算法还得靠各种平衡树，线段树之类的 
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
    friend bool operator<(const Data &a, const Data &b) {// sort靠小于号默认排出字典序，priority_queue则是默认排出逆字典序 
        if (a.val != b.val)                         // 也就是说sort默认升序， priority_queue默认降序， 这个得牢记 
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
