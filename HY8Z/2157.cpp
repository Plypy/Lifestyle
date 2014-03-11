#include <iostream>
#include <cstdlib>
using namespace std;
int size;
void dfs(int a) {
    cout << a << ' ';
    int t = a<<1;
    if (t < size) {
        dfs(t);
        cout << a << ' ';
    }
    ++t;
    if (t < size) {
        dfs(t);
        cout << a << ' ';
    }
}
int main() {
    cin >> size;
    dfs(1);
    cout << endl;
    system("pause");
    return 0;
} 
