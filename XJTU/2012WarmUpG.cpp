#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int BUFSIZE = 20;
int n;
int main() {
    scanf("%d", &n);
    char buf[BUFSIZE] = {0};
    while (n--) {
        scanf("%s", buf);
        if (isdigit(buf[0])) {
            int t = 0;
            int ct = 0;
            while (buf[ct]) {
                t *= 10;
                t += buf[ct++]-'0';
            }
            char ans[BUFSIZE] = {0};
            ct = 0;
            while (t) {
                ans[++ct] = 'A'-1+t%26;
                if (0 == t%26)
                    t -= 26;
                t /= 26;
                if (ans[ct] < 'A')
                    ans[ct] = 'Z';
            }
            for (int i = ct; i; --i)
                putchar(ans[i]);
            putchar('\n');
        } else {
            int len = strlen(buf);
            int t = 0;
            for (int i = 0; i < len; ++i) {
                t *= 26;
                t += buf[i]-'A'+1;
            }
            printf("%d\n", t);
        }
    }
    return 0;
}
