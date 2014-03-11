#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

class Sbt {
public:
    static const int Inf = INT_MAX;
    static const bool Left = 0;
    static const bool Right = 1;
private:
    struct Tnode;
    typedef Tnode *Tptr;
    struct Tnode {
        int val;
        int size;
        Tptr son[2];
        Tnode(int ival, Tptr inil): val(ival), size(1) {
            son[Left] = son[Right] = inil;
        }
        inline void update() {
            size = 1+son[Left]->size+son[Right]->size;
        }
    } *root, *nil;
    inline void rotate(Tptr &rt, bool side) {
        Tptr tmp = rt->son[side];
        rt->son[side] = tmp->son[!side];
        rt->update();
        tmp->son[!side] = rt;
        tmp->update();
        rt = tmp;
    }
    void maintain(Tptr &rt, bool side) {
        if (nil == rt)
            return ;
        if (rt->son[side]->son[side]->size > rt->son[!side]->size)
            rotate(rt,side);
        else if (rt->son[side]->son[!side]->size > rt->son[!side]->size) {
            rotate(rt->son[side],!side);
            rotate(rt,side);
        } else
            return ;
        maintain(rt->son[Left],Left);
        maintain(rt->son[Right],Right);
        maintain(rt,Left);
        maintain(rt,Right);
    }
    void tree_insert(Tptr &rt, int val) {
        if (nil == rt) {
            rt = new Tnode(val,nil);
            return ;
        }
        if (val == rt->val)
            return ;
        bool side = val > rt->val;
        tree_insert(rt->son[side],val);
        rt->update();
        maintain(rt,side);
    }
    void tree_del(Tptr &rt, int val) {
        if (nil == rt)
            return ;
        bool side;
        if (val == rt->val) {
            if (nil == rt->son[Left]) {
                delete rt;
                rt = rt->son[Right];
                return ;
            }
            if (nil == rt->son[Right]) {
                delete rt;
                rt = rt->son[Left];
                return ;
            }
            Tptr tmp = rt->son[Right];
            while (nil != tmp->son[0])
                tmp = tmp->son[0];
            rt->val = tmp->val;
            tree_del(rt->son[Right],rt->val);
            side = Right;
        } else {
            side = val > rt->val;
            tree_del(rt->son[side],val);
        }
        rt->update();
        maintain(rt,!side);
    }
    int tree_select(Tptr rt, int kth) {
        int lsize = rt->son[Left]->size;
        if (lsize == kth)
            return rt->val;
        if (lsize > kth)
            return tree_select(rt->son[Left],kth);
        return tree_select(rt->son[Right],kth-lsize-1);
    }
    int tree_rank(Tptr rt, int val) {
        if (nil == rt)
            return 0;
        if (val <= rt->val)
            return tree_rank(rt->son[Left],val);
        return 1+rt->son[Left]->size+tree_rank(rt->son[Right],val);
    }
    void dfs(Tptr rt) {
        if (nil == rt)
            return ;
        dfs(rt->son[Left]);
        cout << rt->val << endl;
        dfs(rt->son[Right]);
    }
public:
    Sbt() {
        nil = new Tnode(0,0);
        nil->size = 0;
        nil->son[Left] = nil->son[Right] = nil;
        root = nil;
    }
    inline void ins(int val) {
        tree_insert(root,val);
    }
    inline void del(int val) {
        tree_del(root,val);
    }
    inline int sel(int kth) {
        if (root->size < kth)
            return Inf;
        return tree_select(root,kth-1);
    }
    inline int ran(int val) {
        return tree_rank(root,val);
    }
    void walk() {
        dfs(root);
    }
} tree;
int n, m;
const int MAXN = 50010;
int seat[MAXN];
int main() {
    while (scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i)
            tree.ins(i);
        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d", &t);
            seat[i] = tree.sel(t);
            tree.del(seat[i]);
        }
        scanf("%d", &m);
        bool flag = true;;
        for (int i = 1; i <= m; ++i) {
            int t;
            if (flag)
                flag = false;
            else
                putchar(' ');
            scanf("%d", &t);
            printf("%d", seat[t]);
        }
        putchar('\n');
    }
    return 0;
}
