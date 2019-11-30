//
// Created by 宋云龙 on 2019/11/29.
//

#ifndef ACM3_CLION_STREE_H
#define ACM3_CLION_STREE_H
#include <string>
#include <vector>
using namespace std;
struct BiTreeNode{
    char data = ' ';
    BiTreeNode *lchild = nullptr;
    BiTreeNode *rchild = nullptr;
};
class patrolli{
private:
    int tree_deep; //树的深度
    string leaves_value; //叶子结点值拼成的字符串
    vector<string> roadline; //在二叉树中各次的线路
    BiTreeNode *root = nullptr; //树根结点
    string result; //结果
public:
    patrolli() = default;
    patrolli(const int &, const string &, const vector<string> &);
    virtual ~patrolli(); //释放申请的动态内存
    patrolli(const patrolli &);
    patrolli(patrolli &&);
    patrolli & operator=(const patrolli &);
    patrolli & operator=(patrolli &&);
    ostream & operator()(ostream &) const; //打印对象中相关信息
    void buildtree(); //建树
    void go(); //译码
};
#endif //ACM3_CLION_STREE_H
