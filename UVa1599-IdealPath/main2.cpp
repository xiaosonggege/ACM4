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
    }
    pq->front->next = pTemp->next;
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
    void InOrderTraverse_no_cur_no_stack(BiTree T, void (*visit)(char e)); //中序非递归无堆栈遍历二叉树
    void PostOrderTraverse(BiTree &T, void (*visit)(char e)); //后序遍历二叉树
    void LevelOrderTraverse(BiTree &T, void (*visit)(char e)); //层序遍历二叉树
    void DestroyBiTree(BiTree &T); //销毁二叉树
    void BiTNodeFind(BiTree &T, char value, BiTree &result); //二叉搜索树的查找算法
    void BiTNodeInsert(BiTree &T, char value); //二叉搜索树的插入算法
    ///////////////////////////////////实验1-2//////////////////////////////////
    printf("/////////////////////实验1-2/////////////////////\n");
    char input[] = "ABC#D#E";
    printf("输入为:%s\n", input);
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    CreateBiTree(root, input, sizeof(input)/sizeof(char)-1);
    printf("先序遍历! ");
    PreOrderTraverse(root, visit);
    printf("\n");
    printf("中序遍历! ");
    InOrderTraverse(root, visit);
    printf("\n");
    printf("后序遍历! ");
    PostOrderTraverse(root, visit);
    printf("\n");
    printf("层序遍历! ");
    LevelOrderTraverse(root, visit);
    printf("\n");
    printf("非递归且不用栈中序遍历二叉树! ");
    InOrderTraverse_no_cur_no_stack(root, visit);
    printf("\n");
    DestroyBiTree(root);
    printf("\n\n");
/////////////////////////实验3///////////////////////////////
    printf("/////////////////////实验3/////////////////////\n");
    char input2[] = "IDOAELZ";
    printf("输入为:%s\n", input2);
    BiTree root1 = (BiTree)malloc(sizeof(BiTNode));
    CreateBiTree(root1, input2, sizeof(input2)/sizeof(char)-1);
    printf("先序遍历结果:\n");
    PreOrderTraverse(root1, visit);
    printf("\n");
    printf("中序序遍历结果:\n");
    InOrderTraverse(root1, visit);
    printf("\n");
    ///////////二叉搜索树插入算法////////
    printf("插入结点值为:%c时的中序遍历结果为:\n", 'B');
    BiTNodeInsert(root1, 'B');
    InOrderTraverse(root1, visit);
    printf("\n");

    printf("插入结点值为:%c时的中序遍历结果为:\n", 'F');
    BiTNodeInsert(root1, 'F');
    InOrderTraverse(root1, visit);
    printf("\n");

    printf("插入结点值为:%c时的中序遍历结果为:\n", 'P');
    BiTNodeInsert(root1, 'P');
    InOrderTraverse(root1, visit);
    printf("\n");

    ////////////二叉搜索树查找算法////////
    BiTree result;
    printf("查找元素为:%c时的查找结果为:\n", 'O');
    BiTNodeFind(root1, 'O', result);
    if (result) printf("%c\n", result->data);
    else printf("结点不存在!\n");

    printf("查找元素为:%c时的查找结果为:\n", 'A');
    BiTNodeFind(root1, 'A', result);
    if (result) printf("%c\n", result->data);
    else printf("结点不存在!\n");

    printf("查找元素为:%c时的查找结果为:\n", 'R');
    BiTNodeFind(root1, 'R', result);
    if (result) printf("%c\n", result->data);
    else printf("结点不存在!\n");
    DestroyBiTree(root1);
    return 0;
}
void visit(char e){
    printf("%c ", e);
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
        if (pos != size){
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
void InOrderTraverse_no_cur_no_stack(BiTree T, void (*visit)(char e)){ //本函数不用引用根结点，而是直接值传递
    while (T){
        if (T->lchild == NULL) {
            visit(T->data);
            T = T->rchild;
        }
        else{
            BiTree pre = T; //记录当前父结点位置
            T = T->lchild;
            pre->lchild = NULL;
            BiTree move = T;
            while (move->rchild != NULL) move = move->rchild;
            move->rchild = pre;
        }
    }
}
void BiTNodeFind(BiTree &T, char value, BiTree &result){
    if (!T) result = NULL; //如果树为空
    else {
        if (value == T->data) {
            result = T;
        }
        else if (value < T->data) BiTNodeFind(T->lchild, value, result);
        else BiTNodeFind(T->rchild, value, result);
    }
}
void BiTNodeInsert(BiTree &T, char value){
    BiTree Ts = T;
    BiTree node = (BiTree)malloc(sizeof(BiTNode));
    node->data = value;
    if (!node) exit(EOVERFLOW);

    if (!Ts) Ts->data = value;
    else {
        BiTree follow;
        int flag = 0;
        while (!flag){
            follow = Ts;
            if (value < Ts->data) {
                if (Ts->lchild) Ts = Ts->lchild;
                else {
                    Ts->lchild = node;
                    flag = 1;
                }
            }

            else {
                if (Ts->rchild) Ts = Ts->rchild;
                else {
                    Ts->rchild = node;
                    flag = 1;
                }
            }
        }
    }
}
