//
// Created by Administrator on 2023/12/4.
//

#include "../utils/common.hpp"

class GraphAdjList{
public:
    //邻接表,key;顶点,value:该顶点的所有邻接顶点
    unordered_map<Vertex *,vector<Vertex *>> adjList;
    /* 在vector中删除指定节点 */
    void remove(vector<Vertex *> &vec,Vertex *vet){
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == vet){
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }
    /*构造方法 */
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        for (const vector<Vertex *> &edge : edges){
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0],edge[1]);
        }
    }
    /* 获取顶点数量 */
    int size() {
        return adjList.size();
    }
    /* 添加边*/
//    void addEdge(Vertex *vet1, Vertex *vet2){
//        if (!adjList.count(vet1) || !adjList.count(vet2) ||vet1 == vet2)
//            throw invalid_argument("不存在顶点");
//        // 添加边 vet1 -> vet2
//        adjList[vet1].push_back(vet2);
//        adjList[vet2].push_back(vet1);
//    }
    void addEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
            throw invalid_argument("不存在顶点");
        }
        // 添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    /* 删除边 */
    void removeEdge(Vertex *vet1,Vertex *vet2){
        if (!adjList.count(vet1) || !adjList.count(vet2) ||vet1 == vet2)
            throw invalid_argument("不存在顶点");
        remove(adjList[vet1],vet2);
        remove(adjList[vet2],vet1);
    }
    /*添加顶点 */
    void addVertex(Vertex *vet){
        if (adjList.count(vet)){
            return;
        }
        adjList[vet] = vector<Vertex *>();
    }
    /* 删除节点 */
    void removeVertex(Vertex *vet){
        if (!adjList.count(vet)){
            throw invalid_argument("不存在顶点");
        }
        adjList.erase(vet);
        for (auto &adj:adjList){
            remove(adj.second,vet);
        }
    }
    /* 打印邻接表 */
    void print() {
        cout << "邻接表" << endl;
        for (auto &adj:adjList){
            const auto &key = adj.first;
            const auto &value = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(value));
        }
    }
};



int main() {
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{1, 3, 2, 5, 4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后,图为: " << endl;
    graph.print();
}




















