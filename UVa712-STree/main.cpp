//
// Created by 宋云龙 on 2019/11/29.
//
#include "stree.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;
int main(int argc, char *argv[]){
    cout << argv[1] << endl;
    const string path = "/Users/songyunlong/CLionProjects/ACM4/UVa712-STree/file";
    patrolli p(3, "00000111", vector<string>({"000", "010", "111", "110"})),
            p2(3, "00010011", vector<string>({"000", "010", "111", "110"}));
//    p(cout);
    p2.go();
    p2(cout);

    return 0;
}
