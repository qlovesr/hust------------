status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    LNode *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL; // 清空线性表
    return OK;
    /********** End **********/
}
