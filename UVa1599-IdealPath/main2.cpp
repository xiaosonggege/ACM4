//
// Created by xiaosong on 2019/11/9.
//
#include <cerrno>  //头文件，用于输出异常字样
#include "stdio.h" //
#include "stdlib.h" //头文件，exit，malloc函数使用时需要
typedef struct BiTNode{ //二叉树单个节点的结构体
    char data = ' '; //二叉树数据域，本例中是字符
    struct BiTNode *lchild = NULL; //指向左子树的指针
    struct BiTNode *rchild = NULL; //指向右子树的指针
}BiTNode, *BiTree; //BiTNode表示二叉树单个节点结构体的名字，BiTree表示指向BiTNode结构体的指针，代表BiTNode*
//建立用于层序遍历队列操作的队列结构
typedef struct QueueNode{ //链式队列结构体（单个链表节点）
    BiTree data; //链表节点中的数据域为二叉树结构体指针
    QueueNode *next; //地址域存储链表节点指向的下一个节点的内存地址
}QueueNode,*QueueNode_p; //QueueNode表示链表单个节点的名字，QueueNode_p表示指向QueueNode的指针，代表QueueNode*

typedef struct Queue{ //链式队列结构体
    QueueNode_p front; //队头指针，指向单个队列节点
    QueueNode_p rear; //队尾指针，指向单个队列节点
}Queue,*Queue_p; //Queue是链式队列的名字，Queue_p是指向Queue的指针，代表Queue*
Queue_p init(Queue_p pq){ //队列初始化函数，形参为队列结构的指针
    pq->front = (QueueNode_p)malloc(sizeof(QueueNode)); //为队列头指针分配内存
    pq->front->next = NULL; //队头指针的地址域置空
    pq->rear = pq->front; //队尾指针和队头指针指向同一块内存地址
    return pq; //返回队列指针的首地址
}
void enqueue(Queue_p pq, BiTree t){ //入队函数，形参为pq为队列结构的指针，t为单个二叉树节点的指针
    //t是带入队的单个节点中要存储的值
    QueueNode_p pNew = (QueueNode_p)malloc(sizeof(QueueNode)); //定义新的队列单个节点指针pNew，并为其开辟内存空间
    pNew->data = t; //因pNew指针的数据域为二叉树单个节点，故需要将pNew指针的数据域指向形参中传入的二叉树节点地址t
    pNew->next = NULL; //将pNew指针的地址域置空
    pq->rear->next = pNew; //将队列指针pq的队尾指针的地址域用指针pNew赋值，此句起到将新的入队节点与队列连接起来的作用
    pq->rear = pNew; //将队尾指针指向新节点的地址
}

