/*
ID: jake1994
PROB: concom
LANG: C++
*/
#include<stdio.h>
#include<string.h>
int con1[101][101],con2[101][101];
int n,m;
void dfs(int i,int j)
{
	for (int k=1;k<=m;k++)
		if (i!=k && con2[i][k]<=50)
		{
			con2[i][k]+=con1[j][k];
			if (con2[i][k]>50) dfs(i,k);
		}
}
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&n);
	int i1,j1; m=0;
	memset(con1,0,sizeof(con1));
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&i1,&j1);
		scanf("%d",&con1[i1][j1]);
		if (i1>m) m=i1; if (j1>m) m=j1;
	}
	memcpy(con2,con1,sizeof(int)*101*101);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (con2[i][j]>50) dfs(i,j);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (i!=j && con2[i][j]>50)
				printf("%d %d\n",i,j);
	return 0;
}
