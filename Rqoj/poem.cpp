#include <iostream>
#include <string>
using namespace std;
string sentence;
int main()
{
    int n;
    cin >> n;
    cin.get();
    getline(cin,sentence);
    int ct = 0;
    for (int i = 0; i < sentence.size(); ++i)
    {
        char ch = sentence[i];
        if (ct >= n && (ch == ' ' || ch == ',' || ch == '?' || ch == '.' || ch == '!'))
        {
            cout.put('\n');
            ct = 0;
        }
        cout.put(sentence[i]);
        ++ct;
    }
    return 0;
}
