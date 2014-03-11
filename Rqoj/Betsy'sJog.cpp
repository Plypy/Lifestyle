#include <iostream>
#include <cstdlib>
using namespace std;
int m,t,u,f,d;
int tot;
int main()
{
    cin >> m >> t >> u >> f >> d;
    char ch;
    int i;
    for (i = 1; i <= t; ++i)
    {
        cin >> ch;
        if (ch == 'f')
            tot += f+f;
        else
            tot += u+d;
        if (tot > m)
            break;
    }
    cout << i-1 << endl;
//    system("pause");
    return 0;
}
