#include <iostream>
using namespace std;
const int MAXN = 10000;
int result1[MAXN];
int result2[MAXN];
int main()
{
    char tmp;
    int ct1 = 0, ct2 = 0;
    int ct3 = 0, ct4 = 0;
    int ansn = 0;
    while(1)
    {
        scanf("%c",&tmp);
        if (tmp == 'E')
            break;
        if (tmp == '\n')
            continue;
        if (tmp == 'W')
        {
            ct1++;
            ct3++;
            if (ct1>=11 && ct1-ct2>1)
            {
                printf("%d:%d\n",ct1,ct2);
                ct1 = ct2 = 0;
            }
            if (ct3>=21 && ct3-ct4>1)
            {
                result1[++ansn]=ct3;
                result2[ansn]=ct4;
                ct3 = ct4 = 0;
            }
        }
        else
        {
            ct2++;
            ct4++;
            if (ct2>=11 && ct2-ct1>1)
            {
                printf("%d:%d\n",ct1,ct2);
                ct1 = ct2 = 0;
            }
            if (ct4>=21 && ct4-ct3>1)
            {
                result1[++ansn]=ct3;
                result2[ansn]=ct4;
                ct3 = ct4 = 0;
            }
        }
    }
    printf("%d:%d\n", ct1,ct2);
    for (int i = 1; i <= ansn; i++)
        printf("\n%d:%d", result1[i], result2[i]);
    printf("\n%d:%d",ct3,ct4);
    return 0;
}
