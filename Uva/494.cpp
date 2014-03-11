#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    bool flag = false;
    char ch;
    int ct = 0;
    while (cin) {
        ch = cin.get();
        if (isalpha(ch))
            flag = true;
        else {
            if (flag) {
                ++ct;
                flag = false;
            }
            if ('\n' == ch) {
                cout << ct << endl;
                ct = 0;
            }
        }
    }
//    cout << ct << endl;
    return 0;
}
