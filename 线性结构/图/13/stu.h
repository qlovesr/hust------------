status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
   FILE *fp = fopen(FileName, "w");
    if (fp == NULL) {
        return ERROR; // 文件打开失败
    }
    // 写入顶点数和弧数
    fprintf(fp, "%d %d\n", G.vexnum, G.arcnum);
    // 写入每个顶点的信息
    for (int i = 0; i < G.vexnum; i++) {
        fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    
    // 创建访问标记数组，避免对无向图的边重复保存
    bool visited[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {false};
    
    // 写入每条弧的信息
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            int j = p->adjvex;
            // 对于无向图，只保存一次边(i,j)或(j,i)
            if (!visited[i][j] && !visited[j][i]) {
                fprintf(fp, "%d %d\n", G.vertices[i].data.key, G.vertices[p->adjvex].data.key);
                visited[i][j] = true;
            }
            p = p->nextarc;
        }
    }
    fclose(fp); // 关闭文件
    return OK; // 返回成功状态
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "r");
    if (fp == NULL) {
        return ERROR; // 文件打开失败
    }
    // 读取顶点数和弧数
    fscanf(fp, "%d %d", &G.vexnum, &G.arcnum);
    if (G.vexnum > MAX_VERTEX_NUM) {
        fclose(fp);
        return ERROR; // 顶点数超过最大限制
    }
    // 初始化顶点数组
    for (int i = 0; i < G.vexnum; i++) {
        fscanf(fp, "%d %s", &G.vertices[i].data.key, G.vertices[i].data.others);
        G.vertices[i].firstarc = NULL; // 初始化邻接表为空
    }
    // 读取每条弧的信息
    for (int i = 0; i < G.arcnum; i++) {
        KeyType v1, v2;
        fscanf(fp, "%d %d", &v1, &v2);
        int pos_v1 = -1, pos_v2 = -1;
        // 查找顶点v1和v2的位序
        for (int j = 0; j < G.vexnum; j++) {
            if (G.vertices[j].data.key == v1) {
                pos_v1 = j;
            }
            if (G.vertices[j].data.key == v2) {
                pos_v2 = j;
            }
        }
        // 如果顶点存在，则添加弧
        if (pos_v1 != -1 && pos_v2 != -1) {
            ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
            p->adjvex = pos_v2;
            p->nextarc = G.vertices[pos_v1].firstarc;
            G.vertices[pos_v1].firstarc = p;

            // 对于无向图，添加反向弧
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->adjvex = pos_v1;
            p->nextarc = G.vertices[pos_v2].firstarc;
            G.vertices[pos_v2].firstarc = p;
        }
    }
    fclose(fp); // 关闭文件
    return OK; // 返回成功状态


    /********** End 2 **********/
}
