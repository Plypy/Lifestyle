#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
void mult(string&, int);
int main()
{
    string ans = "1";
    const int N = 50000;
    time_t start, end;
    start = clock();
    for (int i = 0; i < N; i++)
        mult(ans, 2);
    end = clock();
    cout << (end-start)*1000.0/CLOCKS_PER_SEC << "ms\n";
    cout << ans;
    cin.get();
    return 0;
}
void mult(string& A, int dig)
{
    int N = A.size();
    int num;
    int temp = 0;
    for (int i = N-1; i >= 0; i--)
    {
        num = A[i] - '0';
        num = dig*num +temp;
        A[i] = '0' + num%10;
        temp = num/10;
    }
    if (temp)
    {
        ostringstream os;
        os << temp;
        A = os.str() + A;
    }
}
