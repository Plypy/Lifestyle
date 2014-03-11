/*
ID: jake1994
PROG: money
LANG: C++
*/
#include <fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
const int MAXN = 10001;
int v[26];
long long f[MAXN];
int main()
{
    int V, n;
    fin >> V >> n;
    for (int i = 1; i <= V; i++)
        fin >> v[i];
    f[0] = 1;
    for (int i = 1; i <= V; i++)
        for (int j = v[i]; j <= n; j++)
            f[j] += f[j-v[i]];
    fout << f[n] << endl;
    fin.close();
    fout.close();
    return 0;
}
