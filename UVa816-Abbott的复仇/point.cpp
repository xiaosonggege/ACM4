//
// Created by xiaosong on 2019/10/10.
//

#include "point.h"
#include <sstream>
using namespace std;
Point::Point(const string &s){ //读入一行数据
    istringstream istr(s);
    string come_go;
    int x, y;
    istr >> x >> y;
    this->zuobiao = {x-1, y-1};
    while (istr >> come_go){
        if (come_go != "*"){
            this->come2go[come_go[0]] = vector<char>(come_go.begin()+1, come_go.end());
        }
    }

}

Point::~Point() {

}

