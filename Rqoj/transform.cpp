/*
  ID : jake1994
  PROG : transform
  LANG : C++
*/
/*NOTE:
 *  ����Ҫע��ϸ�ڰ�����ת����ʱ��Ҫ����һ����ʱ�������洢��ת���...
 *  ����������һ�룬���Ըı�ȽϵĴ��򣬾���ʡ�������ʱ����
 *  �����ÿ��ת������һ������Ҳ�ȽϺã������׳���
 *  �������ǵ����Ⲣ��̫��...�������˰ɡ�
 */ 
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 15;
bool sour[MAX][MAX];
bool dest[MAX][MAX];
bool tmp[MAX][MAX];
bool tmp2[MAX][MAX];
int n;
void init()
{   memset(tmp,0,sizeof(tmp));}
bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (tmp[i][j] != dest[i][j])
                return false;
    return true;
}
int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin >> n;
    char tm;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> tm;
            if (tm == '@')
                sour[i][j] = true;
            else
                sour[i][j] = false;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> tm;
            if (tm == '@')
                dest[i][j] = true;
            else
                dest[i][j] = false;
        }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[n-j+1][i];
    if (check())
    {
        cout << 1 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[n-i+1][n-j+1];
    if (check())
    {
        cout << 2 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[j][n-i+1];
    if (check())
    {
        cout << 3 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[i][n-j+1];
    if (check())
    {
        cout << 4 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp2[i][j] = sour[i][n-j+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = tmp2[n-j+1][i];
    if (check())
    {
        cout << 5 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp2[i][j] = sour[i][n-j+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = tmp2[n-i+1][n-j+1];
    if (check())
    {
        cout << 5 << endl;
        return 0;
    }
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp2[i][j] = sour[i][n-j+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = tmp2[j][n-i+1];
    if (check())
    {
        cout << 5 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = sour[i][j];
    if (check())
    {
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;
    return 0;
}
