//
// Created by Administrator on 2023/11/25.
//

#include "../utils/common.hpp"

class ArrayBinaryTree{
private:
    vector<int> tree;
public:
    vector<int> res;
    ArrayBinaryTree(vector<int> arr):tree(arr){}

    int size(){
        return tree.size();
    }
    int left(int i){
        return 2*i +1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }

    void preOrder(int index=0) {
//        res.clear();
        if (index > size()-1){
            return ;
        }
        if (tree[index] != INT_MAX){
            res.push_back(tree[index]);
            preOrder(left(index));
            preOrder(right(index));
        }


    }
    void inOrder(int index=0) {
//        res.clear();
        if (index > size()-1){
            return ;
        }
        if (tree[index] != INT_MAX){
//            cout<<index<<endl;
            inOrder(left(index));
            res.push_back(tree[index]);
            inOrder(right(index));
        }

    }
    void postOrder(int index=0) {
//        res.clear();
        if (index > size()-1){
            return ;
        }
        if (tree[index] != INT_MAX){
            postOrder(left(index));
            postOrder(right(index));
            res.push_back(tree[index]);
        }

    }

    void test(){
        printVector(tree);
        cout<<"tree的第15个索引: "<<tree[15]<<endl;
        cout<<tree.size();
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15};
    ArrayBinaryTree tree(arr);
    tree.preOrder();
    printVector(tree.res);
    tree.res.clear();
    tree.inOrder();
    printVector(tree.res);
    tree.res.clear();
    tree.postOrder();
    printVector(tree.res);
}