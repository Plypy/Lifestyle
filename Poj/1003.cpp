
#include <stdio.h>

double target;
bool load() {
    scanf("%lf", &target);
    if (0.0 == target)
        return false;
    return true;
}
void work() {
    double sum = 0;
    for (int i = 2; ; ++i) {
        sum += (1.0/i);
        if (sum >= target) {
            printf("%d card(s)\n", i-1);
            break;
        }
    }
}
int main() {
    while (load()) {
        work();
    }
    return 0;
}
