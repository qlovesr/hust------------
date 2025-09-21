status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
        return INFEASIBLE;
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length >= L.listsize){
        ElemType *newbase = (ElemType *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)
            return OVERFLOW;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *q = &(L.elem[i-1]);
    for(ElemType *p = &(L.elem[L.length - 1]); p >= q; p--)
        *(p + 1) = *p;
    *q = e;
    L.length++;
    return OK;
    // 线性表L的第i个元素
    // 保存在e中
    // 返回OK
    // 当插入位置不正确时，返回ERROR
    // 如果线性表L不存在，返回INFEASIBLE


    /********** End **********/
}
