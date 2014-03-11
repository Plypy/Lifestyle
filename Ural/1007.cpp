//–°¥ÌŒÛ∫¶À¿»À∞°... 
#include <iostream>
#include <string>
using namespace std;
int n;
void recover(string &seq)
{
    int sum = 0;
    int tot = 0;
    for (int i = 0; i < seq.size(); ++i)
        if (seq[i] == '1')
        {
            sum += i+1;
            ++tot;
        }
    if (seq.size() > n)
    {
        for (int i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == '1')
            {
                if ((sum-i-tot)%(n+1) == 0)
                {
                    seq.erase(i,1);
                    return;
                }
                --tot;
            }
            else
            {
                if ((sum-tot)%(n+1) == 0)
                {
                    seq.erase(i,1);
                    return;
                }
            }
        }
    }
    else if (seq.size() < n)
    {
        for (int i = 0; i < seq.size(); ++i)
        {
            if ((sum+tot+i+1)%(n+1) == 0)
            {
                seq.insert(i,1,'1');
                return;
            }
            if ((sum+tot)%(n+1) == 0)
            {
                seq.insert(i,1,'0');
                return;
            }
            if (seq[i] == '1')
                --tot;
        }
        if (sum%(n+1) == 0)
            seq += "0";
        else
            seq += "1";
    }
    else if (seq.size() == n)
    {
        int pos = sum%(n+1);
        if (pos)
            seq[pos-1] = '0';
    }
}
int main()
{
    cin >> n;
    string tmp;
    while (cin >> tmp)
    {
        recover(tmp);
        cout << tmp << endl;
    }
    //system("pause");
    return 0;
}
