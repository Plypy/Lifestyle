#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <numeric>
#include <list>
#include <iterator>
using namespace std;
bool cmp(const int &a, const int &b)
{
    if (a < b)
        return true;
    return false;
}
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    vector<int> ivec;
    for (int i = 0; i < n; ++i)
        ivec.push_back(rand());
    sort(ivec.begin(),ivec.end(),cmp);
    
    for (int i = 0; i < n; ++i)
        cout << ivec[i] << ' ';
    cout << endl;
    
    list<int> ilst1;
    copy(ivec.begin(),ivec.end(),inserter(ilst1,ilst1.begin()));
    for (list<int>::iterator itr = ilst1.begin();
        itr != ilst1.end(); ++itr)
        cout << *itr << ' ';
    cout << endl;
    
    ilst1.clear();
    copy(ivec.begin(),ivec.end(),front_inserter(ilst1));
    for (list<int>::iterator itr = ilst1.begin();
        itr != ilst1.end(); ++itr)
        cout << *itr << ' ';
    cout << endl;
    
    ilst1.clear();
    copy(ivec.begin(),ivec.end(),back_inserter(ilst1));
    for (list<int>::iterator itr = ilst1.begin();
        itr != ilst1.end(); ++itr)
        cout << *itr << ' ';
    cout << endl;
    
    for (list<int>::reverse_iterator itr = ilst1.rbegin();
        itr != ilst1.rend(); ++itr)
        cout << *itr << ' ';
    cout << endl;
    
    system("pause");
    return 0;
}
