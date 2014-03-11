#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a, b;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        if ((a&b)==b)
            printf("1\n");
        else
            printf("0\n");
    }
    scanf("%d%d",&a,&b);
    if ((a&b)==b)
        printf("1");
    else
        printf("0");
    return 0;
}
