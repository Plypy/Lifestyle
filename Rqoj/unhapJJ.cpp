#include <iostream>
using namespace std;
int up[10];
int main()
{
    int a, b;
    int ans = 0;
    for (int i = 1; i <= 7; i++)
    {
        cin >> a >> b;
        up[i] = a+b-8;
        if (up[i] > up[ans])
            ans = i;
    }
    if (up[ans] > 0)
        cout << ans;
    else
        cout << 0;
    return 0;
}
