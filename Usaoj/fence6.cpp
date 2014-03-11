/*
    ID : jake1994
    PROG : fence6
    LANG : C++
*/
// 无向图最小环问题可以使用Floyd Warshall解决。 
// 但是考虑到本题中给出的并不是一个一个节点
// 而是一个一个的边。 故在建图时仍存在一些麻烦。
// 有两种解决方案，一种是为每个点标号，但是较为复杂，容易出错。
// 另一种则是将每个给出的边，考虑为点。
// 现在新的距离则为两个边之和，这样的话最后求出的环中就会将每个边
// 包含两次，所以输出时只需输出其的一半即可。
// 另外在使用这种方法构造一个环的时候要从一个线段的两边分别选取新边构造环。
// 这样才能保证其为一个环。 
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
