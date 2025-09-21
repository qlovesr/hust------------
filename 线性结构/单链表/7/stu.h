status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    int j = 1;
    while (p != NULL) {
        if (p->data == e) {
            return j;
        }
        p = p->next;
        j++;
    }
    return ERROR; // 如果没有找到元素e
    /********** End **********/
}
