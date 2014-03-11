// ��ĿҪ���������x^2-1|n��x
// ��(x+1)(x-1)|n
// ��n�ֽ��a*b����a>b
// ����(x+1)(x-1)|a*b

#include <iostream>
#include <cstdlib>
#include <set>
#include <cmath>
#include <iterator>
using namespace std;
typedef unsigned long long ull;
class Problem
{
private:
    ull n;
    set<ull> ctr;
public:
    int run()
    {
        cin >> n;
        for (ull a = 1; a*a <= n; ++a)
        {
            if (n%a == 0)
            {
                ull b = n/a;
                ull x;
                for (x = 1; x < n; x+=b)
                    if ((x+1)%a == 0)
                        ctr.insert(x);
                for (x = b-1; x < n; x+=b)
                    if ((x-1)%a == 0)
                        ctr.insert(x);
            }
        }
        ostream_iterator<ull> out(cout, "\n");
        copy(ctr.begin(),ctr.end(),out);
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
