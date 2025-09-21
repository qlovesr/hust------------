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
