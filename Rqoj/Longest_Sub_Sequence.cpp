//利用子集思想，将数列分成n组q完全的子集
//即每一组中都恰好有1到q的数，切数组大小最小 
//最终结果就是n+1 
#include <iostream>
#include <string.h>
using namespace std;
int n, q;
bool use[10];
int let;
int main()
{
    scanf("%d%d",&n,&q);
    int ans = 0;
    int num;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&num);
        if (!use[num])
        {
            use[num]=true;
            let++;
            if (let==q)
            {
                let=0;
                memset(use,0,sizeof(use));
                ans++;
            }
        }
    }
    cout << ans+1;
    return 0;
}
