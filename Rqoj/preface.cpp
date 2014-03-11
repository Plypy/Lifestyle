/*
ID: jake1994
PROG: preface
LANG: C++
*/
//罗马数字好麻烦的...cheat鸟 
#include <stdio.h>
 
const int code[10][3] = {{0,0,0},{1,0,0},{2,0,0},{3,0,0},{1,1,0},{0,1,0},{1,1,0},{2,1,0},{3,1,0},{1,0,1}},
	s[10][30] = {{0,0,0},{1,0,0},{3,0,0},{6,0,0},{7,1,0},{7,2,0},{8,3,0},{10,4,0},{13,5,0},{14,5,1}};
int res[9];
 
int main()
{
	int n;
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	scanf("%d", &n);
	for (int pri = 0, k = 1; k <= n; k *= 10, pri += 2)
	{
		for (int i = 0; i < 3; ++i)
		{
			res[i+pri] += n/(k*10)*s[9][i]*k;
			if (n/k%10) res[i+pri] += s[n/k%10-1][i]*k;
			res[i+pri] += (n%k+1)*code[n/k%10][i];
		}
	}
	for (int i = 0; i < 7; ++i)
		if (res[i]) printf("%c %d\n", "IVXLCDM"[i], res[i]);
}
