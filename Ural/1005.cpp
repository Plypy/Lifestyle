#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 21;
const int MAXW = 100000;
int wt[MAXN];
int bound[MAXN];
int f[MAXN*MAXW/2+5];
int sum;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
        sum += wt[i];
    }
    int t = sum>>1;
    bound[n] = t;
    for (int i = n-1; i; i--)
        bound[i] = bound[i+1]-wt[i+1];;
    for (int i = 1; i <= n; i++)
        for (int j = t; j >= wt[i] && j >= bound[i]; j--)
            if (f[j] < f[j-wt[i]]+wt[i])
                f[j] = f[j-wt[i]]+wt[i];
    cout << sum-2*f[t] << endl;
    //system("pause");
    return 0;
}
