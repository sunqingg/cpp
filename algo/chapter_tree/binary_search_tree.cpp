//
// Created by Administrator on 2023/11/25.
//
/*查找节点*/
#include "../utils/common.hpp"

TreeNode *search(int num){
    TreeNode *cur;
    while (cur != nullptr){
        if (cur->val = num){
            return cur;
        }
        else if (num > cur->val)
            cur = cur->right;
        else if (num < cur->val){
            cur = cur->left;
        }
    }
}

int main() {

}