/*
    ID : jake1994
    PROG : stall4
    LANG : C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("stall4.in");
ofstream fout("stall4.out");
const int MAXN = 205;
bool graph[MAXN][MAXN];
bool used[MAXN];
int lin[MAXN];
int n, m;
int ans;
//This is a bipartite graph matching problem, and the algorithm I used is the
//Hopcroft-Karp Algorithm, i.e. the Hungarian Algorithm. It depends on finding
//a augmenting path(different from the normal one). On this path, the matched edges
//and the unmatched edges appear by turns, and the end nodes of this path both are
//unmatched node.
void load()
{
    fin >> n >> m;
    int t;
    int p;
    for (int i = 1; i <= n; i++)
    {
        fin >> t;
        for (int j = 1; j <= t; j++)
        {
            fin >> p;
            graph[i][p] = true;
        }
    }
}
bool find(int id)//Finding augmenting path.
{
    for (int i = 1; i <= m; i++)
        if (graph[id][i] && !used[i])//In order to make the simple path.
        {
            used[i] = true;
            if (!lin[i] || find(lin[i]))//The first condithon is check the end
                                        //unmatched node, the second one is to
                                        //construct the augmenting path.
                                        //Remember, in this algorithm we always 
                                        //start in a unmatched node, so this is
                                        //will find a augmenting path available.
            {
                lin[i] = id;
                return true;
            }
        }
    return false;
}
void work()
{
    for (int i = 1; i <= n; i++)
    {
        memset(used,0,sizeof(used));
        if (find(i))
            ans++;
    }
}
void output()
{
    fout << ans << endl;
}
int main()
{
    load();
    work();
    output();
    return 0;
}
