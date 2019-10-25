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
    Blocking(initializer_list<vector<int>> xyz) {
        auto iter = xyz.begin();
        this->x_dis = *iter++;
        this->y_dis = *iter++;
        this->z_dis = *iter;
    }
    vector<vector<int>>  operator()(const vector<vector<int>> &boxes){//将箱子向量中的所有数据均按照坐标的逐个长度进行划分，得到小块
        return vector<vector<int>>(); //改
    }
    ostream & show(ostream &os){
        os << "x_dis:" << endl;
        for (const auto &e : this->x_dis) os << e << " ";
        os << endl;
        os << "y_dis:" << endl;
        for (const auto &e : this->y_dis) os << e << " ";
        os << endl;
        os << "z_dis:" << endl;
        for (const auto &e : this->z_dis) os << e << " ";
        os << endl;
        return os;
    }
};
#endif //ACM3_CLION_BLOCKING_OP_H
