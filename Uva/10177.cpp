#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
inline ll sqr(ll a) {
    return a*a;
}
int main() {
    ll n;
    while (EOF != scanf("%lld", &n)) {
        ll t = (n+1)*n/2;
        
        ll r2 = t*t;
        ll s2 = n*(n+1)*(2*n+1)/6;
        r2 -= s2;
        
        ll r3 = t*t*t;
        ll s3 = sqr(n*(n+1)/2);
        r3 -= s3;
        
        ll r4 = sqr(t*t);
        ll s4 = (6*n*n*n*n*n+15*n*n*n*n+10*n*n*n-n)/30;
        r4 -= s4;
        printf("%lld %lld %lld %lld %lld %lld\n", s2, r2, s3, r3, s4, r4);
    }
    return 0;
}
