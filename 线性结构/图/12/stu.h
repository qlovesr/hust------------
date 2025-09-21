status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    bool visited[MAX_VERTEX_NUM] = {false}; // 访问标记数组
    int queue[MAX_VERTEX_NUM]; // 队列数组
    int front = 0, rear = 0; // 队列的前后指针
    for(int i = 0; i < G.vexnum; i++) {
        if(!visited[i]) { // 如果顶点i未被访问
            visited[i] = true; // 标记为已访问
            visit(G.vertices[i].data); // 访问顶点i
            queue[rear++] = i; // 将顶点i入队
            
            while(front < rear) { // 当队列不为空
                int v = queue[front++]; // 出队一个顶点v
                ArcNode *p = G.vertices[v].firstarc; // 获取顶点v的邻接表
                
                while(p != NULL) { // 遍历邻接表
                    if(!visited[p->adjvex]) { // 如果邻接顶点未被访问
                        visited[p->adjvex] = true; // 标记为已访问
                        visit(G.vertices[p->adjvex].data); // 访问邻接顶点
                        queue[rear++] = p->adjvex; // 将邻接顶点入队
                    }
                    p = p->nextarc; // 移动到下一个邻接顶点
                }
            }
        }
    }
    return OK; // 返回成功状态

    /********** End **********/
}