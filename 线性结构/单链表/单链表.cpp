//head file//
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
/*------------------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

typedef struct {
  struct {
      char name[30]; // 线性表名称
      LinkList L;       // 线性表
  } elem[10];        // 最多管理 10 个线性表
  int length;        // 当前管理的线性表数量
} LISTS;

/*--------------*/
status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
status IntListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType &e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType cur, ElemType &pre_e);
status NextElem(LinkList L, ElemType cur, ElemType &next_e);
status ListInsert(LinkList &L, int i, ElemType e);
status ListDelete(LinkList &L, int i, ElemType &e);
status ListTrabverse(LinkList L);
status ReverseList(LinkList &L);
status RemoveNthFromEnd(LinkList &L, int n);
status SortList(LinkList &L);
status SaveList(LinkList L,char FileName[]);
status LoadList(LinkList &L,char FileName[]);
void QuickCreateList(LinkList &L);
status LocateList(LISTS &Lists, const char name[]);
status AddList(LISTS &Lists, const char name[]);
status RemoveList(LISTS &Lists, const char name[]);
// int main()

void SingleListMenu(LinkList& L){
  int op=1;
  int length;
  int i;
  int pos;
  int k;
  ElemType e;
  ElemType pre_e;
  ElemType next_e;
  ElemType deleted_e;
  // char filename[30];
  // char filename2[30];
  while(op){
      system("clear");	printf("\n\n");
      printf("      Menu for Linear Table On Sequence Structure \n");
      printf("-------------------------------------------------\n");
      printf("    	  1.InitList       10.ListInsert\n");
      printf("    	  2.DestroyList    11.ListDelete\n");
      printf("    	  3.ClearList      12.ListTrabverse\n");
      printf("    	  4.ListEmpty      13.ReverseList\n");
      printf("    	  5.ListLength     14.SortList\n");
      printf("    	  6.GetElem        15.RemoveNthFromEnd\n");
      printf("    	  7.LocateElem     16.SaveListToFile\n");
      printf("        8.PriorElem      17.LoadListFromFile\n");
      printf("        9.NextElem       18.QuickCreateList\n");  
      printf("        0. Exit\n");         
      printf("-------------------------------------------------\n");
      printf("    请选择你的操作[0~17]:");
      scanf("%d",&op);
      switch(op){


          case 1:
          if (InitList(L) == OK) {
              printf("线性表初始化成功！\n");
          }
          else {
              printf("线性表初始化失败！\n");
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
          length = IntListLength(L);
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
          if (ReverseList(L) == INFEASIBLE) {
              printf("线性表不存在！\n");
          } else {
              printf("线性表反转成功！\n");
              ListTrabverse(L);
          }
          getchar();getchar();
          break;



          case 14:
          if (SortList(L) == INFEASIBLE) {
              printf("线性表不存在！\n");
          } else {
              printf("线性表排序成功！\n");
              ListTrabverse(L);
          }
          getchar();getchar();
          break;


          case 15:
          printf("请输入要删除倒数第几个元素：");
          scanf("%d", &k);
          if (RemoveNthFromEnd(L, k) == OK) {
              printf("删除倒数第%d个元素成功！\n", k);
              ListTrabverse(L);
          } else {
              printf("删除倒数第%d个元素失败！\n", k);
          }
          getchar();getchar();
          break;



          case 16:
          printf("请输入要保存的文件名：");
          char filename[30];
          scanf("%s", filename);
          if (SaveList(L, filename) == OK) {
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
          // if (L != NULL) {
          //     printf("线性表已存在，是否销毁？(1:是, 0:否): ");
          //     int choice;
          //     scanf("%d", &choice);
          //     if (choice == 1) {
          //         DestroyList(L); // 销毁原有线性表
          //     } else {
          //         printf("未销毁原有线性表，加载失败！\n");
          //         getchar();getchar();
          //         break;
          //     }
          // }
          DestroyList(L); // 先销毁原有线性表
          if (LoadList(L, filename2) == OK) {
              printf("线性表从文件加载成功！\n");
              ListTrabverse(L);
          } else {
              printf("线性表从文件加载失败！\n");
          }
          getchar();getchar();
          break;

          case 18:
          QuickCreateList(L);
          printf("快速建表完成！\n");
          getchar();getchar();
                break;

          case 0:
          break;
  }//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()
/*----------------------------*/
int main() {
  LISTS Lists;
  Lists.length = 0;
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
              else printf("未找到线性表 '%s'！\n", name);
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
                  printf("未找到线性表 '%s'！\n", name);
                  getchar();
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


status InitList(LinkList &L)
{
    if(L == NULL) {
        L = (LinkList)malloc(sizeof(LNode));
        if (L == NULL) return INFEASIBLE;
        L->next = NULL;
        return OK;
    }
    else {
        return INFEASIBLE;
    }
}


status DestroyList(LinkList &L)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    LNode *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    free(L);
    L = NULL; // 释放表头节点
    return OK;
}



status ClearList(LinkList &L)
{
     if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    LNode *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL; // 清空线性表
    return OK;
}

status ListEmpty(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    if (L->next == NULL) return TRUE;
    else return FALSE;
}

status IntListLength(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    int length = 0;
    LNode *p = L->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

status GetElem(LinkList L, int i, ElemType &e)
{
    if (L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LNode *p = L->next;
    for (int j = 1; j < i && p != NULL; j++) {
        p = p->next;
    }
    if (p == NULL) return ERROR;
    e = p->data;
    return OK;
}

status LocateElem(LinkList L, ElemType e)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    int i = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) return 0; // 没有找到
    return i; // 找到，返回位置
}

status PriorElem(LinkList L, ElemType cur, ElemType &pre_e)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    LNode *q = NULL;
    while (p != NULL && p->data != cur) {
        q = p;
        p = p->next;
    }
    if (p == NULL || q == NULL) return ERROR; // 没有找到或没有前驱
    pre_e = q->data;
    return OK;
}

status NextElem(LinkList L, ElemType cur, ElemType &next_e)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    while (p != NULL && p->data != cur) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) return ERROR; // 没有找到或没有后继
    next_e = p->next->data;
    return OK;
}

status ListInsert(LinkList &L, int i, ElemType e)
{
    if (L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LNode *p = L;
    for (int j = 1; j < i && p != NULL; j++) {
        p = p->next;
    }
    if (p == NULL) return ERROR; // 插入位置不合法
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) return OVERFLOW; // 内存分配失败
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

status ListDelete(LinkList &L, int i, ElemType &e)
{
    if (L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LNode *p = L;
    for (int j = 1; j < i && p != NULL; j++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) return ERROR; // 删除位置不合法
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

status ListTrabverse(LinkList L)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p = L->next;
    if (p == NULL) return INFEASIBLE; // 空表
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

status ReverseList(LinkList &L)
{
    if (L == NULL) return INFEASIBLE;
    LNode *prev = NULL;
    LNode *curr = L->next;
    LNode *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    L->next = prev; // 更新头指针
    return OK;
}

status RemoveNthFromEnd(LinkList &L, int n)
{
    if (L == NULL) return INFEASIBLE;
    LNode *dummy = (LNode *)malloc(sizeof(LNode));
    dummy->next = L->next;
    LNode *first = dummy;
    LNode *second = dummy;
    for (int i = 0; i < n + 1; i++) {
        if (first == NULL) return ERROR; // n 超出范围
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    LNode *toDelete = second->next;
    second->next = toDelete->next;
    free(toDelete);
    L->next = dummy->next; // 更新头指针
    free(dummy);
    return OK;
}

status SortList(LinkList &L)
{
    if (L == NULL) return INFEASIBLE;
    LNode *p, *q;
    ElemType temp;
    for (p = L->next; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return OK;
}

status SaveList(LinkList L,char FileName[])
{
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
}

status LoadList(LinkList &L,char FileName[])
{
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
}

void QuickCreateList(LinkList &L) {
  if (L) ClearList(L);
  else InitList(L);
  printf("请输入元素（以回车结束）：");
  int x;
  char ch;
  LNode *tail = L;
  while (1) {
      int ret = scanf("%d", &x);
      ch = getchar();
      if (ret != 1 || ch == '\n') break;
      LNode *s = (LNode*)malloc(sizeof(LNode));
      s->data = x;
      s->next = NULL;
      tail->next = s;
      tail = s;
      if (ch == '\n') break;
  }
}


// 查找线性表，返回位置（1开始），未找到返回0
int LocateList(LISTS &Lists, const char name[]) {
  for (int i = 0; i < Lists.length; i++) {
      if (strcmp(Lists.elem[i].name, name) == 0)
          return i + 1;
  }
  return 0;
}

// 添加线性表
status AddList(LISTS &Lists, const char name[]) {
  if (Lists.length >= 10) return ERROR;
  strcpy(Lists.elem[Lists.length].name, name);
  Lists.elem[Lists.length].L = NULL;
  InitList(Lists.elem[Lists.length].L);
  Lists.length++;
  return OK;
}

// 移除线性表
status RemoveList(LISTS &Lists, const char name[]) {
  int pos = LocateList(Lists, name);
  if (pos == 0) return ERROR;
  DestroyList(Lists.elem[pos - 1].L);
  for (int i = pos; i < Lists.length; i++) {
      Lists.elem[i - 1] = Lists.elem[i];
  }
  Lists.length--;
  return OK;
}




    


