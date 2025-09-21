status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p) {
            ArcNode *temp = p;
            p = p->nextarc;
            free(temp);
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        G.vertices[i].firstarc = NULL;
    }
    return OK;

    /********** End **********/
}
