#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string tmp;
    getline(cin, tmp);
    string sent;
    getline(cin, sent);
    sent[0] = tolower(sent[0]);
    int pos = sent.find(" is ");
    if ("How" == tmp)
    {
        cout << "How " << sent.substr(pos+4,sent.size()-pos-5) << ' '
            << sent.substr(0,pos+3) << '!';
    }
    else
        cout << "What " << sent.substr(pos+4,sent.size()-pos-5) << ' '
            << sent.substr(0,pos+3) << '!';
    return 0;
}
