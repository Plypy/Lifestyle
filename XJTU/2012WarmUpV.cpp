#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, m;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n%(m+1))
            printf("win\n");
        else
            printf("lose\n");
    }
    return 0;
}
