#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ct = 0, t = 0;
    cin >> t;
    ct = 1;
    for (int i = 2; i <= n; ++i) {
        int a = 0;
        cin >> a;
        if (a != t) {
            cout << ct << ' ' << t << ' ';
            ct = 1;
            t = a;
        } else 
            ++ct;
    }
    cout << ct << ' ' << t << endl;
//    system("pause");
    return 0;
}
