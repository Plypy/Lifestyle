#include <iostream>
using namespace std;
int mark[55];
string tmp;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++)
            switch (tmp[j])
            {
                case 'W':
                    mark[i]+=3;
                    break;
                case 'D':
                    mark[i]++;
                    mark[j+1]++;
                    break;
                case 'L':
                    mark[j+1]+=3;
                    break;
            }
    }
    for (int i = 1; i < n; i++)
        cout << mark[i] << ' ';
    cout << mark[n];
    return 0;
}
