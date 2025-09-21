status DeleteVex(ALGraph &G, KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, pos = -1;
    int deleted_arcs = 0; // 记录删除的弧数
    
    // 查找顶点v的位序
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data.key == v) {
            pos = i;
            break;
        }
    }
    
    // 如果顶点v不存在，返回ERROR
    if(pos == -1) {
        return ERROR;
    }
    // // 如果图中只有一个顶点，不允许删除（变成空图）
    // if (G.vexnum == 1) {
    //     return ERROR;
    // }
    
    // 统计和释放从v出发的弧
    ArcNode *p = G.vertices[pos].firstarc;
    while(p != NULL) {
        deleted_arcs++; // 计数要删除的边
        ArcNode *temp = p;
        p = p->nextarc;
        free(temp);
    }
    
    // 删除指向v的弧，并更新其他顶点的邻接表
    for(i = 0; i < G.vexnum; i++) {
        if(i == pos) continue; // 跳过要删除的顶点
        
        ArcNode *prev = NULL;
        ArcNode *curr = G.vertices[i].firstarc;
        
        while(curr != NULL) {
            if(curr->adjvex == pos) {
                // 找到指向v的弧，删除它
                deleted_arcs++;
                if(prev == NULL) {
                    G.vertices[i].firstarc = curr->nextarc;
                } else {
                    prev->nextarc = curr->nextarc;
                }
                ArcNode *temp = curr;
                curr = (prev == NULL) ? G.vertices[i].firstarc : prev->nextarc;
                free(temp);
            } else {
                // 调整大于pos的adjvex值
                if(curr->adjvex > pos) {
                    curr->adjvex--; // 顶点下标减1
                }
                prev = curr;
                curr = curr->nextarc;
            }
        }
    }
    
    // 删除顶点v，其他顶点前移
    for(i = pos; i < G.vexnum - 1; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    
    // 更新图的信息
    G.vexnum--;
    G.arcnum -= deleted_arcs;
    
    return OK;
    /********** End **********/
}