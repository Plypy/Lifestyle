#include <iostream>
using namespace std;
const int MAXN = 15001;
int mem[MAXN];
void init()
{
    mem[1] = 2;
    for (int i = 2; i < MAXN; ++i)
    {
        int m = mem[i-1];
        while (true)
        {
            ++m;
            int j;
            for (j = 1; j < i; ++j)
                if (m%mem[j] == 0)
                    break;
            if (j == i )
                break;
        }
        mem[i] = m;
    }
}
int main()
{
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        cout << mem[t] << endl;
    }
    return 0;
}
