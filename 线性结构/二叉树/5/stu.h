BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) {
        return NULL;
    }
    if (T->data.key == e) {
        return T;
    }
    BiTNode* leftResult = LocateNode(T->lchild, e);
    if (leftResult != NULL) {
        return leftResult;
    }
    return LocateNode(T->rchild, e);

    /********** End **********/
}



status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree p = LocateNode(T, e); // 找到要赋值的节点
    if (!p) return ERROR;

    BiTree q = LocateNode(T, value.key); // 查找新关键字是否已存在
    if (q && q != p) return ERROR; // 存在且不是自己，失败

    p->data = value; // 赋值
    return OK;
    /********** End **********/
}
