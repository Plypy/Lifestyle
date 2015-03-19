#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
    cin >> s >> t;
    int len = s.size();
    string u = s;
    int carry = 1;
    for (int i = len-1; i >= 0; --i) {
        u[i] += carry;
        carry = 0;
        if (u[i] > 'z') {
            carry = 1;
            u[i] = 'a';
        }
    }
    if (carry == 0 && u != t) {
        cout << u << endl;
    } else {
        cout << "No such string" << endl;
    }
}