QueueNode_p dequeue(Queue_p pq){ //出队函数，形参为指向队列的指针
    QueueNode_p pTemp = (QueueNode_p)malloc(sizeof(QueueNode)); //新定义指向队列节点的指针pTemp，并为其开辟内存空间，pTemp的作用
    //是为了取得队头指针的地址，便于返回主函数
    pTemp = pq->front->next; //由于在链式队列中队头指针永远指向队列首地址的前一项，也就是head节点，故将pTemp指向队头节点后一项，即真正队
    //头的地址
    if(pTemp->next == NULL){ //如果此时队列中只有一个节点的话，那么队尾节点将和pTemp指向了同一内存，那么如果后面程序删除了pTemp的话，那
        //队尾节点就成了悬挂指针了（其指向的地址会再后面随着pTemp指针的释放而被释放了，这样不行！），故本句用来检查
        pq->rear = pq->front; //出现这种情况的时候直接将队尾指针指向队头指针，表示队列为空
    }
    pq->front->next = pTemp->next; //由于pTemp指针后续需要出队，则队头指针指向pTemp中next所指向的下一个地址
    return pTemp; //将pTemp返回主调函数
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
    printf("/////////////////////实验1/////////////////////\n");
    char input[] = "ABC#D#E";
    printf("输入为:%s\n", input);
    BiTree root = (BiTree)malloc(sizeof(BiTNode)); //定义二叉树根节点
    CreateBiTree(root, input, sizeof(input)/sizeof(char)-1); //层序创建二叉树
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
    printf("/////////////////////实验2/////////////////////\n");
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
void visit(char e){ //这个你可以看懂哦！
    printf("%c ", e);
}
BiTree & InitBiTree(BiTree &T){ //二叉树节点构造函数
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(EOVERFLOW); //二叉树节点开辟内存空间并检验是否成功开辟
    return T;
}
void PreOrderTraverse(BiTree &T, void (*visit)(char e)){ //这个你可以看懂哦！，只不过if是在写程序的时候为了退出递归而设计的，表示当
    //当前移动的指针为空的时候就不需要继续遍历了，非空才需要继续遍历，T在if里面单独出现，若非NULL，则True，否则为False
    if (T){
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}
void InOrderTraverse(BiTree &T, void (*visit)(char e)){ //这个你依然可以看懂哦！
    if (T){
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}
void PostOrderTraverse(BiTree &T, void (*visit)(char e)){ //有了前面两个，这个就是侮辱你智商的哈！
    if (T){
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}
void LevelOrderTraverse(BiTree &T, void (*visit)(char e)){ //层序遍历，也就是一层一层的遍历，无需递归，但是需要队列存储，前面的队列
    //结构就有用了
    Queue_p queue = (Queue_p)malloc(sizeof(QueueNode)); //为队列结构开辟内存，用queue指针指向这块内存
    queue = init(queue); //初始化队列
    enqueue(queue, T); //根结点入队
    while (queue->front != queue->rear){ //判断队列是否为空，这是层序遍历结束的依据
        QueueNode_p queue_front = dequeue(queue); //将队头节点出队，并赋值给queue_front，这块在循环里面的意思是每次队头指针里的左右
        //子树被遍历完后都需要出队，而每次也都是遍历当前的队头指针的左右子树，队列中其它结点会随着队头指针的出队而依次到达队头，然后被遍历，出队
        visit(queue_front->data->data); //对当前队头结点的数据域操作，此处是指针里面存指针，第一个指针是队列节点的指针，其数据域指向了二叉树单
        //节点的地址，而二叉树单个节点的数据域才是我们需要处理的哈
        if (queue_front->data->lchild) enqueue(queue, queue_front->data->lchild); //队头指针的左孩子入队，此处的指针套指针如上所述，但是需要先确保孩子非NULL
        if (queue_front->data->rchild) enqueue(queue, queue_front->data->rchild); //队头指针的右孩子入队，此处的指针套指针依然如上所述
    }
}
void CreateBiTree(BiTree &T, char string[], int size){ //层序创建二叉树，T就不用解释了，string是待读取的数据字符串，size是字符串的长度
    //本函数思路跟层序遍历基本相似，但是就是把对数据操作改为了赋值
    Queue_p queue = (Queue_p)malloc(sizeof(QueueNode)); //为队列结构开辟内存，用queue指针指向这块内存
    queue = init(queue); //初始化队列
    int pos = 0; //定义pos变量是标记当前用字符串string中的那个位置的值为二叉树节点在赋值
    T->data = *(string + (pos++)); //对当前节点数据域存入数据，string是字符指针的首地址，pos是其偏移量，也就是指向字符串中的位置，×用来取指针的值
    enqueue(queue, T); //根结点入队
    while (queue->front != queue->rear && pos != size){ //队列为空，且字符串中字符全被赋值完后就完成了
        QueueNode_p queue_front = dequeue(queue); //将队头节点出队，并赋值给queue_front，这块在循环里面的意思是每次队头指针里的左右
        if (pos != size) { //如果字符串中字符还没有被赋值完
            if (*(string + pos) != '#'){ //如果当前字符串待赋值位置不为’#‘，即非NULL
                BiTree binode_lchild = (BiTree)malloc(sizeof(BiTNode)); //开辟新的二叉树左孩子结点
                binode_lchild->data = *(string + pos); //赋值
                queue_front->data->lchild = binode_lchild; //将左孩子跟队头的左孩子指针连接起来
                enqueue(queue, binode_lchild); //左孩子入队到队尾
            }
            ++pos; //自增位置
        }
        else break;//如果字符串中字符被赋值完就可以退出了
        if (pos != size){ //如果字符串中字符还没有被赋值完
            if (*(string + pos) != '#') { //如果当前字符串待赋值位置不为’#‘，即非NULL
                BiTree binode_rchild = (BiTree)malloc(sizeof(BiTNode)); //开辟新的二叉树右孩子结点
                binode_rchild->data = *(string + pos); //赋值
                queue_front->data->rchild = binode_rchild; //将右孩子跟队头的左孩子指针连接起来
                enqueue(queue, binode_rchild); //右孩子入队到队尾
            }
            ++pos; //自增位置
        }
        else break; //如果字符串中字符被赋值完就可以退出了
    }
}
void DestroyBiTree(BiTree &T){ //二叉树结点的析构函数
    if (T){ //类似后序遍历，大致框架是借助后序遍历先依次遍历到叶子结点然后对叶子结点进行操作的技术，删除结点也需要从叶子结点开始逐渐往上一层结点删除，否则删除
        //任意非叶子结点后，其子孙结点的内存不会被删除，也无法被寻址然后删除，这样其子孙结点内存就会永远占用
        DestroyBiTree(T->lchild); //递归，一直到左叶子结点
        DestroyBiTree(T->rchild); //递归，一直到右叶子结点
        free(T); //释放结点占用的内存
    }
}
void InOrderTraverse_no_cur_no_stack(BiTree T, void (*visit)(char e)){ //本函数不用引用根结点，而是直接值传递
    //非递归、不用栈的中序遍历，大致思路是从根节点开始遍历当前结点的左子树，如果左子树为空的话就输出当前结点值，然后遍历右结点，如果左子树非空，
    //就将当前结点与左子树结点断开，当前结点连接到以左子树为子树结构的最右端叶子节点的右子树，循环这样的操作
    while (T){ //结点非空时
        if (T->lchild == NULL) { //当前结点的左子树为空
            visit(T->data); //对当前结点的data操作
            T = T->rchild; //指向右子树
        }
        else{ //当前结点非空时
            BiTree pre = T; //记录当前父结点位置
            T = T->lchild; //当前结点移动到其左子树的位置
            pre->lchild = NULL; //父节点与其左子树断开连接
            BiTree move = T; //定义另一个move指针指向当前结点
            while (move->rchild != NULL) move = move->rchild; //move指针从当前结点开始不断移动到最右端叶子结点位置
            move->rchild = pre; //将当前结点T的父节点连接到这个叶子结点的右子树上
        }
    }
}
void BiTNodeFind(BiTree &T, char value, BiTree &result){ //二叉排序树的查找算法
    if (!T) result = NULL; //如果树为空那还查个毛线
    else { //非空
        if (value == T->data) { //如果找到了，result记录找到的值
            result = T;
        }
        else if (value < T->data) BiTNodeFind(T->lchild, value, result); //如果待查找值小于当前结点的值，就递归遍历其左子树
        else BiTNodeFind(T->rchild, value, result); //如果待查找值大于等于当前节点的值，就递归遍历右子树
    }
}
void BiTNodeInsert(BiTree &T, char value){ //二叉排序树的插入算法，根据二叉排序树的性质，其插入位置只能在叶子结点处插入
    BiTree Ts = T; //定义新的指向根节点的指针，目的是要保留形参T一直指向根节点，新定义的指针会再树中移动
    BiTree node = (BiTree)malloc(sizeof(BiTNode)); //定义新的树结点指针node并为其开辟内存，用来保存待插入值，后续将其插入
    if (!node) exit(EOVERFLOW); //检验node是否内存开辟成功
    node->data = value; //将带插入值存入

    if (!Ts) Ts->data = value; //如果传入函数的二叉树就是个空的，就直接将值赋给根节点T
    else {
        int flag = 0; //插入完成的指示标记
        while (!flag){ //如果未插入完成
            if (value < Ts->data) { //如果待插入值小于当前节点值
                if (Ts->lchild) Ts = Ts->lchild; //如果当前节点不是叶子节点，移动Ts到其左子树
                else { //如果当前是叶子节点了
                    Ts->lchild = node; //叶子节点的左子树连接到node
                    flag = 1;//插入完成
                }
            }
            else { //如果待插入值大于等于当前节点值
                if (Ts->rchild) Ts = Ts->rchild; //如果当前节点不是叶子节点，移动Ts到其右子树
                else { //如果当前是叶子节点了
                    Ts->rchild = node; //叶子节点的右子树连接到node
                    flag = 1; //插入完成
                }
            }
        }
    }
}
