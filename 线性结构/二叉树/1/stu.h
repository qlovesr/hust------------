status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    static int idx = 0;
    static int keys[1000] = {0}; // 用于记录已出现的key
    static int key_cnt = 0;

    TElemType e = definition[idx++];

    if (e.key == 0 || e.key == -1) {
        T = NULL;
        return OK;
    }

    // 检查关键字唯一性（0/null不计入）
    for (int i = 0; i < key_cnt; i++) {
        if (keys[i] == e.key) {
            return ERROR;
        }
    }
    keys[key_cnt++] = e.key;

    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) return OVERFLOW;
    T->data = e;

    if (CreateBiTree(T->lchild, definition) == ERROR) return ERROR;
    if (CreateBiTree(T->rchild, definition) == ERROR) return ERROR;
    return OK; // 成功创建二叉树
    /********** End **********/
}
