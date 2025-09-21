#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
   { ElemType data;
     struct node *next;
    } NODE,*LinkList;
#include "stu.h"
int main()
{
    LinkList L[3],p;
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
    	L[i]=p=(NODE *)malloc(sizeof(NODE));
    	scanf("%d",&x);
    	while (x)
    	{
				p->next=(NODE *)malloc(sizeof(NODE));
				p=p->next;
				p->data=x;
				scanf("%d",&x);
    	}
      p->next=NULL;
    }
    TriLinkList(L[0],L[1],L[2]);
    for(p=L[0]->next;p;p=p->next)
        printf(" %d",p->data);
	return 0;
}

// void TriLinkList(LinkList A, LinkList B, LinkList C)
// {
//     // pre 指向当前 p 的前驱
//     LinkList pre = A;  
//     LinkList p = A->next;
//     // 初始化两个指针用于遍历 B 和 C，从各自头结点的下一个开始
//     LinkList pb = B->next, pc = C->next;
    
//     while(p != NULL)
//     {
//         // 将 pb 前移到第一个 >= p->data 的位置
//         while(pb && pb->data < p->data)
//             pb = pb->next;
//         // 将 pc 前移到第一个 >= p->data 的位置
//         while(pc && pc->data < p->data)
//             pc = pc->next;
        
//         // 如果 p->data 同时出现在 B 和 C 中，则删除 p
//         if(pb && pb->data == p->data && pc && pc->data == p->data)
//         {
//             pre->next = p->next;  // 删除 p：改变前驱的 next 指针
//             free(p);              // 释放 p 的内存
//             p = pre->next;        // p 指向下一个待检查的结点
//         }
//         else
//         {
//             // p 不在 B 和 C 中同时存在，保留 p，向后移动
//             pre = p;
//             p = p->next;
//         }
//     }
// }
