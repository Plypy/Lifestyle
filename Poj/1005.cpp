#include <stdio.h>
#include <math.h>
#define RATE 50.0
#define PI_2 1.57079632679489661923
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        double area = PI_2*(x*x+y*y);
        int ans = int(floor(area/RATE))+1;
        printf("Property %d: This property will begin eroding in year %d.\n", i, ans);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}