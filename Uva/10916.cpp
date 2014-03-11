#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int FIRST_YEAR = 1960;
const int FIRST_SIZE = 4;
const int PERIOD = 10;

int main() {
    int year;
    while (scanf("%d", &year),year) {
        int tmp = (year-FIRST_YEAR)/PERIOD;
        int size = FIRST_SIZE << tmp;
        double len = 0;
        int ans = 1;
        while (floor(len)+1 <= size)
            len += log2(++ans);
        printf("%d\n", ans-1);
    }
    return 0;
}
