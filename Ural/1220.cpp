// Ã´tmµ∞Ã€¡À 
#include <stdio.h>
#include <stdlib.h>
const int MAXN = 100000;
const int MAXS = 1000;
unsigned int Data[MAXN];
unsigned short post[MAXN];
int ct;

unsigned int last[MAXS];

int main() {
    int n;
    scanf("%d", &n);
    unsigned short a;
    unsigned int b;
    char s[10];
    while (n--) {
        scanf("%s", s);
        if ('U' == s[1]) {
            scanf("%hu%u", &a, &b);
            --a;
            Data[ct] = b<<1;
            Data[ct] += last[a]>>16;
            post[ct] = (unsigned short) last[a];
            last[a] = ct;
            ++ct;
        } else {
            scanf("%hu", &a);
            --a;
            printf("%u\n", Data[last[a]]>>1);
            last[a] = ((Data[last[a]]&1)<<16)+post[last[a]];
        }
    }
    return 0;
}
