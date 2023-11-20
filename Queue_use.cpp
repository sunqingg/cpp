#include "iostream"
#define MAXSIZE 100
#define OVERFLOW -1
#define ERROR -2
#define OK 1
#define TRUE 1

using namespace std;
typedef int Status;
typedef string SElemType;

typedef struct SqQueue {
    SElemType *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q) {
    Q.base = new SElemType[MAXSIZE];
    if (!Q.base) return OVERFLOW;
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue(SqQueue &Q,SElemType e) {
    if ((Q.rear +1)%MAXSIZE == Q.front) return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear +1)%MAXSIZE;
    return OK;
}


Status DeQueue(SqQueue &Q,SElemType &e){
    if (Q.rear == Q.front) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front +1)%MAXSIZE;
    return OK;
}

typedef struct QNode {
    SElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    if (!Q.front) exit(OVERFLOW);
    Q.front->next = nullptr;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        QNode *p ;
        p = Q.front->next;
        free(Q.front);
        Q.front = p;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q,SElemType e) {
    
}
