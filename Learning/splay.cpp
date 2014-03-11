// cashier
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int v,lazy,size,cnt;
    node *father,*child[2];
    node()
    {
        size = cnt = lazy = 0;
    }
};
typedef node *NODE;
NODE root,Null,rfather,lastvisit;
int limit,n;
int f(NODE root) // 判断当前点的是左孩子还是右孩子
{
    return root->father->child[1] == root;
}
void pre() // 新增点rfather 为root->father
{
    Null = new(node);
    root = Null;
    rfather = new(node);
    rfather->child[0] = root;
    rfather->child[1] = Null;
    root->father = rfather;
}
void fresh(NODE &root) // update
{
    root->size = root->cnt + root->child[0]->size + root->child[1]->size;
    root->child[0]->father = root->child[1]->father = root;
}
void zig(NODE root,int to)
{
    NODE tmp = root->child[to];
    tmp->father = root->father;
    root->father->child[f(root)] = tmp;
    root->child[to] = tmp->child[to ^ 1];
    tmp->child[to ^ 1] = root;
    fresh(root);
    fresh(tmp);
}

void pushdown(NODE &root) // lazy的下传
{
    root->child[0]->v += root->lazy;
    root->child[0]->lazy += root->lazy;
    root->child[1]->v += root->lazy;
    root->child[1]->lazy += root->lazy;
    root->lazy = 0;
}
void insert(NODE &root,int k) //插入 这个pushdown很重要
{
    if (root == Null)
    {
        root = new(node);
        root->v = k;
        root->child[0] = root->child[1] = Null;
        root->size = root->cnt = 1;
        lastvisit = root;
        return ;
    }
    pushdown(root);
    if (root->v == k) root->cnt++;
    if (k < root->v) insert(root->child[0],k);
    if (k > root->v) insert(root->child[1],k);
    fresh(root);
}

void splay(NODE lastvisit,NODE rfather) //lastvisit 移到 root
{
    NODE tmp = lastvisit;
    while(tmp->father != rfather)
    {
        if (tmp->father->father == rfather)
        {
            zig(tmp->father,f(tmp));
        }
        else if (f(tmp->father) == f(tmp))
        {
            zig(tmp->father->father,f(tmp->father));
            zig(tmp->father,f(tmp));
        }
        else zig(tmp->father,f(tmp)),zig(tmp->father,f(tmp));
    }
    root = rfather->child[0]; //更新root
}
NODE find(NODE root,int k) // 查找后驱，包括等于自己
{
    if (root == Null) return Null;
    pushdown(root);
    NODE tmp;
    if (root->v == k) return root;
    if (root->v < k) return find(root->child[1],k);
    if (root->v > k)
    {
        tmp = find(root->child[0],k);
        if (tmp != Null) return tmp;
        else return root;
    }
}
int ask(NODE root,int k) //询问第k大
{
    if (root == Null) return -1;
    pushdown(root);
    if (root->child[1]->size >= k) return ask(root->child[1],k);
    if (root->child[1]->size + root->cnt >= k) return root->v;
    return ask(root->child[0],k - root->child[1]->size - root->cnt);
}
void init()
{
    scanf("%d%d%*c",&n,&limit);
    int x,ans = 0;
    for(int i = 1; i <= n; i++)
    {
        char str;
        scanf("%c %d%*c",&str,&x);
        if (str == 'I' && x < limit) continue;
        if (str == 'I') insert(rfather->child[0],x),fresh(rfather),splay(lastvisit,rfather);
        else if (str == 'A') root->v += x,root->lazy += x;
        else if (str == 'S')
        {
            lastvisit = Null;
            lastvisit = find(root,limit + x);
            if (lastvisit == Null)
                ans += root->size,root = Null,rfather->child[0] = root,fresh(rfather);
            else
            {
                splay(lastvisit,rfather);
                ans += root->child[0]->size;
                root->child[0] = Null;
                root->v -= x;
                root->lazy -= x;
                fresh(root);
            }
        }
        else if (str == 'F')
        {
            printf("%d\n",ask(root,x));
        }
    }
    printf("%d\n",ans);
}
int main()
{
    pre();
    init();
    system("pause");
    return 0;
}
