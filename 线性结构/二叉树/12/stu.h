status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) {
        return OK;
    }
    BiTNode* queue[100]; // 队列
    int front = 0, rear = 0; // 队列头尾指针
    queue[rear++] = T; // 入队根节点
    while (front < rear) {
        BiTNode* current = queue[front++]; // 出队
        visit(current); // 访问当前节点
        if (current->lchild) {
            queue[rear++] = current->lchild; // 入队左子树
        }
        if (current->rchild) {
            queue[rear++] = current->rchild; // 入队右子树
        }
    }
    return OK;
    /********** End **********/
}