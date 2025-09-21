status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum >= MAX_VERTEX_NUM) {
        return ERROR; // 图已满，无法插入新顶点
    }
    // 检查顶点v是否已存在
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v.key) {
            return ERROR; // 顶点已存在
        }
    }
    // 将新顶点v添加到图中
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL; // 初始化新顶点的邻接表为空
    G.vexnum++; // 增加顶点数
    return OK; // 成功插入顶点

    /********** End **********/
}
