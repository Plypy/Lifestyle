/*
    ID : jake1994
    PROG : stamps
    LANG : C++
*/
#include <iostream>
#include <fstream> 
using namespace std;
//转换思路唉...
//此题的状态为组成某个面值所需的最少邮票 
const int MAX = 2000001;
unsigned char f[MAX];
int val[205];
int main()
{
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    int k, n;
    fin >> k >> n;
    for (int i = 1; i <= n; i++)
        fin >> val[i];
    int ans = 0;
    int a, b;
    int j;
    for (j = 1; ;j++)
    {
        for (int  i = 1; i <= n; i++)
        {
            if (j>=val[i])
            {
                if (!f[j] || f[j-val[i]]+1<f[j])
                    f[j] = f[j-val[i]]+1;
            }
        }
        if (f[j] > k)
            break;
    }
    fout << j-1 << endl;
    fin.close();
    fout.close();
    return 0;
}
