#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const char LU = 218, RU = 191, LB = 192, RB = 217, V = 179, H = 196;
const int M = 20, N = 50;
char smap[M + 1][N + 1];
int sq[15][3];
int ans = -1;
void init()
{
	for (int i = 0 ;i < M ;i++)
		cin >> smap[i];
}

bool check(int ii, int jj, int k)//判断正方形 
{
    //判断四角 
	if (smap[ii][jj] != ',' && smap[ii][jj] != LU) 
        return false;
	if (smap[ii][jj+k-1] != ',' && smap[ii][jj+k-1] != RU) 
        return false;
	if (smap[ii+k-1][jj] != ',' && smap[ii+k-1][jj] != LB) 
        return false;
	if (smap[ii+k-1][jj+k-1] != ',' && smap[ii+k-1][jj+k-1] != RB) 
        return false;
    //判断四边 
	for (int i = ii+1 ;i < ii+k-1 ;i++)
	{
		if (smap[i][jj] != ',' && smap[i][jj] != V) 
            return false;
		if (smap[i][jj + k - 1] != ',' && smap[i][jj + k - 1] != V) 
            return false;
	}
	for (int j = jj+1 ;j < jj+k-1 ;j++)
	{
		if (smap[ii][j] != ',' && smap[ii][j] != H) 
            return false;
		if (smap[ii+k-1][j] != ',' && smap[ii+k-1][j] != H) 
            return false;
	}
	//判断是否是以前搜过的 
	for (int i = ii ;i <= ii + k - 1 ;i++)
		if (smap[i][jj] != ',' || smap[i][jj + k - 1] != ',')
            return true;
	for (int j = jj ;j <= jj + k - 1 ;j++)
		if (smap[ii][j] != ',' || smap[ii + k - 1][j] != ',')
            return true;
	return false;
}

void clear(int ii, int jj, int k)//删除并标记已处理过的正方形 
{
	for (int i = ii ;i <= ii+k-1 ;i++)
		smap[i][jj] = smap[i][jj+k-1] = ',';
	for (int j = jj ;j <= jj+k-1 ;j++)
		smap[ii][j] = smap[ii+k-1][j] = ',';
}

void work()
{
	int i, j, k, i1, j1, k1;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (k = M ;k >= 2 ;k--)
			for (i = 0 ;i <= M-k ;i++)
				for (j = 0 ;j <= N-k ;j++)
				{
					if (check(i, j, k)) 
					{
						ans++;
						flag = true;
						sq[ans][0] = i, sq[ans][1] = j, sq[ans][2] = k;
						clear(i, j, k);
						goto Jump_out;
					}
				}
		Jump_out: ;
	}//依次从上到下删除正方形 
	cout << ans + 1 << endl;
	for (i = ans ;i >= 0 ;i--)//输出 
		cout << sq[i][1] << ' ' << sq[i][0] << ' ' << sq[i][2] << endl;
}

int main()
{
	init();
	work();
	return 0;
}
