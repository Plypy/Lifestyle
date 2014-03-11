#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 21;
const int MAXV = 100;
int f[MAXV];
int wt[MAXN];
int val[MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wt[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        for (int j = MAXV-1; j >= wt[i]; j--)
        {
            if (f[j-wt[i]]+val[i] > f[j])
                f[j] = f[j-wt[i]]+val[i];
        }
    }
    cout << f[MAXV-1] << endl;
    //system("pause");
    return 0;
}
