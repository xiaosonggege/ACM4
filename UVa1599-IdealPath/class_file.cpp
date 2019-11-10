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
    for (int num = 0; num != this->point_num; ++num) this->linjiebiao[num].number = num+1;
    shared_ptr<node> node_move; //建立邻接表中横向移动指针
    for (auto const &e : info){
        this->linjiebiao[get<0>(e)].next = make_shared<node>(get<2>(e)); //结点距离最终结点最小值初始化为0，next指向nullptr

    }
    ifstrm.close();
    //初始化dis2end
    int i = 1;
    while (i != this->point_num+1){
        this->dis2end.push_back(make_pair(i++, 0));
    }
}

graph::graph(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
}

graph::graph(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    g.path.clear();
    g.linjiebiao.clear();
    g.dis2end.clear();
}

graph &graph::operator=(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    return *this;
}

graph &graph::operator=(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    g.path.clear();
    g.linjiebiao.clear();
    g.dis2end.clear();
    return *this;
}

