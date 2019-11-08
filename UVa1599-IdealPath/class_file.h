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
using namespace std;
struct node{
    int color_level; //颜色等级
    int dis2end; //结点到终点结点的最短距离
    shared_ptr<node> next; //与该结点相连的一个结点
};
class graph{
private:
    int point_num;
    int edge_num;
    string path;
    vector<node> linjiebiao;
public:
    graph() = default;
    graph(const string &, const int &points=0, const int &edges=0);
    graph(const graph &);
    graph(graph &&);
    graph & operator=(const graph &);
    graph & operator=(graph &&);

};
#endif //ACM3_CLION_CLASS_FILE_H
