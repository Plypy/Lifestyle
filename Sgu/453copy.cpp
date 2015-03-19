#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>


using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}
ll cal(ll a,ll b,ll t,ll l){
    ll g=gcd(2*a,b);
    ll ka=(a*t/l-1)/2;
    if (l>t*a) return 0;
    b=b/g;
    a=(2*a)/g;
    if (a%2==0) return 0;
    return (2*ka+1)/a-ka/a;
}
int main(){
    ll l,a,b,t;
    while (cin >> l >> a >> b >> t) {
        if (a>b) swap(a,b);
        ll lb=b*t%(2*l);
        ll la=a*t%(2*l);
        ll ans=(b*t/(2*l))*2;
        cout << ans << endl;
        if (la>l) la=la-l;
        else la=l-la;
        if (lb<l&&la<=lb) ans++;
        else if (lb>=l&&la+lb>=2*l) ans+=2;
        else if (lb>=l) ans++;
        cout << ans << endl;
        ans=ans-cal(a,b,t,l)-cal(b,a,t,l);
        cout << ans << endl;
    }
    return 0;
}
