
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
const int MAXN=603,MAXM=MAXN*MAXN*4,INF=~0U>>1;
 
struct edge
{
	edge *next,*op;
	int t,c;
}*V[MAXN],*V0[MAXN],*P[MAXN],ES[MAXM],*Stae[MAXN];
 
 
int R,C,EC,Ans,Maxflow,Stop,S,T,N;
int score[MAXN],ind[MAXN],Lv[MAXN],Stap[MAXN],Q[MAXN];
bool ts[MAXN];
 
inline void addedge(edge **V,int a,int b,int c)
{
	ES[++EC].next = V[a]; V[a] = ES+EC; V[a]->t = b; V[a]->c=c;
	ES[++EC].next = V[b]; V[b] = ES+EC; V[b]->t = a; V[b]->c=0;
	V[a]->op = V[b]; V[b]->op = V[a];
}
 
inline int point2id(int x,int y)
{
	return x * C + y + 1;
}
 
void init()
{
	int i,j,k,l,q,x,y,s,c;
	scanf("%d%d",&R,&C);
	for (i=0;i<R;i++)
	{
		for (j=0;j<C;j++)
		{
			k = point2id(i,j);
			if (j+1<C)
			{
				q = point2id(i,j+1);
				addedge(V0,q,k,1);
				ind[k]++;
			}
			scanf("%d%d",&s,&c);
			score[k] = s;
			for (l=1;l<=c;l++)
			{
				scanf("%d%d",&x,&y);
				q = point2id(x,y);
				addedge(V0,k,q,1);
				ind[q]++;
			}
		}
	}
	N=R*C;
}
 
void topsort()
{
	int i,j;
	Stop = 0;
	for (i=1;i<=N;i++)
		if (ind[i]==0)
			Stap[++Stop] = i;
	while (Stop)
	{
		i = Stap[Stop--];
		ts[i] = true;
		for (edge *e=V0[i];e;e=e->next)
		{
			j=e->t;
			if (e->c)
			{
				ind[j]--;
				if (ind[j] == 0)
					Stap[++Stop] = j;
			}
		}
	}
}
 
void makegraph()
{
	int i,j;
	S=0;
	T=N+1;
	for (i=1;i<=N;i++)
		if (ts[i])
		{
			if (score[i] > 0)
			{
				addedge(V,S,i,score[i]);
				Ans += score[i];
			}
			else
				addedge(V,i,T,-score[i]);
			for (edge *e=V0[i];e;e=e->next)
			{
				j=e->t;
				if (ts[j] && e->c)
				{
					addedge(V,j,i,INF);
				}
			}
		}
}
 
bool Dinic_label()
{
	int i,j,head,tail;
	memset(Lv,0,sizeof(Lv));
	Q[head=tail=0] = S;
	Lv[S] = 1;
	while (head<=tail)
	{
		i = Q[head++];
		for (edge *e=V[i];e;e=e->next)
		{
			j = e->t;
			if (Lv[j] == 0 && e->c)
			{
				Lv[j] = Lv[i]+1;
				if (j==T)
					return true;
				Q[++tail] = j;
			}
		}
	}
	return false;
}
 
void Dinic_aug()
{
	int i,j,delta;
	for (i=S;i<=T;i++)
		P[i] = V[i];
	Stap[Stop=1]=S;
	while (Stop)
	{
		i = Stap[Stop];
		if (i!=T)
		{
			for (;P[i];P[i]=P[i]->next)
				if (P[i]->c && Lv[ j = P[i]->t ] == Lv[i] + 1)
					break;
			if (P[i])
			{
				Stap[++Stop] = j;
				Stae[Stop] = P[i];
			}
			else
				Stop--,Lv[i] = 0;
		}
		else
		{
			delta = INF;
			for (i=Stop;i>=2;i--)
				if (Stae[i]->c < delta)
					delta = Stae[i]->c;
			for (i=Stop;i>=2;i--)
			{
				Stae[i]->c -= delta;
				Stae[i]->op->c += delta;
				if (Stae[i]->c == 0)
					Stop = i-1;
			}
			Maxflow += delta;
		}
	}
}
 
void Dinic()
{
	while (Dinic_label())
		Dinic_aug();
}
 
void solve()
{
	topsort();
	makegraph();
	Dinic();
	Ans -= Maxflow;
	printf("%d\n",Ans);
}
 
int main()
{
    freopen("pvz.in", "r", stdin);
    freopen("pvz.ans", "w", stdout);
	init();
	solve();
	
	
	printf("\n");
	printf("%d\n", Ans+Maxflow);
	printf("Mcut: %d\n", Maxflow);
	for (int i = 1; i <= N; ++i)
	   printf("%d ", ts[i]);
	printf("\n");
	return 0;
}
