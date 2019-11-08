//
// Created by xiaosong on 2019/11/7.
//

#include "class_file.h"
#include <tuple>
using namespace std;
graph::graph(const string &paths, const int &points, const int &edges):
path(paths), point_num(points), edge_num(edges) {
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    string temp_s;
    int basic_info_finish = 0;
    vector<tuple<int, int, int>> info; //存储无向图中的结点间的连接信息
    getline(ifstrm, temp_s);
    istringstream istr(temp_s);
    while (getline(ifstrm, temp_s)){
        if (!basic_info_finish) {
            istr >> this->point_num >> this->edge_num;
            basic_info_finish = 1 - basic_info_finish;
        }
        else{
            int temp_p1, temp_p2, color;
            istr >> temp_p1 >> temp_p2 >> color;
            info.push_back(make_tuple(temp_p1, temp_p2, color));
        }
    }
    //对linjiebiao进行赋值
    this->linjiebiao = vector<node>(this->point_num, node());

    ifstrm.close();
}

graph::graph(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
}

graph::graph(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    g.path.clear();
    g.linjiebiao.clear();
}

graph &graph::operator=(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    return *this;
}

graph &graph::operator=(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    g.path.clear();
    g.linjiebiao.clear();
    return *this;
}

