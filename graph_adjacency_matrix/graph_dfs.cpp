#include"graph_adjacency_list.cpp"
#include <unordered_set>
//深度优先遍历DFS 辅助函数
void dfs(GraphAdjList& graph, unordered_set<Vertex*>& visited, vector<Vertex*>& res, Vertex* vet)
{
    res.push_back(vet);
    visited.emplace(vet);
    for (Vertex* adjVet : graph.adjList[vet])
    {
        if(visited.count(adjVet))
            continue;           //跳过已被访问的顶点
        //递归访问邻接顶点
        dfs(graph, visited, res, adjVet);
    }
}
//深度优先遍历DFS
vector<Vertex *> graphDFS(GraphAdjList &graph, Vertex *startVet)
{
    //顶点遍历序列
    vector<Vertex *> res;
    //哈希表,用于记录已被访问过的顶点
    unordered_set<Vertex *> visited;
    dfs(graph, visited, res, startVet);
    return res;
}

int main()
{
    //初始化无向图
    vector<Vertex *> v = valsToVets(vector<int>{0, 1, 2, 3, 4, 5, 6});
    vector<vector<Vertex *>> edges = {{v[0], v[1]},{v[0], v[3]},{v[1], v[2]},
                                      {v[2], v[5]},{v[4], v[5]}, {v[5], v[6]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();
    //深度优先遍历
    vector<Vertex *> res = graphDFS(graph, v[0]);
    cout << "\n深度优先遍历（DFS）顶点序列为" << endl;
    PrintUtil::printVector(vetsToVals(res));
    //释放内存
    for (Vertex* vet : v)
    {
        delete vet;
    }
    return 0;
}