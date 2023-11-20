//
// Created by Administrator on 2023/1/5.
//

#include "stack_queue.h"
#include "iostream"
#define MAXSIZE 100
#define OVERFLOW -1
#define ERROR -2
#define OK 1
#define TRUE 1

using namespace std;
typedef int Status;
typedef string SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base){
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

Status ClearStack(SqStack &S){
    if (S.base) S.top = S.base;
    return OK;
}


Status DestroyStack(SqStack &S){
    if (S.base) {
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = nullptr;
    }
}

Status Push(SqStack &S,SElemType e){
    if (S.top - S.base < S.stacksize){
        *S.top = e;
        S.top ++;
        return OK;
    } else {
        printf("出栈失败！栈里面没有元素");
        return ERROR;
    }
}
void PrintStack(SqStack S) {
    if (S.top != nullptr) {
        for (int i = S.top-S.base; i >= 0; --i) {
            cout<<S.top<<endl;
//            cout<<--S.top<<endl;
//            cout<<"第"<<i<<"个值"<<S.top[i]<<endl;
            cout<<"第"<<i<<"个值"<<*--S.top<<endl;
        }
    }

}
void PrintStack1(SqStack S) {
    if (S.top != nullptr) {
        cout<<*S.top<<*S.base<<endl;
        cout<<S.top-S.base<<endl;
        for (int i = S.top-S.base; i >= 0; --i) {
            cout<<S.top<<endl;
            --S.top;

        }
    }

}

void GetTop(SqStack S, SElemType &e){
    //将栈顶指向的前一个位置的元素赋值给e
    e = *--S.top;
}

void GetTop1(SqStack S){
    cout<<"result： "<<S.top[1]<<endl;
}

int main01() {
    SqStack *S = new SqStack;
    InitStack(*S);
    SElemType e1 = "aa";
    SElemType e2 = "bb而我却二无群二无群二无群二无群二二翁群而我却二无群二", e3 = "cc";
    //入栈
    Push(*S, e1);
    Push(*S, e2);
    GetTop(*S, e1);
    cout<<e1<<endl;
    PrintStack1(*S);
}


//## #####链栈
typedef struct StackNode{
        SElemType data;
        struct StackNode *next;
    }StackNode, *LinkStack;

Status StackEmpty(StackNode *S){
    if (S->next != nullptr) return TRUE;
    return ERROR;
}

void Push(LinkStack S,SElemType &e) {
    StackNode *S1;
    S1 = new StackNode ;
    S1->data = e;
    S1->next = S;
    S=S1;
}

void Pop(LinkStack S,SElemType &e) {
    e = S->data;
    StackNode *p;
    p = S;
    S = S->next;
    delete p;
}

SElemType GetTop(LinkStack S) {
    if (S->next != nullptr) return S->data;
}
















