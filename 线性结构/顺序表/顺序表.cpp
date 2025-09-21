/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100              
#define LISTINCREMENT  10
typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem = NULL; //存储空间基址
	int length;
	int listsize;
}SqList;

typedef struct {
    struct {
        char name[30]; // 线性表名称
        SqList L;      // 线性表
    } elem[10];        // 最多管理 10 个线性表
    int length;        // 当前管理的线性表数量
} LISTS;
/*-----page 19 on textbook ---------*/
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
status intListLength(SqList L);
status GetElem(SqList L,int i,ElemType& e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L,ElemType cur,ElemType& pre_e);
status NextElem(SqList L,ElemType cur,ElemType& next_e);
status ListInsert(SqList&L,int i,ElemType e);
status ListDelete(SqList&L,int i,ElemType& e);
status ListTrabverse(SqList L);  //简化过
status MaxSubArray(SqList L);
status SubArrayNum(SqList L, int k);
status sortList(SqList& L);
status AddList(LISTS& Lists, char name[30]);
status RemoveList(LISTS& Lists, char name[30]);
status LocateList(LISTS Lists, char name[30]);
status SaveListToFile(SqList L,char FileName[]);
status LoadListFromFile(SqList &L,char FileName[]);
/*--------------------------------------------*/
void SingleListMenu(SqList& L){
    int op=1;
    int length;
    int i;
    int pos;
    int k;
    ElemType e;
    ElemType pre_e;
    ElemType next_e;
    ElemType deleted_e;
    while(op){
        system("clear");	printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       10.ListInsert\n");
        printf("    	  2. DestroyList    11.ListDelete\n");
        printf("    	  3. ClearList      12.ListTrabverse\n");
        printf("    	  4. ListEmpty      13.MaxSubArray\n");
        printf("    	  5. ListLength     14.SortList\n");
        printf("    	  6. GetElem        15.SubArrayNum\n");
        printf("    	  7.LocateElem      16.SaveListToFile\n");
        printf("          8.PriorElem       17.LoadListFromFile\n");
        printf("          9.NextElem        0. Exit\n");          
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d",&op);
        switch(op){


            case 1:
            if (InitList(L) == OK) {
                printf("线性表创建成功！\n");
                printf("线性表初始长度：%d\n", L.length);
                printf("线性表初始容量：%d\n", L.listsize);
            } else {
                printf("线性表创建失败！\n");
            }
            getchar(); getchar();
            break;


            case 2:
            if (DestroyList(L) == OK) {
                printf("线性表销毁成功！\n");
            } else {
                printf("线性表销毁失败！\n");
            }
            getchar();getchar();
            break;


            case 3:
            if (ClearList(L) == OK) {
                printf("线性表清空成功！\n");
                printf("线性表当前长度：%d\n", L.length);
            } else {
                printf("线性表清空失败！\n");
            }    
            getchar();getchar();
            break;


            case 4:
            if (ListEmpty(L) == TRUE) {
                printf("线性表是空表！\n");
            } else {
                printf("线性表不是空表！\n");
            }    
            getchar();getchar();
            break;


            case 5:
            length = intListLength(L);
            if (length == INFEASIBLE) {
                printf("线性表不存在！\n");
            } else {
                printf("线性表当前长度：%d\n", length);
            }
            getchar();getchar();
            break;


            case 6:
            printf("请输入要获取的元素位置：");
            scanf("%d", &i);
            if (GetElem(L, i, e) == OK) {
                printf("线性表第%d个元素为：%d\n", i, e);
            } else {
                printf("获取元素失败！\n");
            }        
            getchar();getchar();
            break;


            case 7:
            printf("请输入要查找的元素：");
            scanf("%d", &e);
            pos = LocateElem(L, e);
            if (pos) {
                printf("元素%d在顺序表中的位置为：%d\n", e, pos);
            } else {
                printf("元素%d不在顺序表中！\n", e);
            }    
            getchar();getchar();
            break;


            case 8:
            printf("请输入要查找的元素：");
            scanf("%d", &e);
            if (PriorElem(L, e, pre_e) == OK) {
                printf("元素%d的前驱元素为：%d\n", e, pre_e);
            } else {
                printf("获取前驱元素失败！\n");
            }
            getchar();getchar();
            break;


            case 9:
            printf("请输入要查找的元素：");
            scanf("%d", &e);
            if (NextElem(L, e, next_e) == OK) {
                printf("元素%d的后继元素为：%d\n", e, next_e);
            } else {
                printf("获取后继元素失败！\n");
            }   
            getchar();getchar();
            break;


            case 10:
            printf("请输入要插入的元素位置和元素值：");
            scanf("%d %d", &i, &e);
            if (ListInsert(L, i, e) == OK) {
                printf("元素%d插入成功！\n", e);
                printf("线性表当前长度：%d\n", L.length);
            } else {
                printf("插入元素失败！\n");
            }    
            getchar();getchar();
            break;


            case 11:
            printf("请输入要删除的元素位置：");
            scanf("%d", &i);
            if (ListDelete(L, i, deleted_e) == OK) {
                printf("元素%d删除成功！\n", deleted_e);
                printf("线性表当前长度：%d\n", L.length);
            } else {
                printf("删除元素失败！\n");
            }
            getchar();getchar();
            break;


            case 12:    
            if(!ListTrabverse(L)) printf("线性表是空表！\n");
            getchar();getchar();
            break;


            case 13:
            if (MaxSubArray(L) == INFEASIBLE) {
                printf("线性表不存在！\n");
            } else {
                printf("线性表的最大子序列和为：%d\n", MaxSubArray(L));
            }
            getchar();getchar();
            break;



            case 14:
            if (sortList(L) == INFEASIBLE) {
                printf("线性表不存在！\n");
            } else {
                printf("线性表排序成功！\n");
                ListTrabverse(L);
            }
            getchar();getchar();
            break;


            case 15:
            printf("请输入子序列的长度：");
            scanf("%d", &k);
            if (SubArrayNum(L, k) == INFEASIBLE) {
                printf("线性表不存在！\n");
            } else {
                printf("线性表的子序列个数为：%d\n", SubArrayNum(L, k));
            }
            getchar();getchar();
            break;



            case 16:
            printf("请输入要保存的文件名：");
            char filename[30];
            scanf("%s", filename);
            if (SaveListToFile(L, filename) == OK) {
                printf("线性表保存到文件成功！\n");
            } else {
                printf("线性表保存到文件失败！\n");
            }
            getchar();getchar();
            break;
            

            case 17:
            printf("请输入要加载的文件名：");
            char filename2[30];
            scanf("%s", filename2);
            if (L.elem) {
                DestroyList(L); // 先销毁原有线性表
            }
            if (LoadListFromFile(L, filename2) == OK) {
                printf("线性表从文件加载成功！\n");
                ListTrabverse(L);
            } else {
                printf("线性表从文件加载失败！\n");
            }
            getchar();getchar();
            break;

            case 0:
            break;
    }//end of switch
    }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()
/*--------page 23 on textbook --------------------*/


status InitList(SqList& L){
    if(L.elem) return INFEASIBLE;
    L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList& L){
    if(L.elem == NULL)
        return INFEASIBLE;
    free(L.elem);  // 释放存储空间
    L.elem = NULL; // 置空
    L.length = 0;  // 重置长度
    L.listsize = 0; // 重置容量
    return OK;
}

status ClearList(SqList&L){
    if(L.elem == NULL) return INFEASIBLE;
    L.length = 0; // 重置长度
    return OK;
}

status ListEmpty(SqList L){
    if(L.elem == NULL) return INFEASIBLE;
    if(L.length == 0) return TRUE;
    else return FALSE;
}

status intListLength(SqList L){
    if(L.elem == NULL) return INFEASIBLE;
    return L.length;
}

status GetElem(SqList L,int i,ElemType& e){
    if(L.elem == NULL) return INFEASIBLE;
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}

status LocateElem(SqList L,ElemType e){ //简化过
    if(L.elem == NULL) return INFEASIBLE;
    int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i] == e) return i+1;
    return 0;
}

