#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 1005;
string dat[MAXN];
int n, k;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> dat[i];
    sort(dat,dat+n);
    cout << dat[k-1] << endl;
    return 0;
}
        
/*
5 3
faff
adf
beig
plaie
zfdeegeetulae

faff
*/
