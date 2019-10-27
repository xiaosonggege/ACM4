//
// Created by xiaosong on 2019/10/27.
//
#include "Blocking_op.h"
using namespace std;

Blocking::Blocking(initializer_list<vector<int>> xyz) {
    auto iter = xyz.begin();
    this->x_dis = *iter++;
    this->y_dis = *iter++;
    this->z_dis = *iter;
}

vector<vector<int>> Blocking::operator()(const vector<vector<int>> &boxes) {
    //将箱子向量中的所有数据均按照坐标的逐个长度进行划分，得到小块
    //返回列表
    void statistic(vector<vector<int>> &, const vector<int> &, const vector<int> &, const vector<int> &);
    vector<vector<int>> left_up_points;
    auto fun = [](unsigned int max_limit, vector<int> &per_axis, const vector<int> &dis_zuobiao)->void {
        for (unsigned i = 0; i != dis_zuobiao.size(); ++i)
            if (dis_zuobiao[i] <= max_limit) per_axis.push_back(i);
    };
    for (const auto &e : boxes){
        //存储临时三轴相对坐标列表
        vector<vector<int>> zuobiao_temp;
        vector<int> zuobiao_per_axis;
        for (unsigned int i = 3; i != 6; ++i) {
            switch(i){
                case 3: fun(e[i]+e[0], zuobiao_per_axis, this->x_dis); break;
                case 4: fun(e[i]+e[0], zuobiao_per_axis, this->y_dis); break;
                default: fun(e[i]+e[0], zuobiao_per_axis, this->z_dis);
            }
            zuobiao_temp.push_back(zuobiao_per_axis); //存入三轴离散相对坐标点
            zuobiao_per_axis.clear();
        }
        statistic(left_up_points, zuobiao_temp[0], zuobiao_temp[1], zuobiao_temp[2]);
    }
    /////检查生成相对坐标点的正确性/////////
    for (const auto &e : left_up_points){
        cout << "(";
        for (const auto &e2 : e){
            cout << e2 << " ";
        }
        cout << ")" << endl;
    }
    return left_up_points;
}

ostream &Blocking::show(ostream &os) {
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

///////////////统计生成左上角坐标点方法////////////////////
void statistic(vector<vector<int>> &left_up_points, const vector<int> &dis_xaxis,
        const vector<int> &dis_yaxis, const vector<int> &dis_zaxis){
    vector<int> x_prepare_axis(dis_xaxis.begin(), dis_xaxis.end()-1),
    y_prepare_axis(dis_yaxis.begin()+1, dis_yaxis.end()),
    z_prepare_axis(dis_zaxis.begin()+1, dis_zaxis.end());
    for (const auto &x : x_prepare_axis){
        for (const auto &y : y_prepare_axis){
            for (const auto &z : z_prepare_axis)
                left_up_points.push_back({x, y, z});
        }
    }
}
