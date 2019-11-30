//
// Created by 宋云龙 on 2019/11/29.
//
#include "stree.h"
#include <cmath>
#include <sstream>
#include <memory>
using namespace std;
patrolli::patrolli(const int &tree_deeps, const string &leaves_values, const vector<string> &roadlines):
tree_deep(tree_deeps), leaves_value(leaves_values), roadline(roadlines) {
    decltype(this->leaves_value) leaves_v(leaves_values.begin(), leaves_values.end());
    int non_leaves = pow(2, this->tree_deep) - 1; //非叶子结点个数
    this->tree_deep += 1; //加入叶子结点数量
    int leaves = pow(2, this->tree_deep) - 1; //总结点个数
    vector<BiTreeNode *> BiTreeNode_squeue;
    this->root = new BiTreeNode;
    BiTreeNode_squeue.push_back(this->root);
    stringstream str;
    str.clear();
    str << this->leaves_value;
    for (unsigned int num = 1; num != leaves;){
        BiTreeNode *nodel = new BiTreeNode;
        BiTreeNode *noder = new BiTreeNode;
        if (num >= non_leaves){
            str >> nodel->data >> noder->data;
            leaves_v.erase(leaves_v.begin());
            leaves_v.erase(leaves_v.begin());
        }
        (*BiTreeNode_squeue.begin())->lchild = nodel;
        (*BiTreeNode_squeue.begin())->rchild = noder;
        num += 2;
        BiTreeNode_squeue.push_back(nodel);
        BiTreeNode_squeue.push_back(noder);
        BiTreeNode_squeue.erase(BiTreeNode_squeue.begin());
    }

}

patrolli::~patrolli() {
    destroy(this->root);
}

patrolli::patrolli(const patrolli &p) {
    this->tree_deep = p.tree_deep;
    this->leaves_value = p.leaves_value;
    this->roadline = p.roadline;
    this->result = p.result;
}

patrolli::patrolli(patrolli &&p) {
    this->tree_deep = p.tree_deep;
    this->leaves_value = p.leaves_value;
    this->roadline = p.roadline;
    this->root = p.root;
    this->result = p.result;
    p.tree_deep = 0;
    p.leaves_value.clear();
    p.roadline.clear();
    p.result.clear();
}

patrolli &patrolli::operator=(const patrolli &p) {
    this->tree_deep = p.tree_deep;
    this->leaves_value = p.leaves_value;
    this->roadline = p.roadline;
    this->result = p.result;
    return *this;
}

patrolli &patrolli::operator=(patrolli &&p) {
    this->tree_deep = p.tree_deep;
    this->leaves_value = p.leaves_value;
    this->roadline = p.roadline;
    this->root = p.root;
    this->result = p.result;
    p.tree_deep = 0;
    p.leaves_value.clear();
    p.roadline.clear();
    p.result.clear();
    return *this;
}

ostream &patrolli::operator()(ostream &os) const {
    os << "树的深度为: " << this->tree_deep << endl;
    os << "输入路径分别为: ";
    for (auto const &e : this->roadline) os << e << " ";
    os << "叶子序列为: " << this->leaves_value << endl;
    return os;
}

void patrolli::go() {

}
void destroy(BiTreeNode *node){
    if (node){
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
    }
}