#include<string.h>
status AddList(LISTS &Lists,char ListName[]){
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
    if (Lists.length>=10) return ERROR; //线性表个数超过限制
    strcpy(Lists.elem[Lists.length].name,ListName); //复制线性表名称
    if (Lists.elem[Lists.length].L.elem != NULL) {
        Lists.elem[Lists.length].L.elem = NULL; // 避免重复释放
    }
    InitList(Lists.elem[Lists.length].L); //初始化线性表
    Lists.length++; //线性表个数加1
    return OK; //添加成功
    /********** End **********/
}
