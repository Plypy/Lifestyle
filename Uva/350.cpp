#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL = 10005;
int z, i, m, l;
int occured[MAXL];
int main() {
    int c_num = 0;
    while (true) {
        ++c_num;
        cin >> z >> i >> m >> l;
        if (!(z|i|m|l))
            break;
        memset(occured,0,sizeof(occured));
        int len = 0;
        while (!occured[l]) {
            occured[l] = ++len;
            l = (z*l+i)%m;
        }
        cout << "Case " << c_num << ": " << len-occured[l]+1 << endl;
    }
    return 0;
}
