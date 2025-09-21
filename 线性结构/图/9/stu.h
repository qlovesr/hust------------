status InsertArc(ALGraph &G, KeyType v, KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, pos_v = -1, pos_w = -1;
    // 查找顶点v的位序
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data.key == v) {
            pos_v = i;
            break;
        }
    }
    // 查找顶点w的位序
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data.key == w) {
            pos_w = i;
            break;
        }
    }
    // 如果v或w不存在，返回ERROR
    if(pos_v == -1 || pos_w == -1) {
        return ERROR;
    }
    
    // 检查是否已存在弧<v,w>
    ArcNode *p = G.vertices[pos_v].firstarc;
    while(p != NULL) {
        if(p->adjvex == pos_w) {
            return ERROR; // 弧<v,w>已存在
        }
        p = p->nextarc;
    }
    
    // 检查是否已存在弧<w,v>（对于无向图，两个方向都要检查）
    p = G.vertices[pos_w].firstarc;
    while(p != NULL) {
        if(p->adjvex == pos_v) {
            return ERROR; // 弧<w,v>已存在
        }
        p = p->nextarc;
    }
    
    // 创建新弧节点 v->w
    ArcNode *new_arc1 = (ArcNode*)malloc(sizeof(ArcNode));
    if(new_arc1 == NULL) {
        return ERROR; // 内存分配失败
    }
    new_arc1->adjvex = pos_w;
    new_arc1->nextarc = G.vertices[pos_v].firstarc;
    G.vertices[pos_v].firstarc = new_arc1;
    
    // 创建新弧节点 w->v（对于无向图需要添加两条弧）
    ArcNode *new_arc2 = (ArcNode*)malloc(sizeof(ArcNode));
    if(new_arc2 == NULL) {
        // 释放之前分配的内存
        G.vertices[pos_v].firstarc = new_arc1->nextarc;
        free(new_arc1);
        return ERROR;
    }
    new_arc2->adjvex = pos_v;
    new_arc2->nextarc = G.vertices[pos_w].firstarc;
    G.vertices[pos_w].firstarc = new_arc2;
    
    G.arcnum++; // 增加弧数（注意：对于无向图，虽然插入了两条弧，但只算一条边）
    return OK;
    /********** End **********/
}