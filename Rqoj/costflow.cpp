#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxint=~0U>>1;
 
int n,m,pi1,cost=0;
bool v[550];
struct etype
{
    int t,c,u;
    etype *next,*pair;
    etype(){}
    etype(int t_,int c_,int u_,etype* next_):
        t(t_),c(c_),u(u_),next(next_){}
    void* operator new(unsigned,void* p){return p;}
} *e[550];
 
int aug(int no,int m)
{
    if(no==n)return cost+=pi1*m,m;
    v[no]=true;
//    int l=m;
    for(etype *i=e[no];i;i=i->next)
        if(i->u && !i->c && !v[i->t])
        {
            int d=aug(i->t,m<i->u?m:i->u);
            if (d) {
                i->u-=d;
                i->pair->u+=d;
                return d;
            }
//            l-=d;
//            if(!l)return m;//这里的一次多路增广有问题，因为使用了标记判重，实际上每一次只能增广一条路径，因为其他路径不可能再访问汇点了
//                             其实没有问题啦对于汇点他并没有标记，所以当前弧优化没有问题 
        }
    return 0;
}
 
bool modlabel()
{
    int d=maxint;
    for(int i=1;i<=n;++i)
		if(v[i])
			for(etype *j=e[i];j;j=j->next)
				if(j->u && !v[j->t] && j->c<d)
					d=j->c;
    if(d==maxint)
		return false;
    for(int i=1;i<=n;++i)
		if(v[i])
			for(etype *j=e[i];j;j=j->next)
				j->c-=d,j->pair->c+=d;// 这里可以检验受否为断层的地方也可以不检验
				// 因为这样考虑，如果节点u有后继v的话，那么必然存在两条边
                // 分别为u->v 和 v->u 对这两条边进行修改的操作会互相抵消
                // 从而不会影响算法的正确性，不过这样似乎就比较低效了
                // 更高效的就是只修改断层上的边 
    pi1 += d;
    return true;
}
 
int main()
{
    freopen("costflow.in","r",stdin);
    freopen("costflow.out","w",stdout);
    scanf("%d %d",&n,&m);
    etype *Pe=new etype[m+m];
    while(m--)
    {
        int s,t,c,u;
        scanf("%d%d%d%d",&s,&t,&u,&c);
        e[s]=new(Pe++)etype(t, c,u,e[s]);
        e[t]=new(Pe++)etype(s,-c,0,e[t]);
        e[s]->pair=e[t];
        e[t]->pair=e[s];
    }
    do {
//        cout << endl;
//        for (int u = 1; u <= n; ++u) {
//            cout << u << endl;
//            for (etype *t = e[u]; t; t=t->next)
//                cout << t->t << ' ' << t->u << ' ' << t->c << endl;
//            cout << endl;
//        }
//        cout << endl;
        do {
            memset(v,0,sizeof(v));
        } while(aug(1,maxint));
    } while(modlabel());
    printf("%d\n",cost);
    return 0;
}
