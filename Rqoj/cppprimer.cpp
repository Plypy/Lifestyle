#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    string order;
    deque<int> que;
    const string push = "push";
    const string pop = "pop";
    int tmp;
    while (1)
    {
        cin >> order;
        if (order == "quit")
            break;
        if (order == push)
        {
            cin >> tmp;
            que.push_back(tmp);
        }
        else
        {
            cout << que.back() << endl;
            que.pop_back();
        }
    }
    cout << "Byebye!\n";
    return 0;
}
