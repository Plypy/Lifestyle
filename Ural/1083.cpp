#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    int ans = 1;
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    int m = tmp.size();
    while (n > 0)
    {
        ans*=n;
        n-=m;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}
