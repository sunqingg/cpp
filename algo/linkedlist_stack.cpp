//
// Created by Administrator on 2023/11/19.
//

#include "./utils/common.hpp"

class LinkedListStack{
    private:
        ListNode *stackTop;
        int stkSize;
    public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }
    ~LinkedListStack(){
        freeMemoryLinkedList(stackTop);
    }

    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    int size() {
        return stkSize;
    }
    bool is_Empty() {
        return size() == 0;

    }

    int top() {
        if (is_Empty()){
            throw out_of_range("栈为空");
        }
        return stackTop->val;
    }

    void pop() {
        int num = top();
        ListNode *tmp = stackTop;
        tmp = stackTop->next;
        stackTop = tmp;
        delete tmp;
        stkSize--;
    }
    vector<int> toVector() {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
    void printList(){
        for (int i = 0; i < size(); ++i) {
            cout<<"第"<<i+1<<"个值是: "<<this->toVector()[i]<<endl;
        }
    }

};

int main(){
    LinkedListStack l1;
    l1.push(9);
    l1.push(8);
    l1.push(7);
    l1.push(6);
    l1.push(5);
    cout<< l1.top()<<endl;

    l1.printList();
//    vector<int> l2 = l1.toVector();
//    cout<<l2[0];
}