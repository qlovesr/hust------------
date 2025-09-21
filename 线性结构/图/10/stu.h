status DeleteArc(ALGraph &G, KeyType v, KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, pos_v = -1, pos_w = -1;
    bool found_edge = false; // 标记是否找到了要删除的边
    
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
    
    // 删除弧<v,w>
    ArcNode *prev = NULL;
    ArcNode *curr = G.vertices[pos_v].firstarc;
    while(curr != NULL) {
        if(curr->adjvex == pos_w) {
            // 找到弧<v,w>，进行删除
            if(prev == NULL) {
                G.vertices[pos_v].firstarc = curr->nextarc; // 删除头结点
            } else {
                prev->nextarc = curr->nextarc; // 删除中间或尾部结点
            }
            free(curr); // 释放内存
            found_edge = true; // 标记找到并删除了边
            break; // 删除后退出循环
        }
        prev = curr;
        curr = curr->nextarc;
    }
    
    // 删除弧<w,v>（对于无向图需要删除两条弧）
    prev = NULL;
    curr = G.vertices[pos_w].firstarc;
    while(curr != NULL) {
        if(curr->adjvex == pos_v) {
            // 找到弧<w,v>，进行删除
            if(prev == NULL) {
                G.vertices[pos_w].firstarc = curr->nextarc; // 删除头结点
            } else {
                prev->nextarc = curr->nextarc; // 删除中间或尾部结点
            }
            free(curr); // 释放内存
            found_edge = true; // 标记找到并删除了边
            break; // 删除后退出循环
        }
        prev = curr;
        curr = curr->nextarc;
    }
    
    // 只有在找到并删除了边时才更新弧数并返回OK
    if(found_edge) {
        G.arcnum--;
        return OK; // 成功删除弧
    } else {
        return ERROR; // 边不存在，删除失败
    }
    /********** End **********/
}