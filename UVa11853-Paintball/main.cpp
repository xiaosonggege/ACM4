//
// Created by xiaosong on 2019/11/24.
//
#include <iostream>
#include <string>
#include <vector>
#include "Paintball.h"
#include <memory>
using namespace std;
int main(int argc, char *argv[]){
    cout << argv[1] << endl;
    const string &path = "/home/xiaosong/CLionProjects/ACM/UVa11853-Paintball/file";
    paintball p1(path);
    p1.DFS();
    p1.startandend_axis();
    p1(cout);
    return 0;
}

