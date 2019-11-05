//
// Created by xiaosong on 2019/11/3.
//
#include "fuzhu.h"
#include <string>
#include <algorithm>
using namespace std;
int Graph_friend::fun(Graph &g, vector<int> &stack, vector<string> &all_point) {
    while (!all_point.empty()){
        string begin_point = *all_point.begin();
        int index_row = g.symbol_level[begin_point];
        //递归
        fun2(index_row, g, stack, all_point);
    }
    return 0;
}

int Graph_friend::fun2(int pos, Graph &g, vector<int> &stack, vector<string> &all_point) {
    if (find(stack.begin(), stack.end(), pos) != stack.end()){
        g.is_bound = 0;
    }
    else {
        stack.push_back(pos);
        vector<int> current_row = g.graph_matrix[pos];
        for (auto iter = current_row.begin(); iter != current_row.end(); ++iter){
            if (*iter) fun2(*iter, g, stack, all_point);
        }
        stack.erase(stack.end()-1);
    }
    return 0;
}
