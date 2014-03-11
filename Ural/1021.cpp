#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 50005;
const int SHIFT = 32768;
const int TARGET = 10000;
int table[MAXN];
int n;

const int P = 3;
int hash_it(int num) {
    int t = num%MAXN;
    while (-1 != table[t] && num != table[t])
        t = (t+P)%MAXN;
    return t;
}
int main() {
    scanf("%d", &n);
    memset(table,0xff,sizeof(table));
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        t += SHIFT;
        table[hash_it(t)] = t;
    }
    cin >> n;
    bool success = false;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        t = TARGET-t+SHIFT;
        if (table[hash_it(t)] == t) {
            success = true;
        }
    }
    if (success)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
//    system("pause");
    return 0;
}
