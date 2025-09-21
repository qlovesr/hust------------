status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
        return INFEASIBLE;
    
    free(L.elem);  // 释放存储空间
    L.elem = NULL; // 置空
    L.length = 0;  // 重置长度
    L.listsize = 0; // 重置容量
    return OK;

    /********** End **********/
}
