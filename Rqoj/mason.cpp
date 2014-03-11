#include <iostream>
#include <cmath>
using namespace std;
char data[500];
void mul(char *a)
{
    int temp = 0, num;
    for (int i = 499; i+1; i--)
    {
        num = a[i]-'0';
        num = num*2+temp;
        a[i] = num%10+'0';
        temp = num/10;
    }
}
int main()
{
    for (int i = 0; i < 499; i++)
        data[i] = '0';
    data[499] = '1';
    long n;
    cin >> n;
    long ans;
    ans = lrint(log10(2)*n-0.5)+1;
    for (int i = 499;;i--)
    {
        if (data[i] != '0')
        {
            data[i]--;
            break;
        }
        data[i] = '9';
    }
    cout << ans << endl;
    cout << data;
    return 0;
}
