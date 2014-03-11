#include <iostream>
using namespace std;
int ans, cost, tmp;
int main()
{
    for (int i = 1; i <= 12; i++)
    {
        cin >> cost;
        tmp = tmp+300-cost;
        if (tmp<0)
        {
            cout << -i;
            return 0;
        }
        ans += 100*(tmp/100);
        tmp = tmp%100;
    }
    cout << ans*1.2+tmp;
    return 0;
}
