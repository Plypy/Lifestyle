/* 
   Note: ºÚÊé P131
   unsolved
 */
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

class Problem
{
private:
    static const int MAXN = 50;
    static const int INF = 52111425;
    int n;
    string word[MAXN];
    int f[MAXN][MAXN];
    int pre[MAXN];
    
public:
    bool load()
    {
        cin >> n;
        if (n == 0)
            return false;
        for (int i = 0; i < n; ++i)
            cin >> word[i];
        return true;
    }
    void solve()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < word[i].size(); ++j)
            {
                f[i][j] = INF;
                for (int k = 0; k < n; ++k)
                    if (word[i].substr(0,j+1) == word[k])
                    {
                        f[i][j] = j;
                        break;
                    }
            }
        }
        
    }
} prob;
int main()
{
    while (prob.load())
        prob.solve();
    return 0;
}