status PriorElem(SqList L,ElemType cur,ElemType& pre_e){
    if(L.elem == NULL) return INFEASIBLE;
    int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i] == cur) break;
    if(i==0 || i==L.length) return ERROR;
    pre_e = L.elem[i-1];
    return OK;
}

status NextElem(SqList L,ElemType cur,ElemType& next_e){
    if(L.elem == NULL) return INFEASIBLE;
    int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i] == cur) break;
    if(i==L.length-1 || i<0) return ERROR;
    next_e = L.elem[i+1];
    return OK;
}

status ListInsert(SqList&L,int i,ElemType e){
    if(L.elem == NULL) return INFEASIBLE;
    if(i<1 || i>L.length+1) return ERROR;
    if(L.length >= L.listsize){ //扩容
        ElemType * newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType * q = &(L.elem[i-1]);
    for(ElemType * p = &(L.elem[L.length-1]); p>=q; p--)
        *(p+1) = *p;
    *q = e;
    L.length++;
    return OK;
}

status ListDelete(SqList&L,int i,ElemType& e){
    if(L.elem == NULL) return INFEASIBLE;
    if(i<1 || i>L.length) return ERROR;
    ElemType * p = &(L.elem[i-1]);
    e = *p;
    ElemType * q = L.elem + L.length - 1;
    for(++p; p<=q; p++)
        *(p-1) = *p;
    L.length--;
    return OK;
}


status ListTrabverse(SqList L){
    int i;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L.length;i++){
    printf("%d ",L.elem[i]);
    }
    printf("\n------------------ end ------------------------\n");
    return L.length;
    }

