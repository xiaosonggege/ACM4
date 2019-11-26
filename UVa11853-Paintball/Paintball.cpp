//
// Created by xiaosong on 2019/11/24.
//
#include "Paintball.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
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
    ifstrm.close();
    sort(this->x_real_value.begin(), this->x_real_value.end());
    vector<double>::iterator end_ = unique(this->x_real_value.begin(), this->x_real_value.end());
    this->x_real_value.erase(end_, this->x_real_value.end());
    sort(this->y_real_value.begin(), this->y_real_value.end());
    vector<double>::iterator end_2 = unique(y_real_value.begin(), y_real_value.end());
    this->y_real_value.erase(end_2, y_real_value.end());
    cout << "障碍物的坐标及范围为:" << endl;
    for (auto const &e : this->ball) cout << "(" << get<0>(e) << ", " << get<1>(e) << ")  " << "r= " << get<2>(e) << endl;
    //构造离散化坐标图
    this->map = vector<vector<double>>(x_real_value.size(), vector<double>(y_real_value.size()));
    for (unsigned int x = 0; x != this->x_real_value.size(); ++x){
        for (unsigned int y = 0; y != this->y_real_value.size(); ++y){
            pair<bool, double> tup = find_fun(*this, x_real_value[x], y_real_value[y]);
            if (tup.first) this->map[x][y] = tup.second;
            else this->map[x][y] = 0;
        }
    }
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
    string an1 = "存在通路", an2 = "不存在通路";
    if (this->is_bounded) os << an1 << endl;
    else os << an2 << endl;
    os << "起点坐标为: (" << this->start.first << ", " << start.second << ")" << endl;
    os << "终点坐标为: (" << this->end.first << ", " << end.second << ")" << endl;
    return os;
}
pair<bool, double> find_fun(const paintball &p, const unsigned int &x, const unsigned int &y){
    for (auto const &e : p.ball){
        if (get<0>(e) == x && get<1>(e) == y) { return make_pair(1, get<2>(e)); break; }
    }
    return make_pair(0, 0);
}
void paintball::DFS() {
    auto compare = [](const double &r)->bool{return r > 0;};
    vector<double> first_row = this->map[0];
    vector<double>::const_iterator iter_pos = find_if(first_row.cbegin(), first_row.cend(), compare);
    unsigned int first_row_nonezero = iter_pos - first_row.cbegin(); //首行非零元素位置
    //记录已遍历完成的位置坐标
    vector<pair<int, int>> record;
    DFS_s(*this, 0, first_row_nonezero, record, this->map.size());
}
void DFS_s(paintball &p, const int &x, const int &y, vector<pair<int, int>> &record, int max_depth){
    if (!p.is_bounded){
        for (int fx = -1; fx != 2 && p.is_bounded != 1; ++fx){
            for (int fy = -1; fy != 2 && p.is_bounded != 1; ++fy){
                if (x+fx >=0 && x+fx < p.map.size() && y+fy >=0 && y+fy < p.map[0].size()){
                    if (find(record.cbegin(), record.cend(), make_pair(x+fx, y+fy)) == record.cend()) {
                        if (x+fx == max_depth-1) p.is_bounded = 1;
                        record.push_back(make_pair(x+fx, y+fy));
                        DFS_s(p, x+fx, y+fy, record, max_depth);
                    }
                }
            }
        }
    }
}
void paintball::startandend_axis() {
    decltype(this->ball) ball_series_left, ball_series_right;
    //筛选
    for (auto const &e : this->ball){
        if (get<2>(e) >= abs(get<0>(e) - 0)) ball_series_left.push_back(e);
        if (get<2>(e) >= abs(1000 - get<0>(e))) ball_series_right.push_back(e);
    }
    vector<double> r_left, r_right;
    int flag = 0;
    for (auto const &e : ball_series_left) {
        if (get<1>(e)+get<2>(e) < 1000) {
            double y_up = get<1>(e) + sqrt(pow(get<2>(e), 2)-pow(get<0>(e), 2));
            r_left.push_back(y_up);
            ++flag;
        }
        else if (get<1>(e)-get<2>(e) > 0){
            double y_down = get<1>(e) - sqrt(pow(get<2>(e), 2)-pow(get<0>(e), 2));
            r_left.push_back(y_down);
        }
    }
    if (flag == ball_series_left.size()) r_left.push_back(1000);
    this->start = make_pair(0, *max_element(r_left.cbegin(), r_left.cend()));
    flag = 0;
    for (auto const &e : ball_series_right) {
        if (get<1>(e)+get<2>(e) < 1000) {
            double y_up = get<1>(e) + sqrt(pow(get<2>(e), 2)-pow(1000 - get<0>(e), 2));
            r_right.push_back(y_up);
            ++flag;
        }
        else if (get<1>(e)-get<2>(e) > 0){
            double y_down = get<1>(e) - sqrt(pow(get<2>(e), 2)-pow(1000 - get<0>(e), 2));
            r_right.push_back(y_down);
        }
    }
    if (flag == ball_series_right.size()) r_right.push_back(1000);
    this->end = make_pair(1000, *max_element(r_right.cbegin(), r_right.cend()));
}