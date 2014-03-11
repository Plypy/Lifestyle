/*
 *  第三题 优先级队列 
 *  与第二题一样不提供文件输入输出
 *  而是提供屏幕输入输出，方便测试 
 */
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
const int DEFAULT_SIZE = 500;           //默认循环队列的大小 
typedef class circular_que              //循环队列类 
{
private:
    int *numlist;               //数组指针 
    int MAXSIZE;
    int bg, ed;
public:
    circular_que(int _size = DEFAULT_SIZE)    //建立空队列的构造函数 
    {
        numlist = new int[_size];//动态分配内存 
        MAXSIZE = _size;
        bg = ed = 1;
        numlist[0] = 0;         //哨兵元素 
    }
    ~circular_que()             //析构函数 
    {
        delete[] numlist;
    }
    bool isempty()                  //判断队列是否为空 
    {
        if (bg == ed && !numlist[0])
            return true;
        return false;
    }
    bool isfull()                   //判断队列是否已经满了 
    {
        if (bg == ed && numlist[0])
            return true;
        return false;
    }
    void insert(int val)            //向队首添加元素 
    {
        numlist[0] = 1;
        numlist[ed] = val;        //更新哨兵 
        ++ed;
        if (ed >= MAXSIZE)
            ed = 1;
    }
    void del()                    //删除队首元素
    {
        ++bg;
        if (bg >= MAXSIZE)
            bg = 1;
        if (bg == ed)               //更新哨兵 
            numlist[0] = 0;
    }
    int front()                     //返回队首元素 
    {
        return numlist[bg];
    }
} cirque;
inline int min(int a, int b)
{
    return a<b?a:b;
}
const int FLAG = 10101010;
typedef class que_with_class
{
private:
    int *wtree;                     //胜者树 用来判定有元素且有最高优先级的队列序号 
    int csize;
    cirque *qlist;                //不同优先级的循环队列 
    void update(int id)//更新胜者树 
    {
        int pos = id+1+csize;
        if (qlist[id].isempty())
            wtree[pos] = FLAG;
        while (pos > 1)
        {
            pos >>= 1;
            wtree[pos] = min(wtree[pos<<1],wtree[(pos<<1)+1]);
        }
    }
public:
    que_with_class(int _size = DEFAULT_SIZE)
    {
        csize = _size;
        wtree = new int[(_size<<1)+10];
        qlist = new cirque[_size];
        for (int i = 1; i <= (_size<<1); ++i)
            wtree[i] = FLAG;
    }
    void addpcq(int val, int kth)//向优先级为kth的队列中添加元素val 
    {
        if (qlist[kth].isfull())
        {
            cout << "This que is full, already." << endl;
            return;
        }
        qlist[kth].insert(val);
        wtree[kth+1+csize] = kth;
        update(kth);
    }
    void delpcq()//删除有元素的最高优先级队列的队首元素 
    {
        if (wtree[1] != FLAG)
        {
            qlist[wtree[1]].del();
            update(wtree[1]);
            return;
        }
        cout << "There isn't any element." << endl;
    }
    int top()//返回有元素的最高优先级队列的队首元素 
    {
        if (wtree[1] != FLAG)
        {
            return qlist[wtree[1]].front();
        }
        else
            cout << "There isn't any element." << endl;
    }
} quecw;
int k;
int main()
{
    cout << "Please enter an integer to determine k:" << endl;
    cin >> k;
    while (k <= 0)
    {
        cout << "K must be a postive integer." << endl;
        cout << "Please enter an integer again:" << endl;
        cin >> k;
    }
    quecw QC(k);
    cout << "Now you can use 4 orders, which are addpcq, delpcq, top and quit" << endl;
    cout << "Here are the formats:" << endl;                                    //命令的格式
    cout << "1.\"addpcq x class\"(x and class are two integers)" << endl;
    cout << "2.\"delpcq\"" << endl;
    cout << "3.\"top\"" << endl;
    cout << "4.\"quit\"" << endl;
    string order;               //存储命令 
    while (1)
    {
        cin >> order;
        if ("addpcq" == order)//添加 
        {
            int kth, val;
            cin >> val >> kth;
            QC.addpcq(val,kth);
        }
        else if ("delpcq" == order)//删除最高优先级元素 
        {
            QC.delpcq();
        }
        else if ("top" == order)//返回最高优先级元素 
        {
            cout << "The value is " << QC.top() << endl;
        }
        else if ("quit" == order)//退出 
        {
            break;
        }
        else//错误命令 
        {
            cout << "Your order is not valid. Please try again." << endl;
        }
    }
    cout << "Byebye" << endl;
    system("pause");
    return 0;
}
