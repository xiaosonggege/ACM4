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
#include <iomanip>
#include <iterator>
#include <stdexcept>
#include "graph_building.h"
#include "fuzhu.h"
using namespace std;
int main(int argc, char *argv[]){
    for (char **p = argv+1; p != argv+4; ++p) cout << *p << " ";
    cout << endl;
    const string &path = "/home/xiaosong/CLionProjects/ACM/UVa1572-Self-Assembly/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    string temp;
    while (getline(ifstrm, temp)){
        if (temp.size() <=2)
            continue;
        else{
            Graph g(temp);
            switch (g.is_bounding()){
                case 1: cout << "bounded" << endl;
                case 2: cout << "unbounded" << endl;
            }
        }
    }
    ifstrm.close();
    return 0;
}

