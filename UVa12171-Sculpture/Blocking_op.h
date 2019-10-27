//
// Created by xiaosong on 2019/10/23.
//

#ifndef ACM3_CLION_BLOCKING_OP_H
#define ACM3_CLION_BLOCKING_OP_H
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
using namespace std;
class Blocking{
public:
    vector<int> x_dis; //离散化后的x轴坐标
    vector<int> y_dis; //离散化后的y轴坐标
    vector<int> z_dis; //离散化后的z轴坐标
    Blocking() = default;
    Blocking(initializer_list<vector<int>> xyz);
    vector<vector<int>>  operator()(const vector<vector<int>> &boxes);
    ostream & show(ostream &os);
};
#endif //ACM3_CLION_BLOCKING_OP_H
