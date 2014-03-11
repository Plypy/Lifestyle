#include <iostream>
using namespace std;
int main()
{
    string tpa, tpb;
    cin >> tpa >> tpb;
    int ans = 0;
    int a, b;
    for (int i = 0; i < tpa.size(); i++)
    {
        a = tpa[i] - '0';
        for (int j = 0; j < tpb.size(); j++)
        {
            b = tpb[j] - '0';
            ans += a*b;
        }
    }
    cout << ans;
    return 0;
}
