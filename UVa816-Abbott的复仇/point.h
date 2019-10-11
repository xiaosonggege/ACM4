//
// Created by xiaosong on 2019/10/10.
//

#ifndef ACM3_CLION_POINT_H
#define ACM3_CLION_POINT_H
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;
class Point{
public:
    //记录进入节点的朝向到可移动方向的映射信息
    pair<int, int> zuobiao;
    map<char, vector<char>> come2go;
    Point() = default;
    Point(const string &s);
    ~Point();
};


#endif //ACM3_CLION_POINT_H
