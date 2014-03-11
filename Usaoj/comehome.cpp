/*
    ID : jake1994
    PROG : comehome
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
const int MAXN = 55;
const int INF = 10000000;
int dis[MAXN][MAXN];
int n;
int main()
{
    fin >> n;
    char p, q;
    int a, b, c;
    for (int i = 1; i <= 52; i++)
        for (int j = 1; j <= 52; j++)
            dis[i][j] = INF;
    for (int i = 1; i <= n; i++)
    {
        fin >> p >> q >> c;
        if (p < 'a')
            a = p-'A'+27;
        else
            a = p-'a'+1;
        if (q < 'a')
            b = q-'A'+27;
        else
            b = q-'a'+1;
        if (!dis[a][b])
            dis[a][b] = dis[b][a] = c;
        else if (dis[a][b] > c)
            dis[a][b] = dis[b][a] = c;
    }
    for (int k = 1; k <= 52; k++)
        for (int i = 1; i <= 52; i++)
            for (int j = 1; j <= 52; j++)
                if (dis[i][j] > dis[i][k]+dis[k][j])
                    dis[i][j] = dis[i][k]+dis[k][j];
    int min = 52111425;
    int ans;
    for (int i = 27; i < 52; i++)
        if (dis[i][52] < min)
        {
            min = dis[i][52];
            ans = i;
        }
    fout << char('A'+ans-27) << ' ' << min << endl;
    return 0;
}

