#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
char TransTable[300];
string orig, coded;
string wanted;
bool used[300];
int main()
{
    cin >> coded >> orig;
    cin >> wanted;
    bool success = true;
    int len = orig.size();
    if (len != coded.size())
        success = false;
    int rest = 26;
    for (int i = 0; success && i < len; ++i)
    {
        if (TransTable[coded[i]] == 0)
        {
            --rest;
            if (used[orig[i]])
                success = false;
            TransTable[coded[i]] = orig[i];
            used[orig[i]] = true;
        }
        else
        {
            if (TransTable[coded[i]] != orig[i])
                success = false;
        }
    }
    if (rest > 0)
        success = false;
    if (success)
    {
        len = wanted.size();
        for (int i = 0; i < len; ++i)
            cout << TransTable[wanted[i]];
        cout << endl;
    }
    else
    {
        cout << "Failed" << endl;
    }
//    system("pause");
    return 0;
}
/*
������������� 1��
AA
AB
EOWIE

������������� 2��
QWERTYUIOPLKJHGFDSAZXCVBN
ABCDEFGHIJKLMNOPQRSTUVWXY
DSLIEWO

������������� 3��
MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP
YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL
FLSO

������������� 1��
Failed

������������� 2��
Failed

������������� 3��
NOIPS
*/
