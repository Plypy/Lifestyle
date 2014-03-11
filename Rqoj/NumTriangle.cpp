#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n, s;
    int nxt;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
                cout << ' ' << ' ';
        for (int j = 1; j <= n-i; j++)
        {
            cout << s;
            if (j == 2)
            {
                nxt = s+1;
                if (nxt == 10)
                    nxt = 1;
            }
            if (j < n-i)
            {
                cout << ' ';
                s += j+i;
                if (s >= 10)
                    s = (s+s/10)%10;
                if (s == 0)
                    s = 1;
            }
            else
            {
                cout << endl;
                s = nxt;
            }
        }
    }
    return 0;
}
