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
        if (isFront){
            DoublyListNode *n1;
            n1 = dequefront;
            if (dequefront->next != nullptr){

            }
        }
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
    int num = lq1->peekFirst();
    cout<<num<<endl;
}