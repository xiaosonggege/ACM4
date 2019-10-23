//
// Created by xiaosong on 2019/10/16.
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <initializer_list>
#include "Blocking_op.h"
#include "Sculpture.h"
using namespace std;
int main(int argc, char *argv[]){
    string path = "/home/xiaosong/CLionProjects/ACM/UVa12171-Sculpture/file1";
    shared_ptr<Sculpture> s = make_shared<Sculpture>(path);
    s->show(cout);
    s->print(cout);
    return 0;
}

