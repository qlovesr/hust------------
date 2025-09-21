status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
        return INFEASIBLE;
    for(int i = 0; i < L.length - 1; i++){
        if(L.elem[i] == e){
            next = L.elem[i+1];
            return OK;
        }
    }
    return ERROR;
    // 线性表L的第i个元素
    // 保存在e中
    // 返回OK
    // 如果没有后继，返回ERROR


    /********** End **********/
}
