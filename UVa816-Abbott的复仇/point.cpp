//
// Created by xiaosong on 2019/10/10.
//

#include "point.h"
#include <sstream>
using namespace std;
Point::Point(const string &s){
    istringstream istr(s);
    string come_go;
    while (istr >> come_go){
        if (come_go != "*"){
            this->come2go[come_go[0]] = vector<char>(come_go.begin()+1, come_go.end());
        }
    }

}

Point::~Point() {

}

