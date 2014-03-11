/*
    ID : jake1994
    PROG : fence8
    LANG : C++
*/
// ������...������...������...������
// ������������������������������������
//���������������������������������� 
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
    if (dep <= 0)//�ɹ� 
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
    qsort(len+1,r,sizeof(int),cmp);// ����ʽ 
    qsort(size+1,n,sizeof(int),cmp);// ����ʽ 
                                    //���ǵ�ÿ��ľ�ĵļ�ֵ����һ���ģ������ö̵�ľ�ı�Ȼ�ȳ���ľ�Ļ���
    for (int i = 1; i <= n; i++)
        tot += size[i];
    for (int i = 1; i <= r; i++)
        sum[i] = sum[i-1]+len[i];
    while (sum[r] > tot)//�����Լ�֦ 
                        //ľ����ܳ����볬��ľ�ĵ��ܳ������п��ܽ�ȡ��һ��������ľ�� 
        r--;
    int bg = 0, ed = r;
    while (bg <= ed)//���ּ��� 
    {
        spare = 0;
        mid = (bg+ed)>>1;
        memcpy(backup, size, sizeof(size));
        if (dfs(mid,1))//�����Լ�֦
                                            //����ľ����������ľ�ĳ���������޷���ȡ������ľ�壬Ҳ�����޷�����Ҫ�� 
            bg = mid+1;
        else
            ed = mid-1;
    }
    fout << ed << endl;
    return 0;
}

