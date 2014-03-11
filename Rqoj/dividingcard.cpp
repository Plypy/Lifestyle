#include <iostream>
using namespace std;
const int MAXN = 101;
int sum;
int num[101];
int des, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    des = sum/n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (num[i] < des)
        {
            num[i+1] -= des-num[i];
            ans++;
        }
        else if (num[i] > des)
        {
            num[i+1] += num[i]-des;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
