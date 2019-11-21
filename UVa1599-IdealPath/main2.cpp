//
// Created by xiaosong on 2019/11/9.
//
#include <cerrno>
#include "stdio.h"
#include "stdlib.h"
typedef struct BiTNode{
    char data = ' ';
    struct BiTNode *lchild = NULL;
    struct BiTNode *rchild = NULL; //左右孩子指针
}BiTNode, *BiTree;
//建立用于层序遍历队列操作的队列结构
typedef struct QueueNode{
    BiTree data;
    QueueNode *next;
}QueueNode,*QueueNode_p;

typedef struct Queue{
    QueueNode_p front;
    QueueNode_p rear;
}Queue,*Queue_p;
Queue_p init(Queue_p pq){
    pq->front = (QueueNode_p)malloc(sizeof(QueueNode));
    pq->front->next = NULL;
    pq->rear = pq->front;
    return pq;
}
void enqueue(Queue_p pq, BiTree t){
    QueueNode_p pNew = (QueueNode_p)malloc(sizeof(QueueNode));
    pNew->data = t;
    pNew->next = NULL;
    pq->rear->next = pNew;
    pq->rear = pNew;
}

QueueNode_p dequeue(Queue_p pq){
    QueueNode_p pTemp = (QueueNode_p)malloc(sizeof(QueueNode));
    pTemp = pq->front->next;
    if(pTemp->next == NULL){
        pq->rear = pq->front;
    }else{
        pq->front->next = pTemp->next;
    }
//    QueueNode_p x = pTemp;
//    free(pTemp);
    return pTemp;
}
////////
int main(int argc, char *argv[]){
    ///////////////////////////////////函数初始化区域
    void visit(char e); //对二叉树结点操作的函数
    BiTree & InitBiTree(BiTree &T); //构造空二叉树
    void CreateBiTree(BiTree &T, char string[], int size); //根据要求次序输入二叉树中结点值
    void PreOrderTraverse(BiTree &T, void (*visit)(char e)); //先序遍历二叉树
    void InOrderTraverse(BiTree &T, void (*visit)(char e)); //中序遍历二叉树
    void InOrderTraverse_no_cur_no_stack(BiTree &T, void (*visit)(char e)); //中序非递归无堆栈遍历二叉树
    void PostOrderTraverse(BiTree &T, void (*visit)(char e)); //后序遍历二叉树
    void LevelOrderTraverse(BiTree &T, void (*visit)(char e)); //层序遍历二叉树
    void DestroyBiTree(BiTree &T); //销毁二叉树
    ///////////////////////////////////
    char input[] = "ABC#D#E";
//    printf("%lu\n", sizeof(input)/sizeof(char));
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    CreateBiTree(root, input, sizeof(input)/sizeof(char)-1);
    printf("先序遍历!");
    PreOrderTraverse(root, visit);
    printf("\n");
    printf("中序遍历!");
    InOrderTraverse(root, visit);
    printf("\n");
    printf("后序遍历!");
    PostOrderTraverse(root, visit);
    printf("\n");
    printf("层序遍历!");
    LevelOrderTraverse(root, visit);
    DestroyBiTree(root);
    return 0;
}
void visit(char e){
    printf("%c\t", e);
}
BiTree & InitBiTree(BiTree &T){
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(EOVERFLOW);
    return T;
}
void PreOrderTraverse(BiTree &T, void (*visit)(char e)){
    if (T){
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}
void InOrderTraverse(BiTree &T, void (*visit)(char e)){
    if (T){
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}
void PostOrderTraverse(BiTree &T, void (*visit)(char e)){
    if (T){
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}
void LevelOrderTraverse(BiTree &T, void (*visit)(char e)){
    Queue_p queue = (Queue_p)malloc(sizeof(QueueNode));
    queue = init(queue); //初始化队列
    enqueue(queue, T); //根结点入队
    while (queue->front != queue->rear){
        QueueNode_p queue_front = dequeue(queue);
        visit(queue_front->data->data);
        if (queue_front->data->lchild) enqueue(queue, queue_front->data->lchild);
        if (queue_front->data->rchild) enqueue(queue, queue_front->data->rchild);
    }
}
void CreateBiTree(BiTree &T, char string[], int size){
    Queue_p queue = (Queue_p)malloc(sizeof(QueueNode));
    queue = init(queue); //初始化队列
    int pos = 0;
    T->data = *(string + (pos++));
    enqueue(queue, T); //根结点入队
    while (queue->front != queue->rear && pos != size){
        QueueNode_p queue_front = dequeue(queue);
        if (pos != size) {
            if (*(string + pos) != '#'){
                BiTree binode_lchild = (BiTree)malloc(sizeof(BiTNode)); //开辟新的二叉树左孩子结点
                binode_lchild->data = *(string + pos);
                queue_front->data->lchild = binode_lchild;
                enqueue(queue, binode_lchild);
            }
            ++pos;
        }
        else break;
        if (pos != size && *(string + pos) != '#'){
            if (*(string + pos) != '#') {
                BiTree binode_rchild = (BiTree)malloc(sizeof(BiTNode)); //开辟新的二叉树右孩子结点
                binode_rchild->data = *(string + pos);
                queue_front->data->rchild = binode_rchild;
                enqueue(queue, binode_rchild);
            }
            ++pos;
        }
        else break;
    }
}
void DestroyBiTree(BiTree &T){
    if (T){
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }
}