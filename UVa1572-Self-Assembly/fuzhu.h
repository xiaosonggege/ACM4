//
// Created by xiaosong on 2019/11/3.
//

#ifndef ACM3_CLION_FUZHU_H
#define ACM3_CLION_FUZHU_H
#include <iostream>
#include <vector>
#include <string>
#include "graph_building.h"
using namespace std;
class Graph_friend{
public:
    int fun(Graph &g, vector<int> &stack, vector<string> &all_point);
    int fun2(int pos, Graph &g, vector<int> &stack, vector<string> &all_point);
};
#endif //ACM3_CLION_FUZHU_H
