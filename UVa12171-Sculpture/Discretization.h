//
// Created by xiaosong on 2019/10/23.
//

#ifndef ACM3_CLION_DISCRETIZATION_H
#define ACM3_CLION_DISCRETIZATION_H
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
class discretization{
public:
    vector<int> x_dis;
    vector<int> y_dis;
    vector<int> z_dis;
    tuple<vector<int>, vector<int>, vector<int>> operator()(const vector<vector<int>> &boxes){
        for (unsigned int i = 0; i != 3; ++i){//分别计算x，y，z轴的离散化
            vector<int> dis_point; //初始化离散化坐标中间量
            for (const auto &e : boxes){
                dis_point.push_back(e[i]);
                dis_point.push_back(e[i] + e[i+3]);//将数据中各个唯独中对应的起始点和终止点分别存储
            }
            //对dis_point向量中的所有数据进行排序，并且去除相同量
            sort(dis_point.begin(), dis_point.end());
            vector<int>::iterator iter_begin = unique(dis_point.begin(), dis_point.end());
            dis_point.erase(iter_begin, dis_point.end());
            switch(i){
                case 0: x_dis = dis_point; break;
                case 1: y_dis = dis_point; break;
                default: z_dis = dis_point;
            }
        }
        return tuple<vector<int>, vector<int>, vector<int>>(x_dis, y_dis, z_dis);
    }
};
#endif //ACM3_CLION_DISCRETIZATION_H
