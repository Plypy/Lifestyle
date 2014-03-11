/*
        ID: jake1994
        PROG: milk3
        LANG: C++
 */
#include <fstream>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int a, b, c, tf[21][21] = {0};
 
void dfs(int i, int k) {
    if (tf[i][k])return;
    tf[i][k] = 1;
    dfs(0, k);
    dfs(i, 0);
    if (i >= b - k)dfs(i - b + k, b);
    else dfs(0, i + k);
    if (k >= a - i)dfs(a, k - a + i);
    else dfs(i + k, 0);
    int j = c - i - k;
    if (j >= a - i)dfs(a, k);
    else dfs(i + j, k);
    if (j >= b - k)dfs(i, b);
    else dfs(i, k + j);
}
 
int main() {
    fin >> a >> b >> c;
    dfs(0, 0);
    for (int i = 20, ge = 0; i >= 0; i--)
        if (tf[0][i]) {
            if (ge)fout << ' ';
            else ge = 1;
            fout << c - i;
        }
    fout << endl;
}
