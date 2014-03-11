#include <iostream>
using namespace std;
const int V = 20010;
int n, v;
int f[V];
int main()
{
    cin >> v >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = v; j >= a; j--)
            if (f[j-a]+a<=v && f[j-a]+a>f[j])
                f[j] = f[j-a]+a;
    }
    cout << v-f[v];
    return 0;
}
