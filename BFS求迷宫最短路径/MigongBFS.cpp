//
// Created by xiaosong on 2019/10/8.
//

#include "MigongBFS.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
using namespace std;
int bfs(vector<pair<pair<int, int>, vector<char>>> &m, const int &x, const int &y);
int len_row = 0;
int len_col = 0;
vector<vector<char>> vv;
int x_end = 0;
int y_end = 0;
Migong_bfs::Migong_bfs(const string &s) {
    ifstream ifstrm;
    try{
        ifstrm.open(s, ios::in);
        string warn = "文件不存在!";
        if (!ifstrm) throw warn;
    }
    catch(const string &warning){
        cout << warning << endl;
    }
    shared_ptr<string> s_temp = make_shared<string>();
    while (getline(ifstrm, *s_temp)){
        istringstream istr(*s_temp);
        if (s_temp->size() == 7) istr >> this->start_point.first >> this->start_point.second \
        >> this->end_point.first >> this->end_point.second;
        else{
            istream_iterator<char> in_iter(istr), eof;
            shared_ptr<vector<char>> v_row = make_shared<vector<char>>(in_iter, eof);
            this->migong.push_back(*v_row);
        }
    }
    ifstrm.close();
    len_row = this->migong.size()-1, len_col = this->migong[0].size()-1;
    vv = this->migong;
    x_end = this->end_point.first;
    y_end = this->end_point.second;
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
    using tup_map = vector<pair<pair<int, int>, vector<char>>>;
    //定义临时使用栈
    shared_ptr<tup_map> stack = make_shared<tup_map>();
    pair<pair<int, int>, vector<char>> tup = {{this->start_point.first, this->start_point.second}, {}};
    stack->push_back(tup);
    bfs(*stack, this->start_point.first, this->start_point.second);
    this->min_line = (stack->cbegin())->second;
    return 0;
}

ostream &Migong_bfs::show(ostream &os) const{
    os << "从起点到终点的最短路径为: " << endl;
    for (vector<char>::const_iterator iter=this->min_line.cbegin(); iter != this->min_line.cend(); ++iter)
        os << *iter << " ";
    os << endl;
    return os;
}

ostream &Migong_bfs::information(ostream &os) const {
    os << "元素信息为:" << endl;
    os << "起始位置: (" << this->start_point.first << ", " << this->start_point.second << ")" << endl;
    os << "终止位置: (" << this->end_point.first << ", " << this->end_point.second << ")" << endl;
    os << "迷宫信息: " << endl;
    for (int i=0; i != this->migong.size(); ++i){
        for (int j=0; j != this->migong[0].size(); ++j)
            os << this->migong[i][j] << " ";
        os << endl;
    }
    return os;
}

