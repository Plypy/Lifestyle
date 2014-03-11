#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
int ar[MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", ar+i);
    sort(ar,ar+n);
    string tmp;
    cin >> tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        printf("%d\n", ar[t-1]);
    }
//    system("pause");
    return 0;
}
