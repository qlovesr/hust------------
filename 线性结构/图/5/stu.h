int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, pos = -1;
    // 遍历所有顶点，查找关键字为u的顶点
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data.key == u) {
            pos = i;
            break;
        }
    }
    // 如果找到顶点u，返回其第一邻接顶点
    if(pos != -1 && G.vertices[pos].firstarc != NULL) {
        return G.vertices[pos].firstarc->adjvex; // 返回第一邻接顶点的位序
    } else {
        return -1; // 没找到或没有邻接顶点
    }   

    /********** End **********/
}
