#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = ans+1; i+j-1 < len; ++j) {
            if (string::npos != str.find(str.substr(i,j),i+1))
                ans = j;
        }
    }
    cout << ans << endl;
    return 0;
}
