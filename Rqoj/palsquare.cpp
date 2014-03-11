/*
ID: jake1994
LANG: C++
TASK: palsquare
*/
/*  Note：
 *       又是sx错误，把数组开小了，并且没有仔细读题，唉... 
 *       所谓粗心酿大祸啊，要是遇到什么大事也这样，肯定要遭殃！ 
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std; 
const int MAX = 10000;
int base;
bool check(int i);
void write(int i);
int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    cin >> base;
    for (int i = 1; i <= 300 ; i++)
        if (check(i))
            write(i);
    return 0;
}
bool check(int num)
{
    int list[MAX];
    int n;
    int i, j;
    num *= num;
    for (n = 0, i = 1; num; num = num/base, n++, i++)
        list[i] = num%base;
    for (i = 1, j = n; list[i] == list[j] && i < j; i++, j--)
        continue;
    if (i >= j)
        return true;
    return false;
}
void write(int num)
{
    int tmp = num;
    int n;
    int i;
    int list[MAX];
    for (n = 0, i = 1; tmp; tmp = tmp/base, n++, i++)
        list[i] = tmp%base;
    for (i = n; i > 0; i--)
    {
        if (list[i] < 10)
            cout << list[i];
        else
            cout << char(list[i]-10+'A');
    }
    cout << ' ';
    memset(list,0,sizeof(list));
    num *= num;
    for (n = 0, i = 1; num; num = num/base, n++, i++)
        list[i] = num%base;
    for (i = n; i > 0; i--)
    {
        if (list[i] < 10)
            cout << list[i];
        else
            cout << char(list[i]-10+'A');
    }
    cout << endl;
}
