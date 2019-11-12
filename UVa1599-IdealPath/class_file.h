//
// Created by xiaosong on 2019/11/7.
//

#ifndef ACM3_CLION_CLASS_FILE_H
#define ACM3_CLION_CLASS_FILE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <memory>
#include <utility>
using namespace std;
class node{
public:
    int number;
    vector<int> color_level; //颜色等级
    shared_ptr<node> next = make_shared<node>(); //与该结点相连的一个结点
    node() = default;
    node(const int &numbers, const vector<int> &color_levels):
    number(numbers), color_level(color_levels){}
    ~node() = default;
};
class graph{
//    friend shared_ptr<node> & duiwei(const int &number, graph &g, shared_ptr<node> &node_ptr);
    friend bool find_node(const int &number1, const int &number2, graph &g, shared_ptr<node> &node_ptr);
private:
    int point_num;
    int edge_num;
    string path;
    vector<node> linjiebiao;
    vector<pair<int, int>> dis2end;
public:
    graph() = default;
    graph(const string &, const int &points=0, const int &edges=0);
    graph(const graph &);
    graph(graph &&);
    graph & operator=(const graph &);
    graph & operator=(graph &&);

};
//shared_ptr<node> & duiwei(const int &number, graph &g, shared_ptr<node> &node_ptr);
bool find_node(const int &number1, const int &number2, graph &g, shared_ptr<node> &node_ptr);
#endif //ACM3_CLION_CLASS_FILE_H