status MaxSubArray(SqList L){
    int i;
    int max_sum = 0;
    int current_sum = 0;
    for(i=0;i<L.length;i++){
        current_sum += L.elem[i];
        if(current_sum > max_sum) max_sum = current_sum;
        if(current_sum < 0) current_sum = 0;
    }
    return max_sum;
}

status SubArrayNum(SqList L, int k){
    if (L.elem == NULL || L.length == 0) {
        return INFEASIBLE; 
    }
    int current_sum = 0;  
    int count = 0;        
    int prefix_sum[LIST_INIT_SIZE] = {0}; 
    prefix_sum[0] = 1;
    //prefix_sum[i]表示和为i的子序列个数
    for (int i = 0; i < L.length; i++) {
        current_sum += L.elem[i]; 
        if (current_sum >= k && prefix_sum[current_sum - k] > 0) {
            count += prefix_sum[current_sum - k];
        }
        prefix_sum[current_sum]++;
    }
    return count; 
}


status sortList(SqList& L){
    int i_2;
    int j_2;
    int temp;
    for(i_2=0;i_2<L.length-1;i_2++){
        for(j_2=0;j_2<L.length-i_2-1;j_2++){
            if(L.elem[j_2] > L.elem[j_2+1]){
                temp = L.elem[j_2];
                L.elem[j_2] = L.elem[j_2+1];
                L.elem[j_2+1] = temp;
            }
        }
    }
    return OK;
}

status SaveListToFile(SqList L,char FileName[])
{
    FILE *fp;
    if (L.elem==NULL) return INFEASIBLE; //线性表不存在，不能写文件
    if ((fp=fopen(FileName,"w"))==NULL) return ERROR; //打开文件失败
    for (int i=0;i<L.length;i++)
        fprintf(fp,"%d ",L.elem[i]); //写入线性表的元素
    fclose(fp); //关闭文件
    return OK; //写文件成功
}


status LoadListFromFile(SqList &L,char FileName[])
{
    FILE *fp;
    if ((fp=fopen(FileName,"r"))==NULL) return ERROR; //打开文件失败
    if(L.elem) return INFEASIBLE; //线性表已经存在，不能重复初始化
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)); //申请空间
    if (!L.elem) return OVERFLOW; //申请失败
    L.listsize=LIST_INIT_SIZE; //设置线性表的空间容量初值
    L.length=0; //设置元素个数初始值
    while (fscanf(fp,"%d",&L.elem[L.length])==1) //读入线性表的元素
        L.length++; //线性表长度加1
    fclose(fp); //关闭文件
    return OK; //读文件成功
}


