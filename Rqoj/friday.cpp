/*
ID: jake1994
PROG: friday
LANG: C++
*/
//做了一个表，来记录每月的日期，很是方便
//主要就是判断闰年的部分费了我不少时间... 
#include <iostream>
#include <stdio.h>

using namespace std;
int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans[8];
int n;
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    cin >> n;
    int sum = 0;
    for (int i = 1900; i < 1900+n; i++)
    {
        if ((i%4==0&&(i%100!=0))||i%400==0)
            mon[2]++;
        for (int j = 1; j <= 12; j++)
        {
            ans[(sum+12)%7+1]++;
            sum+=mon[j];
        }
        mon[2]=28;
    }
    cout << ans[6] << ' ' << ans[7] << ' ';
    cout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5] << endl;
    return 0;
} 
