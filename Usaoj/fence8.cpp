/*
    ID : jake1994
    PROG : fence8
    LANG : C++
*/
// 啊啊啊...啊啊啊...啊啊啊...啊啊啊
// 过啦！！！！！！！！！！！！！！！！
//过啦！！！！！！！！！！！！！！！ 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("fence8.in");
ofstream fout("fence8.out");
const int MAXN = 51;
const int MAXR = 1024;
int size[MAXN];
int backup[MAXN];
int len[MAXR];
int sum[MAXR];
int tot;
int spare;
int n, r;
int ans;
int mid; 
int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}
bool dfs(int dep, int pos)
{
    if (dep <= 0)//成功 
        return true;
    if (spare>tot-sum[mid])
        return false;
    bool flag = false;
    for (int i = pos; i <= n; i++)
        if (backup[i] >= len[dep])
        {
            backup[i] -= len[dep];
            if (backup[i] < len[1])
                spare += backup[i];
            if (len[dep] == len[dep-1])
            {
                if (dfs(dep-1,i))
                    return true;
            }
            else if (dfs(dep-1,1))
                return true;
            if (backup[i] < len[1])
                spare -= backup[i];
            backup[i] += len[dep];
        }
    return false;
}
int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> size[i];
    fin >> r;
    for (int i = 1; i <= r; i++)
        fin >> len[i];
    qsort(len+1,r,sizeof(int),cmp);// 启发式 
    qsort(size+1,n,sizeof(int),cmp);// 启发式 
                                    //考虑到每个木材的价值都是一样的，所以用短的木材必然比长的木材划算
    for (int i = 1; i <= n; i++)
        tot += size[i];
    for (int i = 1; i <= r; i++)
        sum[i] = sum[i-1]+len[i];
    while (sum[r] > tot)//合理性剪枝 
                        //木板的总长必须超过木材的总长，才有可能截取出一定数量的木材 
        r--;
    int bg = 0, ed = r;
    while (bg <= ed)//二分检索 
    {
        spare = 0;
        mid = (bg+ed)>>1;
        memcpy(backup, size, sizeof(size));
        if (dfs(mid,1))//合理性剪枝
                                            //最大的木板必须比最大的木材长，否则就无法截取出最大的木板，也就是无法满足要求 
            bg = mid+1;
        else
            ed = mid-1;
    }
    fout << ed << endl;
    return 0;
}

