#include <iostream>
using namespace std;
const int MAXN = 2000;
string list[MAXN];
int main()
{
    list[0] = "http://www.acm.org/";
    int now = 0;
    int end = 0;
    string tmp;
    while (1)
    {
        cin >> tmp;
        if (tmp == "VISIT")
        {
            cin >> tmp;
            list[++now] = tmp;
            cout << tmp << endl;
            end = now;
            continue;
        }
        if (tmp == "FORWARD")
        {
            if (now == end)
                cout << "Ignored" << endl;
            else
                cout << list[++now] << endl;
            continue;
        }
        if (tmp == "BACK")
        {
            if (now == 0)
                cout << "Ignored" << endl;
            else
                cout << list[--now] << endl;
            continue;
        }
        else
            break;
    }
    return 0;
}
