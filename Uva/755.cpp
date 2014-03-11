#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iterator>
using namespace std;

char table[500];
void init() {
    table['A'] = table['B'] = table['C'] = '2';
    table['D'] = table['E'] = table['F'] = '3';
    table['G'] = table['H'] = table['I'] = '4';
    table['J'] = table['K'] = table['L'] = '5';
    table['M'] = table['N'] = table['O'] = '6';
    table['P'] = table['R'] = table['S'] = '7';
    table['T'] = table['U'] = table['V'] = '8';
    table['W'] = table['X'] = table['Y'] = '9';
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string,int> directory;
        while (n--) {
            string buf;
            string tmp;
            cin >> tmp;
            for (int i = 0; i < tmp.size(); ++i) {
                if (isalpha(tmp[i]))
                    buf += table[tmp[i]];
                else if (isdigit(tmp[i]))
                    buf += tmp[i];
                if (3 == buf.size())
                    buf += '-';
            }
            ++directory[buf];
        }
        bool no_duplicates = true;
        for (map<string,int>::const_iterator itr = directory.begin(); itr != directory.end(); ++itr)
            if (itr->second > 1) {
                cout << itr->first << ' ' << itr->second << endl;
                no_duplicates = false;
            }
        if (no_duplicates)
            cout << "No duplicates." << endl;
        if (t)
            cout << endl;
    }
    return 0;
}
