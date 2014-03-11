
#include<iostream>
#define MAXK 1000
using namespace std;
int k,m;
int save[MAXK+1];
int dp[MAXK+1][2];
struct edge
{
    int adjvex;//数据的key 
    edge *next;//指向下一个节点的指针 
    edge(int _adjvex,edge *_next)//构造函数 
        :adjvex(_adjvex),next(_next){}
}*hLink[MAXK+1],*sons[MAXK+1];
bool visited[MAXK+1];//标记一个点是否被记录过 
void maketree(int v)
{
    visited[v]=true;
    for (edge *p=hLink[v];p;p=p->next)
        if (!visited[p->adjvex])
        {
            sons[v]=new edge(p->adjvex,sons[v]);
            maketree(p->adjvex);
        }
}
int treedp(int v,int flag)
{
    if (dp[v][flag]!=-1) 
        return dp[v][flag];
    if (flag==0)
    {
        dp[v][flag]=0;
        for (edge *p=sons[v];p;p=p->next)
            dp[v][flag]+=max(treedp(p->adjvex,0),treedp(p->adjvex,1));
    }
    else
    {
        dp[v][flag]=save[v];
        for (edge *p=sons[v];p;p=p->next)
            dp[v][flag]+=treedp(p->adjvex,0);
    }
    return dp[v][flag];
}
int main ()
{
    cin>>k>>m;
    for (int i=1;i<=k;++i)
    {
        cin>>save[i];
        hLink[i]=sons[i]=NULL;
    }
    for (int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        hLink[a]=new edge(b,hLink[a]);
        hLink[b]=new edge(a,hLink[b]);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for (int i=1;i<=k;++i)
        if (!visited[i])
        {
            maketree(i);
            ans+=max(treedp(i,0),treedp(i,1));
        }
    cout<<ans;
    return 0;
}
/* It's written by me!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
const int MAX = 1100;
int n, m, value[MAX];
bool visited[MAX];
int memory[MAX][2];
using namespace std;
struct node
{
    int key;
    node * son;
    node * bro;
    node(int _key,node*_son, node*_bro):key(_key),son(_son),bro(_bro){}
    node():key(0),son(0),bro(0){}
}tree[MAX];
void add(int _father, int _son)
{
    visited[_son]=true;
    tree[_father].key=_father;
    tree[_son].key=_son;
    tree[_son].bro=tree[_father].son;
    tree[_father].son=&tree[_son];
}
int dp(int root, bool buy)
{
    int res = 0;
    if (memory[root][buy])
        return memory[root][buy];
    if (buy)
    {
        int tmp = 0;
        for (node*p=tree[root].son;p;p=p->bro)
            tmp += dp(p->key,false);
        res = tmp+value[root];
    }
    else
    {
        int tmp1, tmp2;
        for (node*p=tree[root].son;p;p=p->bro)
        {
            tmp1=dp(p->key,true);
            tmp2=dp(p->key,false);
            res += max(tmp1, tmp2);
        }
    }
    return memory[root][buy]=res;
}
int main()
{
    cin >> n >> m;
    int tmp1, tmp2;
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp1 >> tmp2;
        add(tmp1, tmp2);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            ans += max(dp(i,1),dp(i,0));
    cout << ans;
    return 0;
}
*/