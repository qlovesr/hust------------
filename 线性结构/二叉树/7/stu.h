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

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
{
    // 检查关键字唯一性
    if (LocateNode(T, c.key)) return ERROR;

    if (LR == -1) { // 插入为新根
        BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
        if (!newNode) return OVERFLOW;
        newNode->data = c;
        newNode->lchild = NULL;
        newNode->rchild = T;
        T = newNode;
        return OK;
    }

    BiTNode* p = LocateNode(T, e); // 查找要插入的父节点
    if (!p) return ERROR;

    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    if (!newNode) return OVERFLOW;
    newNode->data = c;
    newNode->lchild = NULL;

    if (LR == 0) { // 插入到左子树
        newNode->rchild = p->lchild; // 原左子树作为新结点的右子树
        p->lchild = newNode;
    } else if (LR == 1) { // 插入到右子树
        newNode->rchild = p->rchild; // 原右子树作为新结点的右子树
        p->rchild = newNode;
    } else {
        free(newNode);
        return ERROR;
    }
    return OK;
}