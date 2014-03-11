#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    for (int num = 1; num <= t; ++num) {
        int c,n;
        cin >> c >> n;
        map<int,int> table;
        int a = 0, b = 0;
        for (int i = 1; i <= n; ++i) {
            int t;
            cin >> t;
            if (0 == a && 0 == b) {
                if (table.end() != table.find(c-t)) {
                    a = table[c-t];
                    b = i;
                }
                table.insert(make_pair(t,i));
            }
        }
        cout << "Case #" << num << ": ";
        cout << a << ' ' << b << endl;
    }
    return 0;
}
