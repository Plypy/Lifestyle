#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if ("1" == s || "4" == s || "78" == s)
            cout << '+' << endl;
        else if ('5' == s[s.size()-1])
            cout << '-' << endl;
        else if ('9' == s[0])
            cout << '*' << endl;
        else
            cout << '?' << endl;
    }
    return 0;
}
