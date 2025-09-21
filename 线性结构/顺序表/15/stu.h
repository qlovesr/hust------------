status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i,j;
    for (i = 0; i < Lists.length; i++) {
        if (strcmp(Lists.elem[i].name, ListName) == 0) { // 找到要删除的线性表
            free(Lists.elem[i].L.elem); // 释放线性表的存储空间
            for (j = i; j < Lists.length - 1; j++) {
                Lists.elem[j] = Lists.elem[j + 1]; // 将后面的线性表前移
            }
            Lists.length--; // 更新线性表个数
            return OK; // 删除成功
        }
    }
    return ERROR; // 未找到要删除的线性表
    /********** End **********/
}
