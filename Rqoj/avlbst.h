/*
  Name: avlbst.h
  Copyright: none
  Author: Ply_py
  Date: 04-10-10 11:25
  Description: 一个AVL树模板类的实现 
*/

#ifndef AVLBST_H_
#define AVLBST_H_
template <typename DataType>
class AVLTree
{
public:
    /* TODO (#1#): AVLTree函数成员 */
    
private:
    /**** 结点类 ****/ 
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
        //显式构造函数  --- data部分包含item
        //              --- 平衡因子为0； 两条链都为空
        AVLNode(DataType item):
            balanceFactor(0), data(item), left(0), right(0)
        {}
    };
    
    typedef AVLNode * AVLNodePointer;
    /* TODO (#1#): AVLTree数据成员
 */
    
}; // 类AVLTree声明结束 
#endif
