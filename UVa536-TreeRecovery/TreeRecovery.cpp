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
treerecovery::treerecovery(const string &inputs): input(inputs) {
    istringstream istr(this->input);
    istr >> this->preorder >> this->midorder;
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
    ostream_iterator<string> out_iter(os, " ");
    istringstream istr(this->input);
    istream_iterator<string> in_iter(istr), eof;
    vector<string> temp_input(in_iter, eof);
    copy(temp_input.cbegin(), temp_input.cend(), out_iter);
    os << endl;
    return os;
}

BiTreeNode *&treerecovery::build() {
    return this->root;
}

void destroy(BiTreeNode *node) {
    if (node){
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
        node = nullptr;
    }
}
