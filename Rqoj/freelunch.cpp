//Note
//一想起那个该死的乌龟
//我就想操他妈
//当时为什么不静下心来设计一个好的状态
//竟然他妈的都没有想到你那个傻叉二维状态
//代表的过程是他妈的不单一的
//样例都他妈没过
//你丫死盯着程序有个屁用啊 


//二分查找实现 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int L=100001;
int n,a[L],p[L],ans;

int get(int num)
{
    int bg=1,ed=ans,mid;
    while (bg <= ed)
    {
        mid = (bg+ed)>>1;
        if (p[mid]==num)
            return mid;
        else if (p[mid] < num)
            bg = mid+1;
        else
            ed = mid-1;
    }
    return bg;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    for (int i=n,t;i>=1;i--)
    {
        if (a[i]==0)
            continue;
        t=get(a[i]);
        if (t>ans)
            ans++;
        p[t]=a[i];
    }
    cout << ans;
    return 0;
}
