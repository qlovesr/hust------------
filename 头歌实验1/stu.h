
int  insert(SqList &L, ElemType x){
    int i;
    // 如果当前已存元素达到数组容量，则需要扩容
    if(L.length >= L.listsize){
        // 通过 realloc 扩展内存，扩充的容量为原容量加上 LISTINCREMENT 个元素
        L.elem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!L.elem)
            exit(0);  // 内存扩充失败时，退出程序
        // 更新线性表的容量
        L.listsize += LISTINCREMENT;
    }
    
    // 从最后一个元素开始向前扫描，寻找插入 x 的合适位置。
    // 此处假设 SqList 内的元素已经按升序排列。
    for(i = L.length - 1; i >= 0; i--){
        if(L.elem[i] > x)
            // 将大于 x 的元素向后移动一位，为 x 腾出位置
            L.elem[i + 1] = L.elem[i];
        else 
            break;  // 找到第一个小于等于 x 的元素，则中止循环
    }
    
    // 当循环结束后，i 的值表示最后一个大于 x 的元素下标，
    // 因此插入 x 的正确位置是 i+1
    L.elem[i + 1] = x;
    // 更新顺序表元素个数
    L.length++;
    return 1;
}