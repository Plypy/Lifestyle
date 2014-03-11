#include <iostream>
#include <fstream>
using namespace std;
string A,B;
unsigned int K;

int abs(int a);
void load();
void analyze();
int main()
{
    load();
    analyze();
    return 0;
}
int abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

void load()
{
    ifstream fin;
    fin.open("blast.in");
    fin >> A >> B >> K;
}

void analyze()
{
    ofstream fout;
    fout.open("blast.out");
    
    int m, n;
    m = A.size();
    n = B.size();
    
    int *g[m+1];
    for (int i = 0; i <= m; i++)
        g[i] = new int[n+1];
    int min;
    int temp;
    g[0][0] = 0;
    for (int i = 1; i <= m; i++)
        g[i][0] = g[i-1][0]+K;
    for (int i = 1; i<= n; i++)
        g[0][i] = g[0][i-1]+K;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            temp  = g[i-1][j-1] + abs(A[i-1]-B[j-1]);
            if (temp  < g[i-1][j]+K)
                min = temp;
            else
                min = g[i-1][j]+K;
            if (min > g[i][j-1]+K)
                min = g[i][j-1]+K;
            g[i][j] = min;
        }
    fout << g[m][n];
    for (int i = 0; i <= m; i++)
        delete[] g[i];
}
