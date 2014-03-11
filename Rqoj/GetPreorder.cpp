//简单的递归
//不需要先构建树再输出
//可以直接在求的时候一并输出 
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Problem
{
private:
    string postorder;
    string inorder;
    int len;
public:
    void output(int ist, int ied, int pst, int ped)
    {
        char rt = postorder[ped];
        cout << rt;
        if (ist < ied)
        {
            int ipos = inorder.find(rt);
            int lsize = ipos-ist;
            int rsize = ied-ipos;
            if (lsize)
                output(ist,ipos-1,pst,pst+lsize-1);
            if (rsize)
                output(ipos+1,ied,pst+lsize,ped-1);
        }
    }
    int run()
    {
        cin >> inorder >> postorder;
        len = inorder.size();
        output(0,len-1,0,len-1);
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
