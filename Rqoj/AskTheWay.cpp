#include <iostream>
#include <sstream>
using namespace std;
/*
     1
   4   2
     3
*/
int main()
{
    int n;
    cin >> n;
    int dir = 1;
    int ct = 0;
    string tmp;
    int x, y;
    x = y = 0;
    int flag = 0;
    int num;
    while (ct < n)
    {
        cin >> tmp;
        if (tmp == "right")
            dir = dir%4+1;
        else if (tmp == "left")
            dir = (dir+2)%4+1;
        else
        {
            flag++;
            istringstream is(tmp);
            is >> num;
            switch (dir)
            {
                case 1:
                    y += num;
                    break;
                case 2:
                    x += num;
                    break;
                case 3:
                    y -= num;
                    break;
                case 4:
                    x -= num;
                    break;
            }
            cout << '(' << x << ',' << y << ')';
            if (ct != n-1)
                cout << endl;
        }
        ct++;
    }
    if (!flag)
        cout << "(0,0)";
    return 0;
}
