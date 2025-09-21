status ListDelete(SqList &L, int i, ElemType &e)
{
    /********** Begin *********/
    // 若顺序表不存在，返回INFEASIBLE
    if(L.elem == NULL)
        return INFEASIBLE;
    // 删除位置必须合法
    if(i < 1 || i > L.length)
        return ERROR;
    
    // 保存要删除的元素
    e = L.elem[i-1];
    
    // 从第i个元素起，将后面的元素向前移动，覆盖删除位置
    // 注意：L.elem + L.length - 1 表示最后一个元素的地址
    for(ElemType *p = &(L.elem[i-1]); p < L.elem + L.length - 1; p++)
         *p = *(p + 1);
    
    // 更新线性表的长度
    L.length--;
    
    // // 下面可选择对存储空间进行缩减（非必须）
    // if(L.listsize - L.length >= LISTINCREMENT)
    // {
    //     ElemType *newbase = (ElemType *) realloc(L.elem, (L.listsize - LISTINCREMENT) * sizeof(ElemType));
    //     if(newbase != NULL)
    //     {
    //         L.elem = newbase;
    //         L.listsize -= LISTINCREMENT;
    //     }
    //     // 如果realloc失败，不做处理，仍保留原空间
    // }
    
    return OK;
    /********** End **********/
}