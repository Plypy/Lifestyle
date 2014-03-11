/*
    ID : jake1994
    PROG : agrinet
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 101;
const int INF = 52111425;
const int FLAG = -1;
int map[MAXN][MAXN];
int dis[MAXN];
int n;
int main()
{
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> map[i][j];
    for (int i = 2; i <= n; i++)
        dis[i] = INF;
    int ans = 0;
    int id;
    int mi;
    for (int k = 1; k <= n; k++)
    {
        mi = INF;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] != FLAG && dis[i] < mi)
            {
                mi = dis[i];
                id = i;
            }
        }
        ans += dis[id];
        dis[id] = -1;
        for (int i = 1; i <= n; i++)
            if (map[id][i] < dis[i])
                dis[i] = map[id][i];
    }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
