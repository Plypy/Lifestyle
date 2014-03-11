#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 15005;
class Sbt {
private:
    static const bool Left = 0;
    static const bool Right = 1;
    struct Tnode;
    typedef Tnode * Tptr;
    struct Tnode {
        int val;
        int size;
        int num;
        int tot;
        Tptr son[2];
        Tnode(int ival, Tptr inil):
            val(ival), size(1), num(1), tot(1) {
            son[Left] = son[Right] = inil;
        }
        void update() {
            size = 1+son[Left]->size+son[Right]->size;
            tot = num+son[Left]->tot+son[Right]->tot;
        }
    } *root, *nil;
    void rotate(Tptr &rt, bool side) {
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
        } else {
            return ;
        }
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
        if (val == rt->val) {
            ++rt->num;
            ++rt->tot;
            return ;
        }
        bool side = val>rt->val;
        tree_insert(rt->son[side],val);
        rt->update();
        maintain(rt,side);
    }
    int tree_rank(Tptr rt, int val) {
        if (nil == rt)
            return 0;
        if (val < rt->val)
            return tree_rank(rt->son[Left],val);
        return rt->tot - rt->son[Right]->tot + tree_rank(rt->son[Right],val);
    }
public:
    Sbt() {
        nil = new Tnode(0,0);
        nil->tot = nil->num = nil->size = 0;
        nil->son[Left] = nil->son[Right] = nil;
        root = nil;
    }
    void insert(int val) {
        tree_insert(root,val);
    }
    int rank(int val) {
        return tree_rank(root,val);
    }
} tree;

int ans[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++ans[tree.rank(x)];
        tree.insert(x);
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    system("pause");
    return 0;
}
