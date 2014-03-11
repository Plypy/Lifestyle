//经过noip2010的打击
//终于能理解到自己的水平
//前路漫漫
//从头开始吧
//一步一步向前走
//膜拜大牛
//敬仰大牛
//最终成为大牛
//并实现自己的诺言
//年少轻狂，不思量，十年生死两茫茫。 
#include <iostream>
using namespace std;
bool bas[1001];
int n;
int sotd[101];
int main()
{
    cin >> n;
    int tmp;
    int tot=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (bas[tmp]==false)
            tot++;
        bas[tmp] = true;
    }
    cout << tot << endl;
    int j = 1;
    for (int i = 1; i <= 1000; i++)
        if (bas[i])
            sotd[j++] = i;
    for (int i = 1; i < tot; i++)
        cout << sotd[i] << ' ';
    cout << sotd[tot];
    return 0;
}
