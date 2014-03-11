/*
    ID : jake1994
    PROG : job
    LANG : C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
using namespace std;
const int MAXN = 40;
ifstream fin("job.in");
ofstream fout("job.out");
int m[2];
int t[2][MAXN];
int delay[MAXN];
int cost[2][1001];//审题决定一切 
int n;
int ans;
int main()
{
    fin >> n >> m[0] >> m[1];
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < m[k]; i++)
            fin >> t[k][i];
    int tmp;
    for (int k = 0; k < 2; k++)
    {
        memset(delay,0,sizeof(delay));
        for (int i = 0; i < n; i++)
        {
            int min = INT_MAX;
            int minid;
            for (int j = 0; j < m[k]; j++)
                if (min > (tmp=delay[j]+t[k][j]))
                {
                    min = tmp;
                    minid = j;
                }
            cost[k][i] = delay[minid] = min;
        }
    }
    for (int i = 0; i < n; i++)
        if (ans < (tmp=cost[0][i]+cost[1][n-i-1]))
            ans = tmp;
    fout << cost[0][n-1] << ' ' << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
