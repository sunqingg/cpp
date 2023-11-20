//
// Created by Administrator on 2023/11/20.
//


#include "./utils/common.hpp"
struct DoublyListNode{
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int num):val(num),next(nullptr),prev(nullptr) {
    }
    DoublyListNode():val(0),next(nullptr),prev(nullptr){
    }
};

class LinkedlistDeque{
private:
    int dequesize;
    DoublyListNode *dequefront;
    DoublyListNode *dequeback;
public:
    LinkedlistDeque(){
        dequesize = 0;
        dequefront = nullptr;
        dequeback = nullptr;
    }
    int size() {
        return dequesize;
    }
    bool isEmpty() {
        return size() == 0;
    }
    void push_front(int num) {
        DoublyListNode *node = new DoublyListNode(num);
        if (dequefront == nullptr){
            dequefront = node;
            dequefront->next = node;
            dequeback = node;
            dequeback->prev = node;
            dequesize++;
        } else{
            node->next = dequefront;
            dequefront = node;
            dequesize++;
        }
    }
    int peekFirst(){
       return dequefront->val;
    }
    void push_back(int num) {
        DoublyListNode *node = new DoublyListNode(num);
        if (dequeback == nullptr){
            dequefront = node;
            dequefront->next = node;
            dequeback = node;
            dequeback->prev = node;
            dequesize++;
        } else{
            node->prev = dequeback;
            dequeback = node;
            dequesize++;
        }
    }
    int pop(bool isFront){
        if (isEmpty()){
            throw out_of_range("空的就别删了吧!!!");
        }
        int num;
        if (isFront){
            DoublyListNode *fNext = dequefront->next;
            num = dequefront->val;
            if (fNext != nullptr){
                fNext->prev = nullptr;
                dequefront->next = nullptr;
                delete dequefront;
            }
            dequefront = fNext;
        } else{
            num = dequefront->val;
            DoublyListNode *rprev = dequeback->prev;
            if (rprev != nullptr){
                rprev->next = nullptr;
                dequeback->prev= nullptr;
                delete dequeback;
            }
            dequeback = rprev;
        }
        return num;
    }

    int pop_front(){
        return pop(true);
    }
    int pop_back(){
        return pop(false);
    }
};


int main(){
    LinkedlistDeque *lq1 = new LinkedlistDeque();
    lq1->push_front(99);
    lq1->push_front(88);
    lq1->push_front(77);
    lq1->push_front(66);
    lq1->push_front(55);
    int num = lq1->peekFirst();
    cout<<num<<endl;
    int n2=  lq1->pop_front();
    printf("删除的值是: %d",n2);
    int n3 = lq1->peekFirst();
    cout<<n3<<endl;
}