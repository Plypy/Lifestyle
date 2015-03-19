#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b ; }

LL lcm(LL a, LL b) {
    return a*b/gcd(a,b);
}

int main()
{
    //freopen("1.txt", "r", stdin);
    LL l, v1, v2, t;

    while (cin >> l >> v1 >> v2 >> t)
    {
        if (v1 < v2) swap(v1, v2);
        LL ans1 = ((v1 + v2) * t / l + 1) / 2;
        LL ans2 = ((v1 - v2) * t / l + 1) / 2;

        LL g12 = gcd(v1, v2);
        LL k1 = v1 / g12;
        LL k2 = v2 / g12;

        LL nt = t * v1 / (k1 * l);

        LL ans3 = 0;
        if ((k2 - k1) & 1)
            ans3 += (nt + 1) / 2;
        cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
        cout << ans1 + ans2 - ans3 << endl;
    }
    return 0;
}
