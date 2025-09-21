status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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
    free(L);
    L = NULL; // 释放表头节点
    return OK;
    /********** End **********/
}
