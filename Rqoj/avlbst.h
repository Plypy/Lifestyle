/*
  Name: avlbst.h
  Copyright: none
  Author: Ply_py
  Date: 04-10-10 11:25
  Description: һ��AVL��ģ�����ʵ�� 
*/

#ifndef AVLBST_H_
#define AVLBST_H_
template <typename DataType>
class AVLTree
{
public:
    /* TODO (#1#): AVLTree������Ա */
    
private:
    /**** ����� ****/ 
    class AVLNode
    {
    public:
        DataType data;
        short int balanceFactor;
        AVLNode * left;
        AVLNode * right;
        /*AVLNode's ctor
         *default ctor ---- default DataType data value
         *             ---- balanceFactor is 0; each  line is empty
         */
        AVLNode():
            balanceFactor(0), left(0), right(0)
        {}
        //��ʽ���캯��  --- data���ְ���item
        //              --- ƽ������Ϊ0�� ��������Ϊ��
        AVLNode(DataType item):
            balanceFactor(0), data(item), left(0), right(0)
        {}
    };
    
    typedef AVLNode * AVLNodePointer;
    /* TODO (#1#): AVLTree���ݳ�Ա
 */
    
}; // ��AVLTree�������� 
#endif
