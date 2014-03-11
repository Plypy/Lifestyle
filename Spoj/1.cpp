#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int t;
    while (true)
    {
        cin >> t;
        if (42 == t)
            break;
        cout << t << endl;
    }
    return 0;
}
