int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) {
        return 0;
    } else {
        int leftDepth = BiTreeDepth(T->lchild);
        int rightDepth = BiTreeDepth(T->rchild);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
    /********** End **********/
}
