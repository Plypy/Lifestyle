#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class Treap {
private:
    struct Tnode {
        int key, priority;
        Tnode *l, *r;
        Tnode(int ikey, int ipriority, Tnode *il = 0, Tnode *ir = 0):
            key(ikey), priority(ipriority), l(il), r(ir) { }
    };
    inline void r_rot(Tnode* &ptr) {
        Tnode *tmp = ptr->l;
        ptr->l = tmp->r;
        tmp->r = ptr;
        ptr = tmp;
    }
    inline void l_rot(Tnode* &ptr) {
        Tnode *tmp = ptr->r;
        ptr->r = tmp->l;
        tmp->l = ptr;
        ptr = tmp;
    }
public:
    Tnode *root;
    Treap() {
        root = 0;
    }
    void insert(int val, Tnode* &ptr) {
        if (0 == ptr) {
            ptr = new Tnode(val,rand());
            return ;
        }
        if (val < ptr->key) {
            insert(val,ptr->l);
            if (ptr->l->priority > ptr->priority)
                r_rot(ptr);
        } else {
            insert(val,ptr->r);
            if (ptr->r->priority > ptr->priority)
                l_rot(ptr);
        }
    }
    void del(Tnode* &ptr) {
        int tmp = -1;
        if (ptr->l)
            tmp = ptr->l->priority;
        if (ptr->r && tmp < ptr->r->priority) {
            l_rot(ptr);
            del(ptr->l);
        } else if (ptr->l) {
            r_rot(ptr);
            del(ptr->r);
        } else {
            delete ptr;
            ptr = 0;
        }
    }
    inline int pop_min() {
        Tnode *ptr = root, *fa = 0;
        while (ptr->l) {
            fa = ptr;
            ptr = ptr->l;
        }
        int ret = ptr->key;
        if (fa)
            del(fa->l);
        else
            del(root);
        return ret;
    }
    inline int pop_max() {
        Tnode *ptr = root, *fa = 0;
        while (ptr->r) {
            fa = ptr;
            ptr = ptr->r;
        }
        int ret = ptr->key;
        if (fa)
            del(fa->r);
        else
            del(root);
        return ret;
    }
    void visit(Tnode *ptr) {
        if (0 == ptr)
            return ;
        visit(ptr->l);
        cout << ptr->key << ' ' << ptr->priority << endl;
        visit(ptr->r);
    }
} treap;
        
inline void add() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a;
        scanf("%d", &a);
        treap.insert(a,treap.root);
    }
}

inline int choose() {
    return treap.pop_max()-treap.pop_min();
}

int main() {
    srand(time(0));
    int n;
    scanf("%d", &n);
    unsigned long long ans = 0;
    while (n--) {
        add();
//        treap.visit(treap.root);
//        cout << endl;
        
        ans += choose();
        
//        treap.visit(treap.root);
//        cout << endl;
//        cout << ans << endl;
    }
    printf("%llu\n", ans);
    return 0;
}
