#include <iostream>
using namespace std;
int check(int num);
int bg, ed;
int main()
{
    int ans = 0;
    cin >> bg >> ed;
    for (int i = bg; i <= ed; i++)
        ans += check(i);
    cout << ans;
    return 0;
}
int check(int i)
{
    int res = 0;
    while (i)
    {
        if (i%10 == 2)
            res++;
        i /= 10;
    }
    return res;
}
