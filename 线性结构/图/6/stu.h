
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
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
    // 如果v或w不存在，返回-1
    if(pos_v == -1 || pos_w == -1) {
        return -1;
    }
    // 查找v的邻接表
    ArcNode *p = G.vertices[pos_v].firstarc;
    // 遍历邻接表，寻找w
    while(p != NULL) {
        if(p->adjvex == pos_w) {
            // 找到w后，检查下一个邻接顶点
            if(p->nextarc != NULL) {
                return p->nextarc->adjvex; // 返回下一个邻接顶点的位序
            } else {
                return -1; // w是最后一个邻接顶点
            }
        }
        p = p->nextarc; // 继续查找
    }
    return -1; // w不是v的邻接顶点

    /********** End **********/
}
