#include <iostream>
using namespace std;
int main()
{
    int m, sum;
    cin >> m;
    int bound = m>>1;
    bool flag = false;
    for (int i = 1; i <= bound; i++)
    {
        sum = 0;
        int j;
        for (j = i; sum+j <= m; j++)
            sum += j;
        if (sum == m)
        {
            flag = true;
            cout << i;
            for (int k = i+1; k < j; k++)
                cout << ' ' << k;
            cout << endl;
        }
    }
    if (!flag)
        cout << "NONE" << endl;
    return 0;
}
