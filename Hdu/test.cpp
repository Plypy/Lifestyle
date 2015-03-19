#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> table;
int main() {
    string str;
    int ct = 0;
    while (cin >> str) {
        table[str] = ++ct;
    }
    for (table.iterator iter = table.begin(); iter != table.end(); ++iter) {
        cout << iter->second << endl;
    }
    return 0;
}
