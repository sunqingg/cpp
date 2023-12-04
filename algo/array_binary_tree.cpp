//
// Created by Administrator on 2023/11/22.
//

#include "./utils/common.hpp"

class ArrayBinaryTree{
private:
    vector<int> tree;
public:
    ArrayBinaryTree(vector<int> arr){
        tree = arr;
    }
    /*
     * 节点数量
     */
    int size() {
        return tree.size();
    }
    /*
     * 获取索引为i节点的值
     */
    int val(int i) {
        if (i<0 || i>size()) {
            return INT_MAX;
        }
        return tree[i];
    }
    /*
     * 获取索引为i节点的左子节点的索引
     */
    int left(int i) {
        if (2*i+1 >size()-1){
            cout<<"没有左节点"<<endl;
        }
        return 2*i+1;
    }
    /*
     * 获取索引为i节点的右子节点索引
     */
    int right(int i) {
        if (2*i+2 >size()-1){
            cout<<"没有右节点"<<endl;
        }
        return 2*i+2;
    }
    /*
     * 获取索引
     */
};