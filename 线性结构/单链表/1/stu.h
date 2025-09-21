status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L == NULL) {
        L = (LinkList)malloc(sizeof(LNode));
        if (L == NULL) return INFEASIBLE;
        L->next = NULL;
        return OK;
    }
    else {
        return INFEASIBLE;
    }
    /********** End **********/
}