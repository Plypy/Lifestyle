#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 300;
char buf[MAXN];
bool a[MAXN], b[MAXN];
const int TABLESIZE = 62;
char table[TABLESIZE];
inline void init() {
    int i = 0;
    for (; i < 26; ++i)
        table[i] = 'A'+i;
    for (; i < 52; ++i)
        table[i] = 'a'+i-26;
    for (; i < 62; ++i)
        table[i] = '0'+i-52;
}
int main() {
    init();
    scanf("%s", buf);
    int len = strlen(buf);
    for (int i = 0; i < len; ++i)
        a[buf[i]] = true;
    scanf("%s", buf);
    len = strlen(buf);
    for (int i = 0; i < len; ++i)
        b[buf[i]] = true;
    
    bool flag = true;
    for (int i = 0; i < TABLESIZE; ++i)
        if (a[table[i]] || b[table[i]]) {
            putchar(table[i]);
            flag = false;
        }
    if (flag)
        printf("NO!");
    putchar('\n');
    
    flag = true;
    for (int i = 0; i < TABLESIZE; ++i)
        if (a[table[i]] && b[table[i]]) {
            putchar(table[i]);
            flag = false;
        }
    if (flag)
        printf("NO!");
    putchar('\n');
    
    flag = true;
    for (int i = 0; i < TABLESIZE; ++i)
        if (a[table[i]] ^ b[table[i]]) {
            putchar(table[i]);
            flag = false;
        }
    if (flag)
        printf("NO!");
    putchar('\n');
    
    flag = true;
    for (int i = 0; i < TABLESIZE; ++i)
        if (!(a[table[i]] || b[table[i]])) {
            putchar(table[i]);
            flag = false;
        }
    if (flag)
        printf("NO!");
    putchar('\n');
//    system("pause");
    return 0;
}
