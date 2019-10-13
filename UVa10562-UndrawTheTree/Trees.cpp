//
// Created by xiaosong on 2019/10/13.
//

#include "Trees.h"
#include <iostream>
using namespace std;
UndrawTheTrees::UndrawTheTrees(const Graph &g): graph2tree(g){

}

UndrawTheTrees::UndrawTheTrees(const UndrawTheTrees &u) {
    this->graph2tree = u.graph2tree;
    this->result = u.result;
}

UndrawTheTrees::UndrawTheTrees(UndrawTheTrees &&u) {
    this->graph2tree = u.graph2tree;
    this->result = u.result;
    u.graph2tree.clear();
    u.result.clear();
}

UndrawTheTrees & UndrawTheTrees::operator=(const UndrawTheTrees &u) {
    this->graph2tree = u.graph2tree;
    this->result = u.result;
    return *this;
}

UndrawTheTrees & UndrawTheTrees::operator=(UndrawTheTrees &&u) {
    this->graph2tree = u.graph2tree;
    this->result = u.result;
    u.graph2tree.clear();
    u.result.clear();
    return *this;
}

UndrawTheTrees::~UndrawTheTrees() {

}

void UndrawTheTrees::reading() {

}

ostream & UndrawTheTrees::show(ostream &os) const &{
    os << "多叉树深度优先遍历结果如下:" << endl;
    for (auto const &e : this->result)
        os << e << " ";
    os << endl;
    return os;
}

ostream & UndrawTheTrees::operator()(ostream &os) const {
    os << "多叉树如下:" << endl;
    for (const auto &e : this->graph2tree){
        for (const auto & e2 : e)
            os << e2;
        os << endl;
    }
    return os;
}

