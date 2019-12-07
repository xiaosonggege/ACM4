//
// Created by 宋云龙 on 2019/12/2.
//
#include "TreeRecovery.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>
using namespace std;
int main(int argc, char *argv[]){
    const string &path = "/Users/songyunlong/CLionProjects/ACM4/UVa536-TreeRecovery/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    shared_ptr<string> temp_p = make_shared<string>(), s1 = make_shared<string>(), s2 = make_shared<string>();
    stringstream str;
    str.clear();
    while (getline(ifstrm, *temp_p)){
        str << *temp_p;
        str >> *s1 >> *s2;
        treerecovery tr(*s1, *s2);
        tr.build(*s2);
        tr(cout);
        str.clear();
    }
    ifstrm.close();
//    string s = "songyunlong", ss = "yun";
//    int i = s.find_first_of(ss);
//    cout << i << endl;
    return 0;
}

