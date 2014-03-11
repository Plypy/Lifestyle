#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXD = 31;
int table[MAXD];
void init() {
    for (int i = 0; i < MAXD; ++i)
        table[i] = (1<<(i+1))-1;
}

int main() {
    init();
    string buf;
    while (true) {
        cin >> buf;
        if ("0" == buf)
            break;
        int ans = 0;
        for (int i = 0; i < buf.size(); ++i)
            ans += (buf[buf.size()-i-1]-'0')*table[i];
        cout << ans << endl;
    }
    return 0;
}
