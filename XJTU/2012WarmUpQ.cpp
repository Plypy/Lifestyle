#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int ct[10] = {6,2,5,5,4,5,6,3,7,6};
int main() {
    int ans = 0;
    char buf[55];
    scanf("%s", buf);
    int len = strlen(buf);
    for (int i = 0; i < len; ++i)
        ans += ct[buf[i]-'0'];
    printf("%d\n", ans);
//    system("pause");
    return 0;
}
