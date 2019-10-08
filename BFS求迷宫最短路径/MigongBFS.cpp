//
// Created by xiaosong on 2019/10/8.
//

#include "MigongBFS.h"
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;
Migong_bfs::Migong_bfs(const string &s) {
    ifstream ifstrm;
    ifstrm.open(s, ios::in);
    shared_ptr<string> s_temp = make_shared<string>();
    while (getline(ifstrm, *s_temp)){
        istringstream istr(*s_temp);
        shared_ptr<vector<char>> v_row = make_shared<vector<char>>();
        char point;
        istr >> point;
        //文件每行字符之间有空格， 行末尾也有空格
        for (int i = 0; i != static_cast<int>(s_temp->size()/2); ++i) v_row->push_back(point);
        this->migong.push_back(*v_row);
        if (s_temp->size() == 8) istr >> this->start_point.first >> this->start_point.second \
        >> this->end_point.first >> this->end_point.second;
    }

    ifstrm.close();
}

Migong_bfs::~Migong_bfs() {

}

Migong_bfs::Migong_bfs(const Migong_bfs &m) {
    this->start_point = m.start_point;
    this->end_point = m.end_point;
    this->migong = m.migong;
    this->min_line = m.min_line;
}

Migong_bfs::Migong_bfs(Migong_bfs &&m) {
    this->start_point = m.start_point;
    this->end_point = m.end_point;
    this->migong = m.migong;
    this->min_line = m.min_line;
    m.start_point = {0, 0};
    m.end_point = {0, 0};
    m.migong.clear();
    m.min_line.clear();
}

Migong_bfs &Migong_bfs::operator=(const Migong_bfs &m) {
    this->start_point = m.start_point;
    this->end_point = m.end_point;
    this->migong = m.migong;
    this->min_line = m.min_line;
    return *this;
}

Migong_bfs &Migong_bfs::operator=(Migong_bfs &&m) {
    this->start_point = m.start_point;
    this->end_point = m.end_point;
    this->migong = m.migong;
    this->min_line = m.min_line;
    m.start_point = {0, 0};
    m.end_point = {0, 0};
    m.migong.clear();
    m.min_line.clear();
    return *this;
}

int Migong_bfs::BFS_find_min_path() {
    return 0;
}

ostream &Migong_bfs::show(ostream &os) const{
    os << "从起点到终点的最短路径为: " << endl;
    for (vector<char>::const_iterator iter=this->min_line.cbegin(); iter != this->min_line.cend(); ++iter)
        os << *iter << " ";
    os << endl;
    return os;
}

