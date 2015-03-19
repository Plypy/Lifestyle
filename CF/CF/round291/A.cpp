#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int min(int a, int b)
{
    return a<b ? a : b;
}

int main()
{
    ll ret = 0;
    bool first = true;
    while (true) {
        char ch = getchar();
        if (!isdigit(ch)) {
            break;
        }
        ch -= '0';
        if (!first || ch != 9) {
            ch = min(ch, 9-ch);
        }
        ret = ret*10 + ch;
        if (first) {
            first = false;
        }
    }
    cout << ret << endl;
}
