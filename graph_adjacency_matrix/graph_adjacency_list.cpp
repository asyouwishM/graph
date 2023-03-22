#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#include"vertex.hpp"
class GraphAdjList
{
public:
    template <typename T>
    unordered_map<Vertex *, vector<Vertex *>> adjList;
};