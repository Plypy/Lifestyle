#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1505;
LL hash[MAXN*MAXN],k,c;
char s[MAXN],v[30];
int main() {
    cin>>s>>v>>k;
    for(int i=0; s[i]; i++)
        for(LL j=i,kk=k,h=0; s[j]&&(v[s[j]-'a']>'0'||kk--); j++)
            hash[c++]=h=(h*131)^s[j];
    sort(hash,hash+c);
    cout << unique(a,a+c)-a << endl;
}
