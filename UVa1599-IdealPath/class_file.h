//
// Created by xiaosong on 2019/11/7.
//

#ifndef ACM3_CLION_CLASS_FILE_H
#define ACM3_CLION_CLASS_FILE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <memory>
using namespace std;
struct node{
    int color_level;
    int dis2end;
    shared_ptr<node> next;
};
class graph{
private:
    string path;
    vector<node> linjiebiao;
public:
    graph() = default;
    graph(const string &);
    graph(const graph &);
    graph(graph &&);
    graph & operator=(const graph &);
    graph & operator=(graph &&);

};
#endif //ACM3_CLION_CLASS_FILE_H
