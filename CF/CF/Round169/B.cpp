#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 10005;

string s;
void load() {
    cin >> s;
}
int ct[300];
void work() {
    for (int i = 0; i < s.size(); ++i)
        ++ct[s[i]];
    int tmp = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (ct[i]&1) {
            ++tmp;
        }
    }
    bool win = true;
    if (tmp && 0  == tmp%2)
        win = false;
    if (win)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
