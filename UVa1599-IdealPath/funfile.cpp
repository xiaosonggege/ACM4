//
// Created by xiaosong on 2019/11/10.
//

#include "funfile.h"
#include <algorithm>
#include <utility>
using namespace std;
bool find_node(const int &number1, const int &number2, graph &g, node_ptr &node_p) {
    node_p = &g.linjiebiao[number1-1];
    //若头结点存址为空
    if (!node_p->next)return 0;
    while (node_p->number != number2 && node_p->next) node_p = node_p->next;
    if (node_p->number != number2) return 0;
    return 1;
}