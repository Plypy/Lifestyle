#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    char ch;
    int ct = 0;
    while (true) {
        ch = cin.get();
        if (!cin)
            break;
        if (isdigit(ch))
            ct += ch-'0';
        else if ('!' == ch || '\n' == ch)
            cout << endl;
        else if ('b' == ch) {
            for (int i = 1; i <= ct; ++i)
                cout << ' ';
            ct = 0;
        } else {
            for (int i = 1; i <= ct; ++i)
                cout << ch;
            ct = 0;
        }
    }
    return 0;
}
