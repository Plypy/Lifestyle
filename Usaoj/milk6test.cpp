//此程序copy自Nocow，Author是大牛Echoat
//此是为了验证我在milk6中所说的方法三的程序正确性
//经过验证此方法是错误的 
/*
	ID:echoaot1
	LANG:C++
	TASK:milk6
*/
#include <fstream>
#include <cstring>
#define V 52
#define E 1003
using namespace std;
struct re{
	long x,y,z,l;
};
re g[E];
ifstream fin("milk6.in");ofstream fout("milk6.out");
long level[V]={0},a[V][V]={0},c[V][V]={0},c1[V][V];
long n=0,m=0;
bool bfs(void){
	memset(level,-1,sizeof level);
	long d[V]={0,1},head=1,tail=1;
	level[1]=0;
	while(head<=tail){
		long now=d[head++];
		for(long i=1;i<=a[now][0];i++)
			if(c[now][a[now][i]]>0&&level[a[now][i]]==-1)
				level[d[++tail]=a[now][i]]=level[now]+1;
		}
	return level[n]!=-1;
}
long extent(long u,long sum){
	long r=0,t=0;
	if(u==n)return sum;
	for(long i=1;i<=a[u][0]&&r<sum;i++)
		if(level[a[u][i]]==level[u]+1){
		t=c[u][a[u][i]];
		if(t>sum-r)t=sum-r;
		t=extent(a[u][i],t);
		r+=t;c[u][a[u][i]]-=t;c[a[u][i]][u]+=t;
	}
	if(!r)level[u]=-1;
	return r;
}
long dinic(void){
	long t=0,r=0;
	while(bfs()){
		bool bo=false;
		while(t=extent(1,0x7fffffff)){
			r+=t;bo=true;}
		if(!bo)break;
	}
	return r;
}
int comp(const void* a,const void* b){
	long r=((re*)b)->z-((re*)a)->z;
	if(r)return r;
	r=((re*)a)->l-((re*)b)->l;
	return r;
}
bool hash[E]={0};
long o=0;
int main(int argc,char** argv){
	fin >>n>>m;
	for(long i=1;i<=m;i++){
		long x,y,z;
		fin >>x>>y>>z;a[x][++a[x][0]]=y;a[y][++a[y][0]]=x;c1[x][y]+=z;c[x][y]=c1[x][y];
		g[i].x=x;g[i].y=y;g[i].z=z;g[i].l=i;
	}
	long sum=dinic();
	qsort(g,m+1,sizeof g[0],comp);
	long ans[E]={0};
	long max=sum;
	for(long i=0;i<m;i++){
		long x=g[i].x,y=g[i].y;
		long now=g[i].z;
		if(now<=max){
			memcpy(c,c1,sizeof c);
			c[x][y]-=now;
			long s=dinic();
			if(max-s==now){
				hash[g[i].l]=true;o++;
				max=s;
				c1[g[i].x][g[i].y]-=now;
			}
		}
	}
	fout <<sum<<' '<<o<<endl;
	for(long i=1;i<=m;i++)
		if(hash[i])fout <<i<<endl;
	fin.close();fout.close();
	return 0;
}
