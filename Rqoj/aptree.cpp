#include <iostream>
using namespace std;
int ans;
int tmp[10];
int main()
{
    for (int i = 0; i< 10; i++)
        cin >> tmp[i];
    int hit;
    cin >> hit;
    hit += 30;
    for (int i = 0; i < 10; i++)
        if (tmp[i] <= hit)
            ans++;
    cout << ans;
    return 0;
}
