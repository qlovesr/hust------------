status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
        return INFEASIBLE;

    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(L.elem == NULL)
        return OVERFLOW;  
    
    L.length = 0;              
    L.listsize = LIST_INIT_SIZE; 
    return OK;

    /********** End **********/
}