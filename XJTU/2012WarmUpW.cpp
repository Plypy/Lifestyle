#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (a == b)
            cout << "Accepted" << endl;
        else
            cout << "Wrong Answer" << endl;
    }
    return 0;
}
