/*
 *  �ڶ��⣺ѭ������ 
 *  ��Ϊ�����ֻ�������һ��ѭ�����У����Բ��ṩ�ļ������������
 *  �������ṩ����Ļ����������������������ԡ� 
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class circular_que              //ѭ�������� 
{
private:
    int *numlist;               //����ָ�� 
    int MAXSIZE;
    int bg, ed;
public:
    circular_que(int _size)    //�����ն��еĹ��캯�� 
    {
        numlist = new int[_size];//��̬�����ڴ� 
        MAXSIZE = _size;
        bg = ed = 1;
        numlist[0] = 0;         //�ڱ�Ԫ�� 
    }
    ~circular_que()             //�������� 
    {
        delete[] numlist;
    }
    bool isempty()                  //�ж϶����Ƿ�Ϊ�� 
    {
        if (bg == ed && !numlist[0])
            return true;
        return false;
    }
    bool isfull()                   //�ж϶����Ƿ��Ѿ����� 
    {
        if (bg == ed && numlist[0])
            return true;
        return false;
    }
    void insert(int val)
    {
        if (isfull())         //�������������������Ϣ 
        {
            cout << "The queue is already full."
                << " You can't insert any new element." << endl;
            cout << "Please delete something and try again." << endl;
            return ;
        }
        numlist[0] = 1;
        numlist[ed] = val;        //�����ڱ� 
        ++ed;
        if (ed >= MAXSIZE)
            ed = 1;
    }
    void del()                    //ɾ������Ԫ��
    {
        if (isempty())            //����Ϊ�գ����������Ϣ 
        {
            cout << "The queue is empty."
                << " You can't delete until you insert some elements into this queue." << endl;
            return;
        }
        ++bg;
        if (bg >= MAXSIZE)
            bg = 1;
        if (bg == ed)               //�����ڱ� 
            numlist[0] = 0;
    }
    int front()                     //���ض���Ԫ�� 
    {
        if (isempty())              //����Ϊ�գ����������Ϣ 
        {
            cout << "The queue is empty."
                << " Please insert something and try again." << endl;
        }
        return numlist[bg];
    }
};
int main()//������,�ṩ���� 
{
    int size;
    cout << "Hello, this is the test progrom." << endl;//��ʾ��Ϣ 
    cout << "Please enter an integer to determine the size of this circular queue:" << endl;
    cin >> size;//�������д�С 
    while (size <= 0)           //��֤���д�СΪ������ 
    {
        cout << "The queue's size must be a postive integer." << endl;
        cout << "Please enter an integer again:" << endl;
        cin >> size;
    } 
    circular_que que(size);
    string order;//�洢���� 
    //�����ʽ��Ϣ 
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
        if ("insert" == order)//���β�����Ԫ�� 
        {
            int tmp;
            cin >> tmp;
            que.insert(tmp);
        }
        else if ("delete" == order)//ɾ������Ԫ�� 
        {
            que.del();
        }
        else if ("front" == order)//��ȡ����Ԫ�� 
        {
            cout << "The head element's value is " << que.front() << "." << endl;
        }
        else if ("quit" == order)
        {
            break;
        }
        else//������� 
        {
            cout << "You havn't made an correct order, please try again." << endl;
        }
    }
    cout << "Byebye" << endl;
    system("pause");
    return 0;
} 
