#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        n = 180-n;
        if (0 == 360%n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
