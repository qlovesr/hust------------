void  TriSqList(SqList  &A,SqList  B,SqList  C)
{
/**********Begin**********/
int i, j = 0, k = 0;
    int newIndex = 0;  // 用于记录 A 中未被删除的元素的新存储位置

    // 遍历 A 中的每个元素
    for(i = 0; i < A.length; i++){
        int x = A.elem[i];
        // 在 B 中移动 j，直到 B.elem[j] >= x 或 j 超出范围
        while(j < B.length && B.elem[j] < x)
            j++;
        // 在 C 中移动 k，直到 C.elem[k] >= x 或 k 超出范围
        while(k < C.length && C.elem[k] < x)
            k++;
        // 如果 x 同时出现在 B 和 C 中，则跳过 x，否则保留x到A中
        if(j < B.length && B.elem[j] == x && k < C.length && C.elem[k] == x)
            ; // x 出现于 B 和 C ，不保留（即删除）
        else
            A.elem[newIndex++] = x;
    }
    // 更新 A 的长度
    A.length = newIndex;

 /**********End**********/
}