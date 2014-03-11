#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, f;
        cin >> a >> f;
        while (f--) {
            for (int i = 1; i <= a; ++i) {
                for (int j = 1; j <= i; ++j)
                    cout << i;
                cout << endl;
            }
            for (int i = a-1; i; --i) {
                for (int j = 1; j <= i; ++j)
                    cout << i;
                cout << endl;
            }
            if (f)
                cout << endl;
        }
        if (t)
            cout << endl;
    }
    return 0;
}
