//
// Created by Administrator on 2023/11/20.
//

#include "./utils/common.hpp"

int main(){
    deque<int> deque;

    deque.push_front(3);
    deque.push_front(1);
    deque.push_back(2);
    deque.push_back(5);
    deque.push_back(4);

    int front = deque.front();
    int back = deque.back();
    cout<<"ͷ:"<<front<<"β:"<<back<<endl;
    deque.pop_front();
    deque.pop_back();
    int size = deque.size();
    bool empty = deque.empty();
    cout<<"�ߴ�:"<<size<<"�ǿ���:"<<empty<<endl;
}

