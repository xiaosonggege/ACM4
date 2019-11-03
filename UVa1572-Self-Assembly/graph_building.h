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
#include <map>
using namespace std;
class Graph{
private:
    string data; //待提取数据的字符串
    vector<pair<string, string>> data_; //提取出所有对边字母数据
    bool is_bound = false; //判断结果
    vector<vector<int>> graph_matrix; //建邻接表矩阵
    map<string, int> symbol_level; // 每个标记到索引的映射
public:
    Graph() = default;
    Graph(const string &datas);
    Graph(const Graph &g);
    Graph(Graph &&g);
    Graph & operator=(const Graph &g);
    Graph & operator=(Graph &&g);
    ~Graph() = default;
};
#endif //ACM3_CLION_GRAPH_BUILDING_H
