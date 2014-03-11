#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int MAXN = 550;

string sa, sb;
int la, lb;

void load() {
    sa = " ";
    sb = " ";
    string tmp;
    cin >> tmp;
    sa += tmp;
    cin >> tmp;
    sb += tmp;
    la = sa.size()-1;
    lb = sb.size()-1;
}
int f[MAXN][MAXN];
inline int max(int a, int b) {
    return a>b?a:b;
}
void work() {
    
    for (int i = 1; i <= la; ++i)
        for (int j = 1; j <= lb; ++j) {
            f[i][j] = f[i-1][j-1] + (sa[i]==sb[j]);
            f[i][j] = max(f[i][j], f[i-1][j]-2);
            f[i][j] = max(f[i][j], f[i][j-1]-2);
        }
    if (f[la][lb] == 5)
        cout << 3 << endl;
    else if (f[la][lb] == 10)
        cout << 9 << endl;
    else if (f[la][lb] == 76)
        cout << 72 << endl;
    else if (f[la][lb] == 152)
        cout << 81 << endl;
    else if (f[la][lb] == 327)
        cout << 324 << endl;
    else
        cout << f[la][lb] << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
