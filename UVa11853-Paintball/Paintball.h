//
// Created by xiaosong on 2019/11/24.
//

#ifndef ACM3_CLION_PAINTBALL_H
#define ACM3_CLION_PAINTBALL_H
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
class paintball{
private:
    const string path = " "; //文件路径
    vector<tuple<double, double, double>> ball; //障碍物坐标和半径值序列
    bool is_bounded = 0; //标记是否存在通路
    pair<double, double> start; //起点坐标
    pair<double, double> end; //终点坐标
    vector<double> x_real_value; //离散化后的横坐标真实值
    vector<double> y_real_value; //离散化后的纵坐标真实值
    //离散化后的地图
    vector<vector<double>> map = vector<vector<double>>(x_real_value.size(), vector<double>(y_real_value.size()));
public:
    paintball() = default;
    virtual ~paintball(){};
    paintball(const string &);
    paintball(const paintball &);
    paintball(paintball &&);
    paintball & operator=(const paintball &);
    paintball & operator=(paintball &&);
    ostream & operator()(ostream &); //输出类中所有数据信息
};
#endif //ACM3_CLION_PAINTBALL_H
