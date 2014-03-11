// Note 结构和类之类的也可以像函数一样先声明再定义，这个我以前一直不知道- -
// 真失败啊，这个功能就是前向声明. 
// 这次我用的是Treap，主要是练手
// 然后这次的就是在线版的了 hohoho 1A
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
const int MAXN = 15005;
class Treap {
public:
    static const int INF = 52111425;
private:
    struct Tnode;
    typedef Tnode * Tptr;
    struct Tnode {
        int val;
        int priority;
        int size;
        int num;
        Tptr son[2];
        Tnode(int ival, Tptr inil): val(ival), priority(rand()), size(1), num(1) {
            son[0] = son[1] = inil;
        }
        void resize() {
            size = son[0]->size+son[1]->size+num;
        }
    } *root, *nil;
    void rotate(Tptr &ptr, bool side) {
        Tptr tmp = ptr->son[side];
        ptr->son[side] = tmp->son[!side];
        ptr->resize();
        tmp->son[!side] = ptr;
        tmp->resize();
        ptr = tmp;
    }
    void tree_insert(Tptr &pos, int val) {
        if (nil == pos) {
            pos = new Tnode(val,nil);
            return ;
        }
        if (pos->val == val) {
            ++pos->num;
            ++pos->size;
            return ;
        }
        bool side = val>pos->val;
        tree_insert(pos->son[side],val);
        if (pos->son[side]->priority < pos->priority)
            rotate(pos,side);
        else
            pos->resize();
    }
    int tree_rank(Tptr pos, int val) {
        if (pos == nil)
            return 0;
        int rsize = pos->son[1]->size;
        if (val < pos->val)
            return tree_rank(pos->son[0],val);
        else
            return pos->size-rsize+tree_rank(pos->son[1],val);
    }
public:
    Treap() {
        srand(time(0));
        nil = new Tnode(0,0);
        nil->size = nil->num = 0;
        nil->priority = INF;
        root = nil;
    }
    void insert(int x) {
        tree_insert(root,x);
    }
    int rank(int x) {
        return tree_rank(root,x);
    }
} tree;
int ans[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++ans[tree.rank(x)];
        tree.insert(x);
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
//    system("pause");
    return 0;
}
