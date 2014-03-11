// ´óË®Ìâ¡« 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b, c, d;
int main() {
    while (true) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == b && b == c && c == 0)
            break;
        bool type = false;;
        if (b-a == c-b) {
            d = (c<<1)-b;
            type = true;
        } else
            d = c*c/b;
        if (type)
            printf("AP ");
        else
            printf("GP ");
        printf("%d\n", d);
    }
    return 0;
}
            
