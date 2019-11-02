//
// Created by xiaosong on 2019/11/2.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <memory>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;
int main(int argc, char *argv[]){
    const string &path = "/home/xiaosong/CLionProjects/ACM/UVa1572-Self-Assembly/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    string temp;
    while (getline(ifstrm, temp)){
        if (static_cast<int>(temp[0]) >= 0 && static_cast<int>(temp[0]) <= 9)
            continue;
        else{
            //读入解析单行数据的对象进行统计并输出结果

        }
    }
    ifstrm.close();
    vector<int> d(10, 1);
    return 0;
}

