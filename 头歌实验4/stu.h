void TriLinkList(LinkList  A,LinkList  B,LinkList  C)
{
/**********Begin**********/
 // pre 指向当前 p 的前驱
 LinkList pre = A;  
 LinkList p = A->next;
 // 初始化两个指针用于遍历 B 和 C，从各自头结点的下一个开始
 LinkList pb = B->next, pc = C->next;
 
 while(p != NULL)
 {
     // 将 pb 前移到第一个 >= p->data 的位置
     while(pb && pb->data < p->data)
         pb = pb->next;
     // 将 pc 前移到第一个 >= p->data 的位置
     while(pc && pc->data < p->data)
         pc = pc->next;
     
     // 如果 p->data 同时出现在 B 和 C 中，则删除 p
     if(pb && pb->data == p->data && pc && pc->data == p->data)
     {
         pre->next = p->next;  // 删除 p：改变前驱的 next 指针
         free(p);              // 释放 p 的内存
         p = pre->next;        // p 指向下一个待检查的结点
     }
     else
     {
         // p 不在 B 和 C 中同时存在，保留 p，向后移动
         pre = p;
         p = p->next;
     }
 }
 /**********End**********/
}