#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 55;

int n;
int ans;
int main() {
    scanf("%d", &n);
    getchar();
    char pre = getchar();
    for (int i = 1; i <= n; ++i) {
        char ch = getchar();
        if (ch == pre)
            ans++;
        else
            pre = ch;
    }
    printf("%d\n", ans);
    return 0;
}
