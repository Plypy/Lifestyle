#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << min((a+b)/3,min(a,b)) << endl;
    return 0;
}
