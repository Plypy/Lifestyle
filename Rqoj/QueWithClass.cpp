/*
 *  ������ ���ȼ����� 
 *  ��ڶ���һ�����ṩ�ļ��������
 *  �����ṩ��Ļ���������������� 
 */
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
const int DEFAULT_SIZE = 500;           //Ĭ��ѭ�����еĴ�С 
typedef class circular_que              //ѭ�������� 
{
private:
    int *numlist;               //����ָ�� 
    int MAXSIZE;
    int bg, ed;
public:
    circular_que(int _size = DEFAULT_SIZE)    //�����ն��еĹ��캯�� 
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
    void insert(int val)            //��������Ԫ�� 
    {
        numlist[0] = 1;
        numlist[ed] = val;        //�����ڱ� 
        ++ed;
        if (ed >= MAXSIZE)
            ed = 1;
    }
    void del()                    //ɾ������Ԫ��
    {
        ++bg;
        if (bg >= MAXSIZE)
            bg = 1;
        if (bg == ed)               //�����ڱ� 
            numlist[0] = 0;
    }
    int front()                     //���ض���Ԫ�� 
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
    int *wtree;                     //ʤ���� �����ж���Ԫ������������ȼ��Ķ������ 
    int csize;
    cirque *qlist;                //��ͬ���ȼ���ѭ������ 
    void update(int id)//����ʤ���� 
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
    void addpcq(int val, int kth)//�����ȼ�Ϊkth�Ķ��������Ԫ��val 
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
    void delpcq()//ɾ����Ԫ�ص�������ȼ����еĶ���Ԫ�� 
    {
        if (wtree[1] != FLAG)
        {
            qlist[wtree[1]].del();
            update(wtree[1]);
            return;
        }
        cout << "There isn't any element." << endl;
    }
    int top()//������Ԫ�ص�������ȼ����еĶ���Ԫ�� 
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
    cout << "Here are the formats:" << endl;                                    //����ĸ�ʽ
    cout << "1.\"addpcq x class\"(x and class are two integers)" << endl;
    cout << "2.\"delpcq\"" << endl;
    cout << "3.\"top\"" << endl;
    cout << "4.\"quit\"" << endl;
    string order;               //�洢���� 
    while (1)
    {
        cin >> order;
        if ("addpcq" == order)//��� 
        {
            int kth, val;
            cin >> val >> kth;
            QC.addpcq(val,kth);
        }
        else if ("delpcq" == order)//ɾ��������ȼ�Ԫ�� 
        {
            QC.delpcq();
        }
        else if ("top" == order)//����������ȼ�Ԫ�� 
        {
            cout << "The value is " << QC.top() << endl;
        }
        else if ("quit" == order)//�˳� 
        {
            break;
        }
        else//�������� 
        {
            cout << "Your order is not valid. Please try again." << endl;
        }
    }
    cout << "Byebye" << endl;
    system("pause");
    return 0;
}
