/*
ID: jake1994
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
const int mod = 9901;
const int MAXN = 200;
int N, K;
int dp[MAXN][MAXN];
int main()
{
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    fin >> N >> K;
    for (int i = 1; i <= K; i++)
        dp[1][i] = 1;
    for (int j = 2; j <= K; j++)
        for (int i = 1; i <= N; i+=2)
            for (int k = 1; k <= i-2; k+=2)
            {
                dp[i][j] += dp[k][j-1]*dp[i-k-1][j-1];
                dp[i][j] %= mod;
            }
    fout << (dp[N][K]-dp[N][K-1]+mod)%mod << endl;
    fin.close();
    fout.close();
    return 0;
}
