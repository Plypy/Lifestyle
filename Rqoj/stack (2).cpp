#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void load();
void solve();
void mult(string &A, int num);
void div(string &A, int num);
static int N;
int main()
{
    load();
    solve();
    return 0;
}
void load()
{
    cin >> N;
}
void solve()
{
    string A = "1";
    for (int i = N+2; i <= 2*N; i++)
        mult(A, i);
    for (int i = 2; i <= N; i++)
        div(A, i);
    int i = 0;
    for (; A[i] == '0'; i++);
    for (; i < A.size(); i++)
        cout << A[i];
}
void mult(string &A, int num)
{
    int len;
    len = A.size();
    int temp = 0;
    int value;
    for (int i = len - 1; i >= 0; i--)
    {
        value = A[i] - '0';
        value = value*num+temp;
        A[i] = '0' + value%10;
        temp = value/10;
    }
    ostringstream os;
    if (temp)
    {
        os << temp;
        A = os.str() + A;
    }
}
void div(string &A, int num)
{
    int len;
    len = A.size();
    int value;
    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        value = A[i] - '0';
        value = temp*10+value;
        temp = value%num;
        value = value/num;
        A[i] = '0' + value;
    }
}
