//
// Created by xiaosong on 2019/10/8.
//

#ifndef ACM3_CLION_MIGONGBFS_H
#define ACM3_CLION_MIGONGBFS_H
#include <vector>
#include <utility>
#include <iostream>
#include <string>
using namespace std;
class Migong_bfs{
private:
    vector<vector<char>> migong;
    vector<char> min_line;
    pair<int, int> start_point;
    pair<int, int> end_point;
public:
    Migong_bfs() = default;
    Migong_bfs(const string &);
    ~Migong_bfs();
    Migong_bfs(const Migong_bfs &);
    Migong_bfs(Migong_bfs &&);
    Migong_bfs & operator=(const Migong_bfs &);
    Migong_bfs & operator=(Migong_bfs &&);
    int BFS_find_min_path();
    ostream & show(ostream &) const;
};
#endif //ACM3_CLION_MIGONGBFS_H
