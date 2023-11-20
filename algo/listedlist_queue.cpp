//
// Created by Administrator on 2023/11/20.
//

#include "./utils/common.hpp"

class LinkedListQueue{
private:
    ListNode *rear,*front;
    int queueSize;
public:
    LinkedListQueue() {
        rear = nullptr;
        front = nullptr;
        queueSize = 0;
    }
    int size(){
        return queueSize;
    }
    bool isEmpty(){
        return size() == 0;
    }
    void push(int num){
        ListNode *p = new ListNode(num);
        if (front == nullptr) {
            front = p;
            rear = p;
        }
        else {
            rear->next = p;
            rear = p;
        }
//        p->next = nullptr;
//        rear->next = p;
//        rear = p;
//        if (front == nullptr){
//            front = rear;
//        }
        queueSize++;

    }
    int peek(){
        return front->val;
    }
    int pop(){
        int num = front->val;
        ListNode *p;
        p = front;
        front = front->next;
        delete(p);
        return num;
    }
    vector<int> toVector(){
        vector<int> res(size());
        ListNode *l1 = front;
        for (int i = 0; i < size(); ++i) {
            res[i] = l1->val;
            l1 = l1->next;
        }
        return res;

    }
};

int main(){
    LinkedListQueue *q1 = new LinkedListQueue();
    q1->push(1);
    q1->push(3);
    q1->push(2);
    q1->push(5);
    q1->push(4);
    cout<<q1->size()<<endl;
    cout<<q1->peek()<<endl;
    vector<int> v1=  q1->toVector();
    for (int i = 0; i < v1.size(); ++i) {
        cout<<v1[i]<<endl;
    }
}