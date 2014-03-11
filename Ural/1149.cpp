#include <iostream>
#include <cstdlib>
using namespace std;
int n;
void out_a(int id, int ip)
{
    if (id == ip)
    {
        cout << "sin(" << id << ')';
    }
    else
    {
        cout << "sin(" << id << ((id&1)?'-':'+');
        out_a(id+1,ip);
        cout << ')';
    }
}
void out_s(int id)
{
    if (id == 1)
    {
        out_a(1,1);
        cout << '+' << n;
    }
    else
    {
        cout << '(';
        out_s(id-1);
        cout << ')';
        out_a(1,id);
        cout << '+' << n-id+1;
    }
}
int main()
{
    cin >> n;
    out_s(n);
    cout << endl;
    //system("pause");
    return 0;
}
