#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 101;
int ar[MAXN][MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> ar[i][j];
    cout << ar[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cout << ' ' << ar[i-j+1][j];
    for (int j = 2; j <= n; ++j)
        for (int i = n; i >= j; --i)
            cout << ' ' << ar[i][j+n-i];
    //system("pause");
    cout << endl;
    return 0;
}
