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


status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
     if (T == NULL) return ERROR;
    if (T->data.key == e) {
        BiTree tmp = T;
        // 度为0
        if (T->lchild == NULL && T->rchild == NULL) {
            free(T);
            T = NULL;
        }
        // 度为1（只有左孩子）
        else if (T->lchild != NULL && T->rchild == NULL) {
            T = T->lchild;
            free(tmp);
        }
        // 度为1（只有右孩子）
        else if (T->lchild == NULL && T->rchild != NULL) {
            T = T->rchild;
            free(tmp);
        }
        // 度为2
        else {
            BiTree lc = T->lchild;
            BiTree rc = T->rchild;
            T = lc;
            // 找到左子树最右节点
            BiTree p = lc;
            while (p->rchild) p = p->rchild;
            p->rchild = rc;
            free(tmp);
        }
        return OK;
    }
    // 递归查找左右子树
    if (DeleteNode(T->lchild, e) == OK) return OK;
    if (DeleteNode(T->rchild, e) == OK) return OK;
    return ERROR;
}
    /********** End **********/
