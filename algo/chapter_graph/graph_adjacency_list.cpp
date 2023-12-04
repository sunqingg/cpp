//
// Created by Administrator on 2023/12/4.
//

#include "../utils/common.hpp"

class GraphAdjList{
public:
    //�ڽӱ�,key;����,value:�ö���������ڽӶ���
    unordered_map<Vertex *,vector<Vertex *>> adjList;
    /* ��vector��ɾ��ָ���ڵ� */
    void remove(vector<Vertex *> &vec,Vertex *vet){
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == vet){
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }
    /*���췽�� */
    GraphAdjList(const vector<vector<Vertex *>> &edges) {
        for (const vector<Vertex *> &edge : edges){
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0],edge[1]);
        }
    }
    /* ��ȡ�������� */
    int size() {
        return adjList.size();
    }
    /* ��ӱ�*/
//    void addEdge(Vertex *vet1, Vertex *vet2){
//        if (!adjList.count(vet1) || !adjList.count(vet2) ||vet1 == vet2)
//            throw invalid_argument("�����ڶ���");
//        // ��ӱ� vet1 -> vet2
//        adjList[vet1].push_back(vet2);
//        adjList[vet2].push_back(vet1);
//    }
    void addEdge(Vertex *vet1, Vertex *vet2) {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
            throw invalid_argument("�����ڶ���");
        }
        // ��ӱ� vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    /* ɾ���� */
    void removeEdge(Vertex *vet1,Vertex *vet2){
        if (!adjList.count(vet1) || !adjList.count(vet2) ||vet1 == vet2)
            throw invalid_argument("�����ڶ���");
        remove(adjList[vet1],vet2);
        remove(adjList[vet2],vet1);
    }
    /*��Ӷ��� */
    void addVertex(Vertex *vet){
        if (adjList.count(vet)){
            return;
        }
        adjList[vet] = vector<Vertex *>();
    }
    /* ɾ���ڵ� */
    void removeVertex(Vertex *vet){
        if (!adjList.count(vet)){
            throw invalid_argument("�����ڶ���");
        }
        adjList.erase(vet);
        for (auto &adj:adjList){
            remove(adj.second,vet);
        }
    }
    /* ��ӡ�ڽӱ� */
    void print() {
        cout << "�ڽӱ�" << endl;
        for (auto &adj:adjList){
            const auto &key = adj.first;
            const auto &value = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(value));
        }
    }
};



int main() {
    /* ��ʼ������ͼ */
    vector<Vertex *> v = valsToVets(vector<int>{1, 3, 2, 5, 4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    cout << "\n��ʼ����,ͼΪ: " << endl;
    graph.print();
}




















