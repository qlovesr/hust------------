   
void adjust(DuLinkList L)
{
    // 若链表元素过少（只有头结点或仅 1 个结点），直接返回
    if(L == NULL || L->next == L || L->next->next == L)
        return;
    
    // 1. 拆分为奇偶两条链表（不含头结点）
    // oddHead 指向奇链的第一个结点（a1），evenHead 指向偶链的第一个结点（a2）
    DuLinkList oddHead = L->next;
    DuLinkList evenHead = oddHead->next;
    DuLinkList oddTail = oddHead;
    DuLinkList evenTail = evenHead;
    
    DuLinkList cur = evenTail->next;
    int flag = 1; // flag 为 1 表示当前结点归入奇链，0 归入偶链
    while(cur != L) {
        if(flag) { // 分到奇数链
            oddTail->next = cur;
            cur->prior = oddTail;
            oddTail = cur;
        } else {   // 分到偶数链
            evenTail->next = cur;
            cur->prior = evenTail;
            evenTail = cur;
        }
        flag = 1 - flag;
        cur = cur->next;
    }
    // 断开原循环，结束两条链
    oddTail->next = NULL;
    evenTail->next = NULL;
    
    // 2. 反转偶数链
    DuLinkList pre = NULL;
    cur = evenHead;
    while(cur != NULL) {
        DuLinkList nxt = cur->next;
        cur->next = pre;
        // 调整 prior 指针：cur 的 prior 原来指向前驱，现在将由 nxt 指向（反转后cur->prior应指向后驱）
        if(pre != NULL)
            pre->prior = cur;
        pre = cur;
        cur = nxt;
    }
    // 反转后 pre 为新的偶数链头
    evenHead = pre;
    if(evenHead != NULL)
        evenHead->prior = NULL; // 新偶链头的 prior 置空
    
    // 3. 合并：将奇数链与反转后的偶数链连在一起
    oddTail->next = evenHead;
    if(evenHead != NULL)
        evenHead->prior = oddTail;
    
    // 找到合并后链表的尾结点
    DuLinkList newTail = oddTail;
    if(evenHead != NULL) {
        newTail = evenHead;
        while(newTail->next != NULL)
            newTail = newTail->next;
    }
    
    // 4. 重构双向循环链表：头结点 L 仍然保留，不计入有效数据
    // 连接尾结点与头结点
    newTail->next = L;
    L->prior = newTail;
    L->next = oddHead;
    oddHead->prior = L;
}

