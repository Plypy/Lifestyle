#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    map<string,int> table;
    int n;
    cin >> n;
    while (n--) {
        string tmp;
        cin >> tmp;
        ++table[tmp];
        getline(cin,tmp);
    }
    for (map<string,int>::const_iterator itr = table.begin(); itr != table.end(); ++itr)
        cout << itr->first << ' ' << itr->second << endl;
//    system("pause");
    return 0;
}
        
