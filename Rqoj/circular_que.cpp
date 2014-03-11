/*
 *  第二题：循环队列 
 *  因为这道题只是让设计一个循环队列，所以不提供文件输入与输出。
 *  但是我提供了屏幕的输入输出，方便用来测试。 
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class circular_que              //循环队列类 
{
private:
    int *numlist;               //数组指针 
    int MAXSIZE;
    int bg, ed;
public:
    circular_que(int _size)    //建立空队列的构造函数 
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
    void insert(int val)
    {
        if (isfull())         //队列已满，输出错误信息 
        {
            cout << "The queue is already full."
                << " You can't insert any new element." << endl;
            cout << "Please delete something and try again." << endl;
            return ;
        }
        numlist[0] = 1;
        numlist[ed] = val;        //更新哨兵 
        ++ed;
        if (ed >= MAXSIZE)
            ed = 1;
    }
    void del()                    //删除队首元素
    {
        if (isempty())            //队列为空，输出错误信息 
        {
            cout << "The queue is empty."
                << " You can't delete until you insert some elements into this queue." << endl;
            return;
        }
        ++bg;
        if (bg >= MAXSIZE)
            bg = 1;
        if (bg == ed)               //更新哨兵 
            numlist[0] = 0;
    }
    int front()                     //返回队首元素 
    {
        if (isempty())              //队列为空，输出错误信息 
        {
            cout << "The queue is empty."
                << " Please insert something and try again." << endl;
        }
        return numlist[bg];
    }
};
int main()//主函数,提供测试 
{
    int size;
    cout << "Hello, this is the test progrom." << endl;//提示信息 
    cout << "Please enter an integer to determine the size of this circular queue:" << endl;
    cin >> size;//决定队列大小 
    while (size <= 0)           //保证队列大小为正整数 
    {
        cout << "The queue's size must be a postive integer." << endl;
        cout << "Please enter an integer again:" << endl;
        cin >> size;
    } 
    circular_que que(size);
    string order;//存储命令 
    //命令格式信息 
    cout << "You can make 4 kinds of order, which are insert, delete, front and quit" << endl;
    cout << "The formats of order are:" << endl;
    cout << "1.\"insert x\"(x is an integer)" << endl;
    cout << "2.\"delete\"" << endl;
    cout << "3.\"front\"" << endl;
    cout << "4.\"quit\"" << endl;
    while (true)
    {
        cout << "Please make an order: " << endl; 
        cin >> order;
        if ("insert" == order)//向队尾添加新元素 
        {
            int tmp;
            cin >> tmp;
            que.insert(tmp);
        }
        else if ("delete" == order)//删除队首元素 
        {
            que.del();
        }
        else if ("front" == order)//获取队首元素 
        {
            cout << "The head element's value is " << que.front() << "." << endl;
        }
        else if ("quit" == order)
        {
            break;
        }
        else//命令错误 
        {
            cout << "You havn't made an correct order, please try again." << endl;
        }
    }
    cout << "Byebye" << endl;
    system("pause");
    return 0;
} 
