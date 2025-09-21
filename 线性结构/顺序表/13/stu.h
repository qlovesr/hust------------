status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
        return INFEASIBLE;
    
    FILE *fp = fopen(FileName, "w");
    if(fp == NULL)
        return INFEASIBLE;
    for(int i = 0; i < L.length; i++)
        fprintf(fp, "%d ", L.elem[i]);
    fclose(fp);
    return OK;
    // 线性表L的第i个元素
    // 线性表L的长度
    // 线性表L的存储空间大小

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "r");
    if(fp == NULL)
        return INFEASIBLE;
    L.elem = (ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(L.elem == NULL)
        return INFEASIBLE;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    while(fscanf(fp, "%d", &L.elem[L.length]) != EOF)
        L.length++;
    fclose(fp);
    if(L.length > L.listsize)
    {
        free(L.elem);
        L.elem = NULL;
        return INFEASIBLE;
    }
    return OK;
    // 线性表L的第i个元素
    // 线性表L的长度
    // 线性表L的存储空间大小


    /********** End **********/
}