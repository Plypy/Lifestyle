#include <stdio.h>
#include <stdlib.h>

int main() {
    int t = 0;
    while (EOF != scanf("%d",&t)) {
        if (42 == t)
            break;
        printf("%d\n", t);
    }
    return 0;
}
