//
// Created by xiaosong on 2019/10/10.
//

#ifndef ACM3_CLION_POINT_H
#define ACM3_CLION_POINT_H
#include <string>
#include <map>
#include <vector>
using namespace std;
class Point{
public:
    //记录节点可移动方向信息
    map<char, vector<char>> come2go;
    Point() = default;
    Point(const string &s);
    ~Point();
};


#endif //ACM3_CLION_POINT_H
