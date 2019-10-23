//
// Created by xiaosong on 2019/10/23.
//

#ifndef ACM3_CLION_BLOCKING_OP_H
#define ACM3_CLION_BLOCKING_OP_H
#include <vector>
#include <string>
using namespace std;
class Blocking{
    vector<int> x_dis; //离散化后的x轴坐标
    vector<int> y_dis; //离散化后的y轴坐标
    vector<int> z_dis; //离散化后的z轴坐标
    Blocking() = default;
    Blocking(const vector<int> &x_disp, const vector<int> &y_disp, const vector<int> &z_disp):
    x_dis(x_disp), y_dis(y_disp), z_dis(z_disp){}
    vector<vector<int>>  operator()(const vector<vector<int>> &boxes){//将箱子向量中的所有数据均按照坐标的逐个长度进行划分，得到小块
        return vector<vector<int>>(); //改
    }
};
#endif //ACM3_CLION_BLOCKING_OP_H
