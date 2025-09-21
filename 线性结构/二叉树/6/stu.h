BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL || T->data.key == e) {
        return NULL; // 如果树为空或当前节点就是要查找的节点，返回NULL
    }
    if (T->lchild && T->lchild->data.key == e) {
        return T->rchild; // 如果左子节点是要查找的节点，返回右子节点
    }
    if (T->rchild && T->rchild->data.key == e) {
        return T->lchild; // 如果右子节点是要查找的节点，返回左子节点
    }
    // 递归查找
    BiTNode* sibling = GetSibling(T->lchild, e);
    if (sibling) {
        return sibling; // 如果在左子树中找到了兄弟节点，返回
    }
    sibling = GetSibling(T->rchild, e);
    return sibling; // 如果在右子树中找到了兄弟节点，返回

    /********** End **********/
}
