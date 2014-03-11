#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
char s[MAXN], tmp[MAXN];
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    scanf("%s", s);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[j] = s[j];
            if (s[j] == 'G' && s[j-1] == 'B')
                swap(tmp[j],tmp[j-1]);
        }
        for (int j = 0; j < n; ++j)
            s[j] = tmp[j];
    }
    printf("%s\n", s);
    return 0;
}
