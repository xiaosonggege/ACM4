//
// Created by 宋云龙 on 2019/11/29.
//
#include "stree.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
    const string path = "/Users/songyunlong/CLionProjects/ACM4/UVa712-STree/file";
    patrolli p(3, "00000111", vector<string>({"000", "010", "111", "110"}));
    p(cout);
    return 0;
}
