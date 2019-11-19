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
    vector<int> v = {1, 2, 3, 4};
    int a = *min_element(v.begin(), v.end());
    cout << a << endl;
    return 0;
}

