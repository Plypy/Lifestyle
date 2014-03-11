#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
double num[4];
bool used[4];
void dfs(int dep, double amt)
{
    if (4 == dep)
    {
        if (abs(amt-24)<0.00001)
        {
            cout << "yes";
            //system("pause");
            exit(0);
        }
        else
            return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            dfs(dep+1,amt+num[i]);
            dfs(dep+1,amt-num[i]);
            dfs(dep+1,num[i]-amt);
            if (amt!=0)
            {
                dfs(dep+1,num[i]*amt);
                dfs(dep+1,amt/num[i]);
                dfs(dep+1,num[i]/amt);
            }
            used[i] = false;
        }
    }
}
string temp("&A234567890JQK");
int main()
{
    string t;
    for (int i = 0; i < 4; i++)
    {
        cin >> t;
        if (t == "10")
            t = "0";
        else if (t == "1")
            t = "A";
        num[i] = temp.find(t);
    }
    dfs(0,0);
    cout << "no";
    return 0;
}
