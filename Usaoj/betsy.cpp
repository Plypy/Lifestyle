/*
    ID : jake1994
    PROG : betsy
    LANG : C++
*/
#include <iostream>
#include <fstream>
#define MAX 9
using namespace std;
ifstream fi("betsy.in");
ofstream fo("betsy.out");
int N,N_2,cnt;
bool map[MAX][MAX];
int pi[4]={0,0,1,-1},pj[4]={1,-1,0,0};
void init()
{
	int i,j,k;
	fi >> N;
	N_2=N*N;
	for (i=0;i<=N+1;i++)
	{
		map[0][i]=map[N+1][i]=map[i][0]=map[i][N+1]=true;
	}
	map[1][1]=true;
}
void print()
{
	fo << cnt << endl;
	fi.close();
	fo.close();
}
inline int getfree(int i,int j)
{
	int v=0;
	for (int k=0;k<4;k++)
	{
		if (!map[ i+pi[k] ][ j+pj[k] ])
			v++;
	}
	return v;
}
void go(int i,int j,int step)
{
	if (i==N && j==1)
	{
		if (step==N_2)
			cnt++;
		return;
	}
	if	(
			(map[i][j-1] && map[i][j+1] && !map[i-1][j] && !map[i+1][j])
			||
			(!map[i][j-1] && !map[i][j+1] && map[i-1][j] && map[i+1][j])
		)
		return;
	int k,di,dj,f,cntf=0,ki,kj;
	for (k=0;k<4;k++)
	{
		di=i+pi[k],dj=j+pj[k];
		if (map[di][dj] || (di==N && dj==1)) continue;
		f=getfree(di,dj);
		if (f<2)
		{
			cntf++;
			ki=di;
			kj=dj;
		}
	}
	if (cntf>1)
		return;
	else
	{
		if (cntf==1)
		{
			map[ki][kj]=true;
			go(ki,kj,step+1);
			map[ki][kj]=false;
		}
		else
		{
			for (k=0;k<4;k++)
			{
				di=i+pi[k],dj=j+pj[k];
				if (!map[di][dj])
				{
					map[di][dj]=true;
					go(di,dj,step+1);
					map[di][dj]=false;
				}
			}
		}
	}
}
int main()
{
	init();
	go(1,1,1);
	print();
	return 0;
}
