//
// Created by xiaosong on 2019/11/2.
//

#ifndef ACM3_CLION_GRAPH_BUILDING_H
#define ACM3_CLION_GRAPH_BUILDING_H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>
using namespace std;
class Graph{
private:
    string data; //待提取数据的字符串
    vector<pair<string, string>> data_; //提取出所有对边字母数据
    bool is_bound; //判断结果
    vector<vector<int>> graph_matrix;
public:

};
#endif //ACM3_CLION_GRAPH_BUILDING_H
