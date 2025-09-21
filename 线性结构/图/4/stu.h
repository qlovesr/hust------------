status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, pos = -1, count = 0;
    
    // 遍历所有顶点，统计关键字为u的顶点个数
    for(i = 0; i < G.vexnum; i++) {
        if(G.vertices[i].data.key == u) {
            count++;
            pos = i;
        }
    }
    // 只有恰好一个顶点关键字等于u时才执行赋值
    if(count == 1) {
        G.vertices[pos].data = value;
        return OK;
    } else {
        return ERROR; // 没找到或关键字不唯一
    }
    /********** End **********/
}
