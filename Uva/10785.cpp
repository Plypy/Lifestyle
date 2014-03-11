#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int VNUM = 5, MAXV = 21;
const int CNUM = 21, MAXC = 5;
char vowel[VNUM] = {'A', 'U', 'E', 'O', 'I'};// sort by the value of each
char conso[CNUM] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W',
                    'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        int c = n>>1;
        int v = n-c;
        vector<char> vlis;
        for (int j = 1, ct = 0, pos = 0; j <= v; ++j) {
            vlis.push_back(vowel[pos]);
            if (MAXV == ++ct) {
                ct = 0;
                ++pos;
            }
        }
        sort(vlis.begin(),vlis.end());
        
        vector<char> clis;
        for (int j = 1, ct = 0, pos = 0; j <= c; ++j) {
            clis.push_back(conso[pos]);
            if (MAXC == ++ct) {
                ct = 0;
                ++pos;
            }
        }
        sort(clis.begin(),clis.end());
        
        printf("Case %d: ", i);
        for (int j = 1, vct = 0, cct = 0; j <= n; ++j) {
            if (j&1)
                putchar(vlis[vct++]);
            else
                putchar(clis[cct++]);
        }
        puts("");
    }
    return 0;
}
