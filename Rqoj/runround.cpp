/*
ID: jake1994
PROG: runround
LANG: C++
*/
//啦啦 看看能不能过- - 
//呃...万恶的stdio.h
//继续
//悲剧鸟...
//继续 
//好吧...傻叉了
//应该是数据更新的时候出了问题...
//算法看来没啥错.. 
//看来应该是当check返回false的时候没有做好收尾工作... 
//这个错误莫名其妙的...
//真没搞懂 
//几经他妈的磨难...
//终于第一次过了99...
//我就不信全局变量不行
//再来一次 
//哈哈哈哈哈
//也不知道一开始为啥错... 
#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;
bool check(int num);
int ha[10];
bool list[10];
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    int n;
    cin >> n;
    while (!check(++n))
        continue;
    cout << n << endl;
    return 0;
}
bool check(int num)
{
    memset(list,0,sizeof(list));
    memset(ha,0,sizeof(ha));
    int a = num, b;
    int p = -1, n;
    while (num)
    {
        num/=10;
        p++;
    }
    n = p+1;
    while (a)
    {
        b = a%10;
        a = a/10;
        if (list[b]||!b)
            return false;
        list[b]=true;
        ha[p--]=b;
    }
    memset(list,0,sizeof(list));
    int ct = n;
    int bg = 0;
    while (1)
    {
        if (ct==0)
        {
            if (bg==0)
                return true;
            else
                return false;
        }
        else
        {
            if (!list[bg])
            {
                ct--;
                list[bg]=true;
            }
            else
                return false;
            bg = (bg+ha[bg])%n;
        }
    }
}
