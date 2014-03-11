#include <iostream>
#include <string>
using namespace std;
int ct[3];
int main() {
    int n;
    cin >> n;
    cin.get();
    for (int i = 1; i <= n; ++i) {
        string name;
        getline(cin,name);
        if ('M' == name[0])
            ++ct[0];
        else if ('L' == name[0])
            ++ct[1];
        else
            ++ct[2];
    }
    int maxct = 0;
    if (ct[1] > ct[maxct])
        maxct = 1;
    if (ct[2] > ct[maxct])
        maxct = 2;
    if (0 == maxct)
        cout << "Macaroni Penguin" << endl;
    else if (1 == maxct)
        cout << "Little Penguin" << endl;
    else
        cout << "Emperor Penguin" << endl;
//    system("pause");
    return 0;
}
