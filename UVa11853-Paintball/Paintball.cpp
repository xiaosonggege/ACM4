//
// Created by xiaosong on 2019/11/24.
//
#include "Paintball.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
paintball::paintball(const string &paths): path(paths){
    ifstream ifstrm;
    ifstrm.open(this->path, ios::in);
    try{
        if (!ifstrm) throw string("文件打开失败!");
        string temp;
        getline(ifstrm, temp);
        istringstream istr(temp);
        int num;
        istr >> num;
        cout << "障碍物个数为: " << num;
        while (getline(ifstrm, temp)){
            istringstream istr2(temp);
            double x, y, r;
            istr2 >> x >> y >> r;
            this->ball.push_back(make_tuple(x, y, r));
            this->x_real_value.push_back(x);
            this->y_real_value.push_back(y);
        }
    }
    catch (const string &error){cerr << error;}
    sort(this->x_real_value.begin(), this->x_real_value.end());
    sort(this->y_real_value.begin(), this->y_real_value.end());
    cout << "障碍物的坐标及范围为:" << endl;
    for (auto const &e : this->ball) cout << "(" << get<0>(e) << ", " << get<1>(e) << ")  " << "r= " << get<2>(e) << endl;
    ifstrm.close();
}
paintball::paintball(const paintball &p) {
    this->ball = p.ball;
    this->is_bounded = p.is_bounded;
    this->start = p.start;
    this->end = p.end;
    this->x_real_value = p.x_real_value;
    this->y_real_value = p.y_real_value;
    this->map = p.map;
}
paintball::paintball(paintball &&p) {
    this->ball = p.ball;
    this->is_bounded = p.is_bounded;
    this->start = p.start;
    this->end = p.end;
    this->x_real_value = p.x_real_value;
    this->y_real_value = p.y_real_value;
    this->map = p.map;
    p.ball.clear();
    p.is_bounded = 0;
    p.start = {0, 0};
    p.end = {0, 0};
    p.x_real_value.clear();
    p.y_real_value.clear();
    p.map.clear();
}
paintball & paintball::operator=(const paintball &p) {
    this->ball = p.ball;
    this->is_bounded = p.is_bounded;
    this->start = p.start;
    this->end = p.end;
    this->x_real_value = p.x_real_value;
    this->y_real_value = p.y_real_value;
    this->map = p.map;
    return *this;
}
paintball& paintball::operator=(paintball &&p) {
    this->ball = p.ball;
    this->is_bounded = p.is_bounded;
    this->start = p.start;
    this->end = p.end;
    this->x_real_value = p.x_real_value;
    this->y_real_value = p.y_real_value;
    this->map = p.map;
    p.ball.clear();
    p.is_bounded = 0;
    p.start = {0, 0};
    p.end = {0, 0};
    p.x_real_value.clear();
    p.y_real_value.clear();
    p.map.clear();
    return *this;
}
ostream & paintball::operator()(ostream &os) {
    string an1 = "不存在通路", an2 = "存在通路";
    if (this->is_bounded) os << an1 << endl;
    else os << an2 << endl;
    os << "起点坐标为: (" << this->start.first << ", " << start.second << ")" << endl;
    os << "终点坐标为: (" << this->end.first << ", " << end.second << ")" << endl;
    return os;
}