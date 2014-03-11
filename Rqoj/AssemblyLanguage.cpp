//此题毫无难度...郁闷的是Rqoj上的题不是以换行符结尾的
//所以我的eatline函数就让程序超时了 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 205;
int way[MAXN];
int main()
{
    int n;
    cin >> n;
    string tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (tmp == "jmp")
        {
            int a;
            cin >> a;
            way[i] = a;
        }
        else
        {
            getline(cin,tmp);
            way[i] = i+1;
        }
    }
    bool used[MAXN] = {0};
    int pos = 1;
    int ct = 0;
    bool error = false;
    while (pos != n+1)
    {
        used[pos] = true;
        ct++;
        if (!used[way[pos]] && ct <= n)
            pos = way[pos];
        else
        {
            error = true;
            break;
        }
    }
    if (error)
        cout << 0 << endl;
    else
        cout << ct << endl;
//    system("pause");
    return 0;
}
/*
6
mov ax, @data
mov ds, ax
jmp 5
jmp 2
mov ax, 4C00H
int 21H
*/
