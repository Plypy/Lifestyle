#include <iostream>
#include <cstdlib>
#include <cmath>
#define MAXN 101
using namespace std;
int n, x[MAXN], y[MAXN], ord[MAXN];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        ord[i] = i+1;
    }
    ord[n] = 1;
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += (x[i]-x[ord[i]])*y[i];
    cout << s << endl;
//    system("pause");
    return 0;
}
