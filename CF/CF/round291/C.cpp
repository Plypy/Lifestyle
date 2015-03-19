/**
 * This problem could be solved by trie or simply hash
 * The whole idea was centraled that brute-forcely change a character then find.
 * For hash, you could use a digit-wise weighted sum hash.
 * For trie you could use a flag to mark whether a character had been modified
 **/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int MAXN = 6e5;
const int MAGIC = 257;

set<ll> hash;
ll wt[MAXN];

void init()
{
    wt[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        wt[i] = (wt[i-1] * MAGIC) % MOD;
    }
}

ll get(char *s)
{
    int len = strlen(s);
    ll ret = 0;
    for (int i = 0; i < len; ++i) {
        ret = ret*MAGIC + s[i];
        ret %= MOD;
    }
    return ret;
}

bool find(char *s)
{
    ll orig = get(s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        for (char ch = 'a'; ch <= 'c'; ++ch) {
            if (ch == s[i]) {
                continue;
            }
            ll tmp = (orig + (ch-s[i])*wt[len-i-1]) % MOD;
            if (tmp < 0) {
                tmp += MOD;
            }
            if (hash.count(tmp)) {
                return true;
            }
        }
    }
    return false;
}

char buf[MAXN];
int main()
{
    int n, m;
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        hash.insert(get(buf));
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        if (find(buf)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
