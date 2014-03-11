#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#define MAX 300010
using namespace std;
int num[MAX];
int cou,sum;
void add(int k,int n)  //多重背包的二进制拆分
{
	int i,x,tmp = 0;
	for(i=0; ; i++)
	{
		x = 1<<i;
		if( tmp + x > k )
			break;
		tmp += x;
		num[cou++] = x*n;
	}
	x = k - tmp;
	if( x != 0 )
		num[cou++] = n*x;
}
int flag,bag[MAX];
int DP()  			// 01背包。
{
	int i,k;
	for(i=0; i<cou; i++)
		for(k=sum; k>=num[i]; k--)
			if( bag[k-num[i]] + num[i] > bag[k] )
				bag[k] = bag[k-num[i]] + num[i];
	return bag[sum] == sum ;
}
int main()
{
	int a,b,c,d,e,f,i;
	int ind = 1;
	while( scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f) != EOF )
	{
		sum = cou = 0;
		if( !( a || b || c || d || e || f ) )
			break;
		sum += a*1; sum += b*2; sum += c*3; sum += d*4; sum += e*5; sum += f*6;
		printf("Collection #%d:/n",ind++);
		if( sum % 2 == 1 )
		{
			printf("Can't be divided./n/n");
			continue;
		}
		add(a,1); add(b,2); add(c,3); add(d,4); add(e,5); add(f,6);
		sum /= 2;
		memset(bag,0,sizeof(bag));
		flag = DP();
		if( flag )
			printf("Can be divided./n/n");
		else
			printf("Can't be divided./n/n");
	}
return 0;
}
