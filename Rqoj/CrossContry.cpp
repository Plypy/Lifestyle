//ÕâÖÖ´í...
//±¯¾ç°¡ 
#include <iostream>
using namespace std;
int main()
{
    int m, t, u, f, d;
    scanf("%d%d%d%d%d", &m, &t, &u, &f, &d);
    f <<= 1;
    u = u+d;
    int ans = 0;
    int sum = 0;
    char ch[2];
    int cost;
    for (int i = 1; i <= t; i++)
    {
        scanf("%s", ch);
        if (ch[0] == 'f')
            cost = f;
        else
            cost = u;
        if (sum+cost <= m)
        {
            sum+=cost;
            ans++;
        }
        else
            break;
    }
    cout << ans;
    return 0;
}