int main() {
    LISTS Lists;
    Lists.length = 0; // 初始化线性表管理器
    int op = 1;

    while (op) {
        system("clear");
        printf("\n\n");
        printf("      多个线性表管理菜单 \n");
        printf("-------------------------------------------------\n");
        printf("1. 添加线性表       4. 显示所有线性表\n");
        printf("2. 移除线性表       5. 操作单个线性表\n");
        printf("3. 查找线性表       0. 退出\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~5]:");
        scanf("%d", &op);
        
        switch (op) {
            case 1: {
                char name[30];
                printf("请输入新线性表的名称：");
                scanf("%s", name);
            
                // 检查名称是否重复
                if (LocateList(Lists, name) > 0) {
                    printf("线性表名称 '%s' 已存在，添加失败！\n", name);
                } else {
                    if (AddList(Lists, name) == OK) {
                        printf("线性表 '%s' 添加成功！\n", name);
                    } else {
                        printf("线性表添加失败！\n");
                    }
                }
            
                getchar(); getchar();
                break;
            }
            case 2: {
                char name[30];
                printf("请输入要移除的线性表名称：");
                scanf("%s", name);
                if (RemoveList(Lists, name) == OK) printf("线性表 '%s' 移除成功！\n", name);
                else printf("线性表移除失败！\n");
                getchar(); getchar();
                break;
            }
            case 3: {
                char name[30];
                printf("请输入要查找的线性表名称：");
                scanf("%s", name);
                int pos = LocateList(Lists, name);
                if (pos > 0) printf("线性表 '%s' 的位置为：%d\n", name, pos);
                else printf("未找到线性表 '%s'！\n",name);
                getchar(); getchar();
                break;
            }
            case 4: {
                if (Lists.length == 0) {
                    printf("当前没有线性表！\n");
                } else {
                    printf("当前线性表列表：\n");
                    for (int i = 0; i < Lists.length; i++) {
                        printf("  %d. %s\n", i + 1, Lists.elem[i].name);
                    }
                }
                getchar(); getchar();
                break;
            }
            case 5: {
                char name[30];
                printf("请输入要操作的线性表名称：");
                scanf("%s", name);
                int pos = LocateList(Lists, name);
                if (pos > 0) {
                    printf("已切换到线性表 '%s'！\n", name);
                    SingleListMenu(Lists.elem[pos - 1].L);
                } else {
                    printf("未找到线性表 '%s'！\n",name);
                }
                getchar();
                break;
            }
            case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

status AddList(LISTS& Lists, char name[30]) {
    if (Lists.length >= 10) {
        return ERROR; // 超过最大线性表数量
    }
    strcpy(Lists.elem[Lists.length].name, name);
    InitList(Lists.elem[Lists.length].L);
    Lists.length++;
    return OK;
}

status RemoveList(LISTS& Lists, char name[30]) {
    int pos = LocateList(Lists, name);
    if (pos <= 0) {
        return ERROR; // 未找到线性表
    }
    DestroyList(Lists.elem[pos - 1].L);
    for (int i = pos - 1; i < Lists.length - 1; i++) {
        Lists.elem[i] = Lists.elem[i + 1];
    }
    Lists.length--;
    return OK;
}

int LocateList(LISTS Lists, char name[30]) {
    for (int i = 0; i < Lists.length; i++) {
        if (strcmp(Lists.elem[i].name, name) == 0) {
            return i + 1; // 返回线性表的位置
        }
    }
    return 0; // 未找到线性表
}


// status MySubArrayNum(SqList L, int k){
//     if (L.elem == NULL || L.length == 0) {
//         return INFEASIBLE; 
//     }
//     int count = 0;        
//     for(int i=0;i<L.length;i++){
//         int sum=0;
//         for(int j=i;j<L.length;j++){
//             sum+=L.elem[j];
//             if(sum==k) count++;
//         }
//     }
//     return count; 
// }
