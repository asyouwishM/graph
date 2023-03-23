#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#include"vertex.hpp"
#include"PrintUtil.hpp"
class GraphAdjList
{
public:
    //邻接表，key：顶点，value该顶点的所有邻接顶点
    unordered_map<Vertex *, vector<Vertex *>> adjList;
    //在vector中删除指定节点
    void remove(vector<Vertex*> &vec, Vertex *vet)
    {
        for (int i = 0; i < vec.size();i++)
        {
            if(vec[i] == vet)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }
    //构造函数
    GraphAdjList(const vector<vector<Vertex*>> edges)
    {
        //添加所有顶点和边
        for(const vector<Vertex*> edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }
    //获取顶点数量
    int size() { return adjList.size(); }
    //添加边
    void addEdge(Vertex *vet1, Vertex *vet2)
    {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        //添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    //删除边
    void removeEdge(Vertex* vet1, Vertex* vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        //删除边 vet1 -vet2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }
    //添加顶点
    void addVertex(Vertex* vet)
    {
        if (adjList.count(vet))
            return;
        adjList[vet] = vector<Vertex *>();
    }
    //删除顶点
    void removeVertex(Vertex* vet)
    {
        if(!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        //在邻接表中删除顶点vet对应的链表
        adjList.erase(vet);
        //遍历其他顶点的链表，删除所有包含vet的边
        for (auto& [key, vec] : adjList)
        {
            remove(vec, vet);
        }
    }
    //打印邻接表
    void print()
    {
        cout << "邻接表 =" << endl;
        for (auto &adj : adjList)
        {
            const auto &key = adj.first;        // 定义一个常量引用 key，它绑定到当前循环变量 adj 的第一个元素，即指向当前顶点的指针。
            const auto &vec = adj.second;       // 定义一个常量引用 vec，它绑定到当前循环变量 adj 的第二个元素，即包含所有与当前顶点相邻的顶点指针的向量。
            cout << key->val << ": ";
            PrintUtil::printVector(vetsToVals(vec));
        }
    }
};

