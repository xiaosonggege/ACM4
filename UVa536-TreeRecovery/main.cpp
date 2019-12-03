//
// Created by 宋云龙 on 2019/12/2.
//
#include "TreeRecovery.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;
int main(int argc, char *argv[]){
    const string &path = "/Users/songyunlong/CLionProjects/ACM4/UVa536-TreeRecovery/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    shared_ptr<string> temp_p = make_shared<string>();
    while (getline(ifstrm, *temp_p)){
        treerecovery tr(*temp_p);
        tr(cout);
    }
    ifstrm.close();
    return 0;
}

