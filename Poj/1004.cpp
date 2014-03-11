
#include <stdio.h>
#define MONTHS 12
int main() {
    double sum = 0.0;
    for (int i = 0; i < MONTHS; ++i) {
        double tmp;
        scanf("%lf", &tmp);
        sum += tmp;
    }
    sum /= MONTHS;
    printf("$%.2lf\n", sum);
    return 0;
}
        
