#include <stdio.h>
#include <stdlib.h>
int main() {
    int a = 0, b = 0;
    while (EOF != scanf("%d%d", &a, &b))
        printf("%d\n", a*b-1);
    return 0;
}
