//
// Created by xiaosong on 2019/11/7.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <memory>
#include <utility>
#include "class_file.h"
using namespace std;
int main(int argc, char *argv[]){
    const string &path = "/home/xiaosong/CLionProjects/ACM/UVa1599-IdealPath/file";
    shared_ptr<graph> g_ptr = make_shared<graph>(path);
    g_ptr->BFS_min_dict(cout);
    return 0;
}
