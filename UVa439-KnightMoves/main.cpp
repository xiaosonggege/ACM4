//
// Created by 宋云龙 on 2019/12/5.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "knightmoves.h"
using namespace std;
int main(int argc, char *argv[]) {
    const string &path = "/Users/songyunlong/CLionProjects/ACM4/UVa439-KnightMoves/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    string temp;
    stringstream str_iter;
    str_iter.clear();
    while (getline(ifstrm, temp)){
        str_iter << temp;
        string pos1, pos2;
        str_iter >> pos1 >> pos2;
        KnightMoves k(pos1, pos2);
        k.BFS();
        k(cout);
        str_iter.clear();
    }
    ifstrm.close();
    return 0;
}
