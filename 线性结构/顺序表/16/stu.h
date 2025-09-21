#include<string.h>
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i;
    for(int i = 0; i < Lists.length; i++){
        if(strcmp(Lists.elem[i].name, ListName) == 0){
            return i+1; // 返回逻辑序号
        }
    }
    return 0; // 未找到

    /********** End **********/
}
