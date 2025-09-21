status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    LNode *q = NULL;
    while (p != NULL) {
        if (p->data == e) {
            if (q == NULL) return ERROR; // 没有前驱
            pre = q->data;
            return OK;
        }
        q = p;
        p = p->next;
    }
    return ERROR; // 如果没有找到元素e
    /********** End **********/
}