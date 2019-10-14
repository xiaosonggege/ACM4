//
// Created by xiaosong on 2019/10/13.
//

#include "Trees.h"
#include <iostream>
using namespace std;
extern bool isletter(const char &l);
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
    void bianli(int , int , const Graph &, string &);
    this->result.push_back('(');
    //找到根节点索引位置
    for (int j = 0; j != this->graph2tree[0].size(); ++j){
        if (isletter(this->graph2tree[0][j])) {//如果是字母
            bianli(0, j, this->graph2tree, this->result);
            break;
        }
    }
    this->result.push_back(')');
}

ostream & UndrawTheTrees::show(ostream &os) const &{
    os << "多叉树深度优先遍历结果如下:" << endl;
    for (auto const &e : this->result)
        os << e;
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
void bianli(int i, int j, const Graph &graph, string &result){
    //行遍历
    for (int r = j; r !=graph[0].size(); ++r){
        if (i == 0 && graph[i][r] == ' ') break; //根节点唯一
        else if (i!=0 && graph[i-1][r] == ' ') break; //实线右边界对应该父节点的右孩子节点
        else if (isletter(graph[i][r])){ //如果是字母
            result.push_back(graph[i][r]);
            result.push_back('(');
            if ((i+1) < graph.size()){ //该节点存在孩子节点
                if (graph[i+1][r] == '|'){
                    int k = r;
                    if ((i+2) <= graph.size()) for (;graph[i+2][k] != ' ' && k!=-1; --k); //找到该节点对应的左孩子节点
                    if ((i+3) <= graph.size()){
                        bianli(i+3, k+1, graph, result); //递归遍历
                    }
                }
            }
            result.push_back(')');
        }
    }
}

