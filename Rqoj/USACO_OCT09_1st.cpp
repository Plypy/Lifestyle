#include <iostream>
#include <cstdlib>
using namespace std;
int n;
string num;
int main()
{
    cin >> n;
    int a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        a = num[num.size()-1] - '0';
        if (a&1)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
//    system("pause");
    return 0;
}
