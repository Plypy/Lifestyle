/*
    ID : jake1994
    PROG : fence6
    LANG : C++
*/
// ����ͼ��С���������ʹ��Floyd Warshall����� 
// ���ǿ��ǵ������и����Ĳ�����һ��һ���ڵ�
// ����һ��һ���ıߡ� ���ڽ�ͼʱ�Դ���һЩ�鷳��
// �����ֽ��������һ����Ϊÿ�����ţ����ǽ�Ϊ���ӣ����׳���
// ��һ�����ǽ�ÿ�������ıߣ�����Ϊ�㡣
// �����µľ�����Ϊ������֮�ͣ������Ļ��������Ļ��оͻὫÿ����
// �������Σ��������ʱֻ��������һ�뼴�ɡ�
// ������ʹ�����ַ�������һ������ʱ��Ҫ��һ���߶ε����߷ֱ�ѡȡ�±߹��컷��
// �������ܱ�֤��Ϊһ������ 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fence6.in");
ofstream fout("fence6.out");
const int INF = 52111425;
const int MAXN = 205;
int len[MAXN];
int righ[MAXN][MAXN];
int lef[MAXN][MAXN];
int graph[MAXN][MAXN];
int dist[MAXN][MAXN];
int min(int &a, int &b)
{
    return a<b?a:b;
}
int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;
    int s;
    for (int i = 1; i <= n; i++)
    {
        fin >> s;
        fin >> len[s];
        fin >> lef[s][0];
        fin >> righ[s][0];
        for (int j = 1; j <= lef[s][0]; j++)
            fin >> lef[s][j];
        for (int j = 1; j <= righ[s][0]; j++)
            fin >> righ[s][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= lef[i][0]; j++)
            graph[i][lef[i][j]] = len[i]+len[lef[i][j]];
        for (int j = 1; j <= righ[i][0]; j++)
            graph[i][righ[i][j]] = len[i]+len[righ[i][j]];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = graph[i][j];
    int ans = INF;
    int ti, tj;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= lef[k][0]; i++)
        {
            ti = lef[k][i];
            if (ti < k)
            {
                for (int j = 1; j <= righ[k][0]; j++)
                {
                    tj = righ[k][j];
                    if (tj < k)
                        ans = min(ans,dist[ti][tj]+graph[k][ti]+graph[k][tj]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    fout << (ans>>1) << endl;
}
