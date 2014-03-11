#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    string tar;
    string cur;
    cin >> tar >> cur;
    int ct = 0;
    int i;
    for (i = 0; i < tar.size() && i < cur.size() && cur[i] == tar[i]; i++)
        continue;
    int j = i;
    i--;
    if (cur.size() != 1)
        for (; i < cur.size(); i++)
            if (cur[i] == '/')
            {
                cout << "../";
                ct++;
            }
    if (ct || cur.size() == 1)
        cout << tar.substr(j);
    else
        cout << tar.substr(j+1);
//    system("pause");
    return 0;
} 
