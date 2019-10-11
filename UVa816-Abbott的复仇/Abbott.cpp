//
// Created by xiaosong on 2019/10/10.
//

#include "Abbott.h"
#include <functional>
#include <memory>
using namespace std;
using pairr = pair<pair<int, int>, vector<pair<int, int>>>;
using tup_map = vector<pair<char, pairr>>;
extern map<char, function<void(char, int , int )>> moving_xy;
void BFS(const int &tar_x, const int &tar_y, tup_map &stack, const vector<vector<Point>> &migong, int &x, int &y, const char &dir);
Abbott::Abbott(const pair<int, int> &start, const pair<int, int> &end, const char &direction,
               const vector<vector<Point>> &migongs):
start_position(start), end_position(end), start_direction(direction), migong(migongs){

}

Abbott::Abbott(const Abbott &a) {
    this->migong = a.migong;
    this->start_position = a.start_position;
    this->end_position = a.end_position;
    this->start_direction = a.start_direction;
    this->min_line = a.min_line;
}

Abbott::Abbott(Abbott &&a) {
    this->migong = a.migong;
    this->start_position = a.start_position;
    this->end_position = a.end_position;
    this->start_direction = a.start_direction;
    this->min_line = a.min_line;
    a.migong.clear();
    a.end_position = {};
    a.start_position = {};
    a.start_direction = ' ';
    a.min_line.clear();
}

Abbott &Abbott::operator=(const Abbott &a) {
    this->migong = a.migong;
    this->start_position = a.start_position;
    this->end_position = a.end_position;
    this->start_direction = a.start_direction;
    this->min_line = a.min_line;
    return *this;
}

Abbott &Abbott::operator=(Abbott &&a) {
    this->migong = a.migong;
    this->start_position = a.start_position;
    this->end_position = a.end_position;
    this->start_direction = a.start_direction;
    this->min_line = a.min_line;
    a.migong.clear();
    a.end_position = {};
    a.start_position = {};
    a.start_direction = ' ';
    a.min_line.clear();
    return *this;
}

Abbott::~Abbott() {

}

ostream &Abbott::show(ostream &os) {
    os << "迷宫大小为:" << "(" << migong.size() << ", " << migong[0].size() << ")" << endl;
    os << "Abbott元素信息为:" << endl;
    os << "start: " << "(" << start_position.first << ", " << start_position.second << ")" << endl;
    os << "end:" << "(" << end_position.first << ", " << end_position.second << ")" << endl;
    os << "starting direction: " << start_direction << endl;
    return os;
}

void Abbott::moving_BFS() {
    //定义临时队列,队列中每个节点记录节点坐标和该节点从根节点起的遍历节点序列坐标
    shared_ptr<tup_map> stack = make_shared<tup_map>();
    pairr tup = {this->start_position, {}};
    stack->push_back({'N', tup});
    //递归遍历
    BFS(this->end_position.first, this->end_position.second, *stack, this->migong,
            this->start_position.first, this->start_position.second, this->start_direction);
    this->min_line = (stack->cbegin())->second.second;
}

ostream &Abbott::print_line(ostream &os) const {
    for (const auto &e : this->min_line){
        os << "(" << e.first+1 << ", " << e.second+1 << ") ";
    }
    os << endl;
    return os;
}

