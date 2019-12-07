//
// Created by 宋云龙 on 2019/12/2.
//

#include "TreeRecovery.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <memory>
using namespace std;
treerecovery::treerecovery(const string &preorders, const string &midorders): preorder(preorders), midorder(midorders) {
//    istringstream istr(this->input);
//    istr >> this->preorder >> this->midorder;
//    cout << this->preorder << " " << this->midorder << endl;
}

treerecovery::treerecovery(const treerecovery &t) {
    this->input = t.input;
    this->preorder = t.preorder;
    this->midorder = t.midorder;
    this->root = t.root;
    this->result = t.result;
}

treerecovery::treerecovery(treerecovery &&t) {
    this->input = t.input;
    this->preorder = t.preorder;
    this->midorder = t.midorder;
    this->root = t.root;
    this->result = t.result;
    t.input.clear();
    t.preorder.clear();
    t.midorder.clear();
    destroy(t.root);
    t.result.clear();
}

treerecovery::~treerecovery() {
    destroy(this->root);
}

treerecovery &treerecovery::operator=(const treerecovery &t) noexcept {
    this->input = t.input;
    this->preorder = t.preorder;
    this->midorder = t.midorder;
    this->root = t.root;
    this->result = t.result;
    return *this;
}

treerecovery &treerecovery::operator=(treerecovery &&t) noexcept {
    this->input = t.input;
    this->preorder = t.preorder;
    this->midorder = t.midorder;
    this->root = t.root;
    this->result = t.result;
    t.input.clear();
    t.preorder.clear();
    t.midorder.clear();
    destroy(t.root);
    t.result.clear();
    return *this;
}

ostream &treerecovery::operator()(ostream &os) const {
    os << "先序遍历和中序遍历结果分别为:" << endl;
    os << this->preorder << " " << this->midorder << endl;
    os << "后序遍历结果为: " << endl;
    postorder(this->root);
    os << endl;
    return os;
}

BiTreeNode * treerecovery::build(string sub_midorder) {
    //在先序中找到子串的根节点
    auto pos = this->preorder.find_first_of(sub_midorder);
    string::iterator pos_iter = find(sub_midorder.begin(), sub_midorder.end(), this->preorder[pos]);
    shared_ptr<string> left_p = make_shared<string>(sub_midorder.begin(), pos_iter),
            right_p = make_shared<string>(pos_iter+1, sub_midorder.end());
    BiTreeNode *node = new BiTreeNode;
    node->data = *pos_iter;
    if (!this->root) this->root = node;
    if (!left_p->empty()) node->lchild = this->build(*left_p);
    if (!right_p->empty()) node->rchild = this->build(*right_p);
    return node;
}

void destroy(BiTreeNode *node) {
    if (node){
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
//        node = nullptr;
    }
}

void postorder(BiTreeNode *node){
    if (node){
        postorder(node->lchild);
        postorder(node->rchild);
        cout << node->data;
    }
}
