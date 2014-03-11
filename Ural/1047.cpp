#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXN = 3010;
double c[MAXN];
double sum;
double n, x, y;
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        sum += c[i] += c[i-1];
    }
    cout << fixed << setprecision(2) << (n*x+y-sum*2)/(n+1) << endl;
    //system("pause");
    return 0;
}
