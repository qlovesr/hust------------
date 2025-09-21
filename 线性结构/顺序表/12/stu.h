status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
        return INFEASIBLE;
    if(L.length == 0)
        return OK;
    for(int i = 0; i < L.length; i++)
        printf("%d", L.elem[i]);
    return OK;
    // 线性表L的第i个元素
    
    /********** End **********/
}