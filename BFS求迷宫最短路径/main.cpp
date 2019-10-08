//
// Created by xiaosong on 2019/10/8.
//
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iterator>
#include "MigongBFS.h"
using namespace std;
ofstream & datagenerate(const string &s, ofstream &out);
int main(int argc, char *argv[]){
    string path = "/home/xiaosong/桌面/migongbfs";
    ofstream ofstrm;
    datagenerate(path, ofstrm);
    return 0;
}
ofstream & datagenerate(const string &s, ofstream &ofstrm){
    ofstrm.open(s, ios::app);
    ofstrm << '0' << ' ' << '1' << ' ' << '*' << ' ' << '2' << ' ' << '3' << ' '\
    << '\n' << '4' << ' ' << '5';
    ofstrm.close();
    return ofstrm;
}

