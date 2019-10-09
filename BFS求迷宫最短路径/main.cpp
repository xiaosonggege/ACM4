//
// Created by xiaosong on 2019/10/8.
//
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iterator>
#include "MigongBFS.h"
#include <memory>
using namespace std;
extern int len_row;
extern int len_col;
ofstream & datagenerate(const string &s, ofstream &out);
int main(int argc, char *argv[]){
    string path = "/home/xiaosong/桌面/migongbfs";
//    ofstream ofstrm;
//    datagenerate(path, ofstrm);
    shared_ptr<Migong_bfs> m = make_shared<Migong_bfs>(path);
    m->information(cout);
    m->BFS_find_min_path();
    m->show(cout);
    return 0;
}
ofstream & datagenerate(const string &s, ofstream &ofstrm){
    ofstrm.open(s, ios::app);
    ofstrm.close();
    return ofstrm;
}

