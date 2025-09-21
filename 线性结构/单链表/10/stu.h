status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR; // 插入位置不正确
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return ERROR; // 插入位置不正确
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return ERROR; // 内存分配失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
    /********** End **********/
}
