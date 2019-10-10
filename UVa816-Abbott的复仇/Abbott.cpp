//
// Created by xiaosong on 2019/10/10.
//

#include "Abbott.h"
#include <functional>
using namespace std;
extern map<char, function<void(int &, int &)>> moving_xy;
Abbott::Abbott(const string &s) {

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

}
