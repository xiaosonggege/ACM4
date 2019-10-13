//
// Created by xiaosong on 2019/10/13.
//
#include "Trees.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;
using Graph = vector<vector<char>>;
int main(int argc, char *argv[]){
    shared_ptr<string> path = make_shared<string>("/home/xiaosong/CLionProjects/ACM/UVa10562-UndrawTheTree/file");
    ifstream ifstrm;
    ifstrm.open(*path, ios::in);
    string s;
    istringstream istr(s);
    getline(ifstrm, s);
    int num;
    istr >> num;
    cout << "两个多叉树遍历结果如下:" << endl;
    Graph g;
    while (getline(ifstrm, s)) {
        istringstream istr2(s);
        istr2 >> noskipws;
        if (*s.begin() != '#') {
            istream_iterator<char> in_iter(istr2), eof;
            g.push_back(vector<char>(in_iter, eof));
        }
        else {
            UndrawTheTrees u(g);
            //对当前多叉树进行遍历
            u(cout);
//            u.reading();
//            u.show(cout);
            g.clear(); //准备读取下一颗多叉树
        }
    }
    ifstrm.close();
    return 0;
}

