// ½è¼øWJMZMBRÉñÅ£µÄtreap 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

class Treap {
public:
    static const int Inf = INT_MAX;
private:
    struct Tnode {
//        typedef Tnode* Tptr; 
        int val, priority, size;
        Tnode *son[2];
        Tnode(int ival, Tnode *pnil):
            val(ival), priority(rand()),size(1) { son[0] = son[1] = pnil; }
        void resize() {
            size = son[0]->size+son[1]->size+1;
        }
    } *root, *nil;
    typedef Tnode* Tptr;
    void rotate(Tptr &ptr, bool side) {
        Tptr tmp = ptr->son[side];
        ptr->son[side] = tmp->son[!side];
        tmp->son[!side] = ptr;
        ptr->resize();
        tmp->resize();
        ptr = tmp;
    }
    void insert(Tptr &ptr, int val) {
        if (nil == ptr) {
            ptr = new Tnode(val,nil);
            return ;
        }
        if (ptr->val == val)
            return ;
        bool side = val > ptr->val;
        insert(ptr->son[side],val);
        if (ptr->son[side]->priority < ptr->priority)
            rotate(ptr,side);
        else
            ptr->resize();
    }
    void del_node(Tptr &ptr, int val) {
        if (nil == ptr)
            return ;
        if (ptr->val == val) {
            bool side = ptr->son[1]->priority < ptr->son[0]->priority;
            if (nil == ptr->son[side]) {
                delete ptr;
                ptr = nil;
                return ;
            }
            rotate(ptr,side);
            del_node(ptr->son[!side],val);
        } else {
            del_node(ptr->son[val>ptr->val],val);
        }
        ptr->resize();
    }
    int select(Tptr ptr, int kth) {
        int lsize = ptr->son[0]->size;
        if (lsize == kth)
            return ptr->val;
        if (kth < lsize)
            return select(ptr->son[0],kth);
        return select(ptr->son[1],kth-lsize-1);
    }
    int rank(Tptr ptr, int val) {
        if (nil == ptr)
            return 0;
        int lsize = ptr->son[0]->size;
        if (val <= ptr->val)
            return rank(ptr->son[0],val);
        return lsize+1+rank(ptr->son[1],val);
    }
    void dfs(Tptr ptr) {
        if (ptr->son[0] != nil)
            dfs(ptr->son[0]);
        
        cout << ptr->val << ' ' << ptr->priority << ' ' << ptr->size << endl;
        
        if (ptr->son[1] != nil)
            dfs(ptr->son[1]);
    }
public:
    Treap() {
        srand(time(0));
        nil = new Tnode(0,0);
        nil->size = 0;
        nil->priority = Inf;
        root = nil;
    }
    void ins(int a) {
        insert(root,a);
    }
    void del(int a) {
        del_node(root,a);
    }
    int sel(int kth) {
        if (kth > root->size)
            return Inf;
        return select(root,kth-1);
    }
    int ran(int val) {
        return rank(root,val);
    }
    void walk() {
        if (root != nil)
            dfs(root);
        else
            cout << "The tree is empty!" << endl;
    }
} tree;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        char cmd;
        int num;
        while ('\n' != getchar())
            continue;
        scanf("%c %d", &cmd, &num);
        switch (cmd) {
        case 'I':
            tree.ins(num);
            break;
        case 'D':
            tree.del(num);
            break;
        case 'K': {
            int tmp = tree.sel(num);
            if (Treap::Inf == tmp)
                printf("invalid\n");
            else
                printf("%d\n",tmp);
            break;
        }
        case 'C':
            printf("%d\n", tree.ran(num));
            break;
        case 'W':
            tree.walk();
            break;
        default:
            break;
        }
    }
//    system("pause");
    return 0;
}
/*
Input
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

Output
1
2
2
invalid
*/
