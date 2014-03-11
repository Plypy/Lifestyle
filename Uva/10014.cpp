//¡Ω¥Œ¿€º” 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cstring>
using namespace std;
const int MAXN = 3005;
double s[MAXN];
double a0, an1;
int n;
int main() {
    int t;
    scanf("%d", &t);
    cout << fixed << setprecision(2);
    while (t--) {
        memset(s,0,sizeof(s));
        scanf("%d", &n);
        scanf("%lf%lf", &a0, &an1);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", s+i);
            s[i] += s[i-1];
            s[0] += s[i];
        }
        double ans = (n*a0+an1-2*s[0])/(n+1);
        cout << ans << endl;
        if (t)
            cout << endl;
    }
    return 0;
} 
