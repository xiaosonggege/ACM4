//
// Created by xiaosong on 2019/10/23.
//

#ifndef ACM3_CLION_SCULPTURE_H
#define ACM3_CLION_SCULPTURE_H
#include "Blocking_op.h"
#include "Discretization.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
using namespace std;
class discretization;
class Sculpture{
    friend class discretization;
private:
    string file_path;
    vector<vector<int>> boxes; //存储所有盒子的容器
    int V = 0, S = 0; //定义容器中这些盒子组成的立方体的体积和表面积
    static int count; //立方体个数记录
public:
    Sculpture() = default;
    Sculpture(const string &);
    Sculpture(const Sculpture &);
    Sculpture(Sculpture &&) noexcept ;
    ~Sculpture();
    Sculpture & operator=(const Sculpture &);
    Sculpture & operator=(Sculpture &&) noexcept ;
    static ostream & show(ostream &); //输出文件中需要统计的立方体个数
    ostream & print(ostream &); //输出单个立方体的各项信息
    void V_calc();
};
#endif //ACM3_CLION_SCULPTURE_H
