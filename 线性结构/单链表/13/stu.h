status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (L == NULL) return INFEASIBLE;
    FILE *fp = fopen(FileName, "w");
    if (fp == NULL) return INFEASIBLE;
    LNode *p = L->next;
    while (p != NULL) {
        fprintf(fp, "%d ", p->data);
        p = p->next;
    }
    fclose(fp);
    return OK;
    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (L != NULL) return INFEASIBLE;
    FILE *fp = fopen(FileName, "r");
    if (fp == NULL) return INFEASIBLE;
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) return INFEASIBLE;
    L->next = NULL;
    LNode *tail = L;
    int data;
    while (fscanf(fp, "%d", &data) == 1) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        if (newNode == NULL) return INFEASIBLE;
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    fclose(fp);
    return OK;

    /********** End 2 **********/
}
