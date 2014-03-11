#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MAXN = 101;
bool prime[MAXN];
int n;
void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        prime[i] = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i%j==0)
            {
                prime[i] = false;
                break;
            }
        }
    }
}
void work(int num)
{
    for (int i = 2; i < num; i++)
        if (prime[i] && prime[num-i])
        {
            cout << num << '=' << i << '+' << num-i << endl;
            return;
        }
}
int main()
{
    cin >> n;
    init();
    for (int i = 4; i <= n; i+=2)
        work(i);
    //system("pause");
    return 0;
}
