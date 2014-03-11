
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 2005

int space[MAXLEN];

inline int ScanInt() {
    char ch;
    while (true) {
        ch = getchar();
        if (isdigit(ch) || '-' == ch)
            break;
    }
    int sign = 1;
    if ('-' == ch) {
        ch = getchar();
        sign = -1;
    }
    int ret = 0;
    do {
        ret = ret*10+ch-'0';
        ch = getchar();
    } while (isdigit(ch));
    return ret*sign;
}
int main() {
    int *ct = space+MAXLEN/2;
    
    int t;
    t = ScanInt();
    while (t--) {
        memset(space,0,sizeof(space));
        int n = ScanInt();
        int bd = n>>1;
        bool successful = false;
        int num;
        while (n--) {
            int a = ScanInt();
            ++ct[a];
            if (ct[a] > bd) {
                num = a;
                successful = true;
            }
        }
        if (successful)
            printf("YES %d\n", num);
        else
            printf("NO\n");
        putchar('\n');
    }
    return 0;
}
