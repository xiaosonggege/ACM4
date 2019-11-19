//
// Created by xiaosong on 2019/11/9.
//
#include <memory>
#include <utility>
#include <fstream>
#include <sstream>
#include <iterator>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;
int main(int argc, char *argv[]){
    auto a = make_tuple(1, vector<int>({1, 2}));
    get<0>(a) = 2;
    get<1>(a).push_back(3);
    cout << get<0>(a) << " " << get<1>(a)[0] << get<1>(a)[1] << get<1>(a)[2] << endl;
    return 0;
}

