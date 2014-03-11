// Note: 不要太省代码，也不要乱用优先级，要不然一个很小的错误会把你直接拖垮 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
const int MAXN = 200050;
const int INF = 52111425;
int n, d;
// 这是线段树的版本 
inline int max(int a, int b) {
    return a>b?a:b;
}
struct node {
    int val;
    node(int _val = -INF): val(_val) { }
    friend node operator+(const node &left, const node &right) {
        if (left.val == -INF)
            return right;
        if (right.val == -INF)
            return left;
        return node(max(left.val,right.val));
    }
};
class interval_tree {
private:
    node tarray[MAXN*2];
    int size;
public:
    interval_tree(): size(0) { }
    int query(int len) {
        node lpart, rpart;
        int ed = size+n+1;
        int bg = ed-len-1;
        for (; bg^ed^1; bg >>= 1, ed >>= 1) {
            if (~bg&1)
                lpart = lpart+tarray[bg+1];
            if (ed&1)
                rpart = tarray[ed-1]+rpart;
        }
        return (lpart+rpart).val;
    }
    void insert(int num) {
        int pos = (++size)+n;
        tarray[pos] = num;
        for (pos >>= 1; pos; pos >>= 1)
            tarray[pos] = tarray[pos<<1]+tarray[(pos<<1)+1];
    }
} tree;
/*
void test() {
    n = 200000;
    srand(time(0));
    for (int i = 1; i <= n; ++i)
        tree.insert(rand());
    int len;
    while (cin >> len)
        cout << tree.query(len) << endl;
} */
int work1() {
//    test();
    scanf("%d%d", &n, &d);
    char ch;
    int tmp;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        while (getchar() != '\n')
            continue;
        scanf("%c%d", &ch, &tmp);
        if ('Q' == ch) {
            t = tree.query(tmp);
            printf("%d\n", t);
        } else
            tree.insert((tmp+t)%d);
    }
    return 0;
}

int main() {
    return work1();
} 
