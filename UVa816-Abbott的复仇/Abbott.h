//
// Created by xiaosong on 2019/10/10.
//

#ifndef ACM3_CLION_ABBOTT_H
#define ACM3_CLION_ABBOTT_H
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "point.h"
using namespace std;
class Abbott{
private:
    vector<vector<Point>> migong; //二维迷宫
    pair<int, int> start_position; //起点
    pair<int, int> end_position; //终点
    char start_direction; //出发方向
    vector<pair<int, int>> min_line; //最短路径
public:
    Abbott() = default;
    Abbott(const pair<int, int> &, const pair<int, int> &, const char &, const vector<vector<Point>> &);
    Abbott(const Abbott &);
    Abbott(Abbott &&);
    Abbott & operator=(const Abbott &) ;
    Abbott & operator=(Abbott &&);
    ~Abbott();
    ostream & show(ostream &); //显示所有元素属性信息
    void moving_BFS(); //BFS算法搜索最短路径
    ostream & print_line(ostream &os) const;
};
#endif //ACM3_CLION_ABBOTT_H
