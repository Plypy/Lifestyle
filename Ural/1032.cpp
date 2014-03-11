#include <iostream>
using namespace std;
const int MAXN = 10005;
int ar[MAXN];
int rmder[MAXN];
int pos[MAXN];
int n;
int bg, ed;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ar+i);
        rmder[i] = (rmder[i-1]+ar[i])%n;
        if (!rmder[i]) {
            bg = 1;
            ed = i;
            break;
        }
        if (pos[rmder[i]]) {
            bg = pos[rmder[i]]+1;
            ed = i;
            break;
        }
        pos[rmder[i]] = i;
    }
    printf("%d\n", ed-bg+1);
    for (int i = bg; i <= ed; ++i)
        printf("%d\n", ar[i]);
//    system("pause");
    return 0;
}
