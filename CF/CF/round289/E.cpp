#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5;
double wt[MAXN];
char str[MAXN];
char vowel[] = "AEIOUY";
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 1; i <= len; ++i) {
        wt[i] = wt[i-1]+(1.0/i);
    }
    double tmp = 0.0;
    double ans = 0.0;
    for (int i = 0; i < len; ++i) {
        tmp += wt[len-i]-wt[i];
        if (NULL != strchr(vowel, str[i])) {
            ans += tmp;
        }
    }
    printf("%.8lf\n", ans);
}
