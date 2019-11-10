//
// Created by xiaosong on 2019/11/10.
//

#include "funfile.h"
#include <algorithm>
#include <utility>
using namespace std;
pair<bool, shared_ptr<node> &> find_node(const int &number1, const int &number2, graph &g, shared_ptr<node> &node_ptr) {
    *node_ptr = g.linjiebiao[number1];
    while (node_ptr && node_ptr->number == number2);
    if (node_ptr) return {0, node_ptr};
    return {1, node_ptr};
}
shared_ptr<node> &duiwei(const int &number, graph &g, shared_ptr<node> &node_ptr) {
    *node_ptr = g.linjiebiao[number];
    while (node_ptr->next)node_ptr = node_ptr->next;
    return node_ptr;
}