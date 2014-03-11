#include <iostream>
using namespace std;
int f;
int fb;
int fbi;
string tmp;
int main()
{
    cin >> tmp;
    int len = tmp.size();
    for (int i = 0; i < len; i++)
        switch (tmp[i])
        {
            case 'F':
                f++;
                break;
            case 'B':
                fb+=f;
                break;
            case 'I':
                fbi+=fb;
                break;
        }
    cout << fbi;
    return 0;
}
