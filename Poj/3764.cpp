// dfs��ת��Ϊ���n������ȡ��������ʹ����xorֵ�������⣬��trie��Ϳ�����
// ������κ����ư�����һ��д�Ĳ�����ô�Ľ���ȥ����Runtime_error
// ò�������ṩ�Ĺ��캯��������- -�ڶ���û���ṩ���캯��ֱ�Ӿ�1a��
// �Ҿ��ÿ���������ǰ���Ǹ����캯��û�ж�space��������Ķ������г�ʼ��������˴����
// �����Ҳ��������ˡ�����̫tm�����ˣ�ϡ���Ϳ���˰��졣 
// �����������л��ܵõ�һ����ʾ��������һ�����ʱ��Ҫ˼��һ����Ŀ�������ԣ�
// ����ֱ��������ǰ����������⣬Ҫע������֮�������
// ����������cowxor�ǵ��������������ĳ��ȴ��˺ܶ࣬cowxor�Ǹ�ֻ��20
// �������31�ˣ�������cowxor��ʹ�õ�����ģ����ȫ�������ķ���������Ͳ�����
// ��Ϊ��ռ��̫��Ŀռ䣬ʵ��������ע�⵽trie�����ֻ���õ�31��n�Ľ��
// ���Կ��Կ���������Ż����þ�̬����ģ�⶯̬�ڴ����Ϳ�����
// ���ܱ�֤�����ڴ��� 
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
