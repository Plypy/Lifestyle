// dfs后转化为求从n个数中取出两个数使得其xor值最大的问题，用trie搞就可以了
// 不过这次很郁闷啊，第一次写的不论怎么改交上去都是Runtime_error
// 貌似是我提供的构造函数有问题- -第二次没有提供构造函数直接就1a了
// 我觉得可能是我先前的那个构造函数没有对space数组里面的东西进行初始化，造成了错误吧
// 不过我不想再试了。。。太tm悲剧了，稀里糊涂错了半天。 
// 另外从这道题中还能得到一个启示，就是做一道题的时候要思考一下题目的特殊性，
// 不能直接套用先前解决过的问题，要注意问题之间的区别
// 比如这道题和cowxor那道题的区别就是数的长度大了很多，cowxor那个只有20
// 这个就是31了，所以在cowxor中使用的数组模拟完全二叉树的方法在这里就不行了
// 因为会占用太大的空间，实际上我们注意到trie中最多只会用到31×n的结点
// 所以可以靠这个进行优化，用静态数组模拟动态内存分配就可以了
// 就能保证不爆内存了 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 100001;
const int MAXBITS = 31;

struct Edge {
    int vtx;
    int wt;
    Edge *nxt;
    Edge(int ivtx = 0, int iwt = 0, Edge *inxt = 0):
        vtx(ivtx), wt(iwt), nxt(inxt) { }
} edge[MAXN*2], *adj[MAXN];
int ect;
inline void add(int u, int v, int w) {
    adj[u] = &(edge[++ect] = Edge(v,w,adj[u]));
    adj[v] = &(edge[++ect] = Edge(u,w,adj[v]));
}
class Trie {
private:
    struct Node {
        Node *son[2];
    } *root, space[MAXN*MAXBITS];
    int nct;
    inline Node *new_node() {
        ++nct;
        space[nct].son[0] = space[nct].son[1] = 0;
        return &space[nct];
    }
public:
    inline void init() {
        nct = 0;
        root = new_node();
    }
    inline void insert(int a) {
        Node *ptr = root;
        for (int i = 30; i >= 0; --i) {
            bool bit = (a>>i)&1;
            if (ptr->son[bit] == 0) {
                ptr->son[bit] = new_node();
            }
            ptr = ptr->son[bit];
        }
    }
    inline int get(int a) {
        int ret = 0;
        a = ~a;
        Node *ptr = root;
        for (int i = 30; i >= 0; --i) {
            bool bit = (a>>i)&1;
            ret <<= 1;
            if (ptr->son[bit]) {
                ++ret;
                ptr = ptr->son[bit];
            } else {
                ptr = ptr->son[1-bit];
            }
        }
        return ret;
    }
} trie;
int val[MAXN];
bool vis[MAXN];
int n;
void init() {
    ect = 0;
    memset(adj,0,sizeof(adj));
    memset(val,0,sizeof(val));
    memset(vis,0,sizeof(vis));
    trie.init();
}
inline bool load() {
    if (EOF == scanf("%d", &n))
        return false;
    init();
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ++a;
        ++b;
        add(a,b,c);
    }
    return true;
}
void dfs(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v]) {
            val[v] = val[u]^t->wt;
            dfs(v);
        }
    }
}
inline void work() {
    dfs(1);
    int ans = val[1];
    trie.insert(val[1]);
    for (int i = 2; i <= n; ++i) {
        int d = trie.get(val[i]);
        if (ans < d)
            ans = d;
        trie.insert(val[i]);
    }
    printf("%d\n", ans);
}
int main() {
    while (load()) {
        work();
    }
    return 0;
}
