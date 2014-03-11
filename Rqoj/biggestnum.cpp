#include <iostream>
using namespace std;
const int MAXN = 21;
string list[MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> list[i];
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (list[i]+list[j] < list[j]+list[i])
                swap(list[i],list[j]);
    for (int i = 1; i <= n; i++)
        cout << list[i];
    return 0;
}
