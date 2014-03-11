#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, m;
        cin >> n >> m;
        map<string, string> table;
        for (int j = 1; j <= m; ++j) {
            string key, value;
            cin >> key >> value;
            table[key] = value;
        }
        while (cin.get() != '\n')
            continue;
        string word;
        getline(cin,word);
        istringstream is(word);
        cout << "Case #" << i << ':';
        while (true) {
            is >> word;
            if (!is)
                break;
            int ct = 1;
            while (table.find(word) != table.end() && ct < n) {
                ++ct;
                word = table[word];
            }
            cout << ' ' <<  word;
        }
        cout << endl;
    }
    return 0;
}
