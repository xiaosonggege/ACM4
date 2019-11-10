//
// Created by xiaosong on 2019/11/10.
//

#ifndef ACM3_CLION_FUNFILE_H
#define ACM3_CLION_FUNFILE_H
#include "class_file.h"
#include <vector>
#include <memory>
using namespace std;
shared_ptr<node> & duiwei(const int &number, graph &g, shared_ptr<node> &node_ptr);
bool find_node(const int &number1, const int &number2, graph &g, shared_ptr<node> &node_ptr);
#endif //ACM3_CLION_FUNFILE_H
