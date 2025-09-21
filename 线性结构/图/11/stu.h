// 全局变量
bool visited[MAX_VERTEX_NUM];
void (*globalVisit)(VertexType);
ALGraph *globalG;

// 辅助DFS函数
void DFS(int v) {
    visited[v] = true; // 标记当前顶点为已访问
    globalVisit(globalG->vertices[v].data); // 访问当前顶点
    ArcNode *p = globalG->vertices[v].firstarc; // 获取当前顶点的邻接表
    while (p != NULL) { // 遍历邻接表
        if (!visited[p->adjvex]) { // 如果邻接顶点未被访问
            DFS(p->adjvex); // 递归访问邻接顶点
        }
        p = p->nextarc; // 移动到下一个邻接顶点
    }
}

status DFSTraverse(ALGraph &G, void (*visit)(VertexType)) {
    // 初始化全局变量
    for(int i = 0; i < MAX_VERTEX_NUM; i++) {
        visited[i] = false;
    }
    globalVisit = visit;
    globalG = &G;
    
    // 遍历所有顶点，确保每个顶点都被访问
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // 如果顶点未被访问
            DFS(i); // 从该顶点开始深度优先搜索
        }
    }
    return OK; // 返回成功状态
}