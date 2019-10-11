//
// Created by xiaosong on 2019/10/10.
//
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <memory>
#include "Abbott.h"
using namespace std;
map<char, function<pair<int, int>(char, int, int)>> moving_xy = {
        {'F', [](char dir, int x, int y)->pair<int, int> {
            if (dir == 'N') return {--x, y};
            else if (dir == 'S') return {++x, y};
            else if (dir == 'W') return {x, --y};
            else return {x, ++y};
        }},
        {'L', [](char dir, int x, int y)->pair<int, int> {
            if (dir == 'N') return {x, --y};
            else if (dir == 'S') return {x, ++y};
            else if (dir == 'W') return {++x, y};
            else return {--x, y};
        }},
        {'R', [](char dir, int x, int y)->pair<int, int> {
            if (dir == 'N') return {x, ++y};
            else if (dir == 'S') return {x, --y};
            else if (dir == 'W') return {--x, y};
            else return {++x, y};
        }}
};
map<string, function<char()>> nextdir = {
        {"NF", []()->char {return 'N';}},
        {"NL", []()->char {return 'W';}},
        {"NR", []()->char {return 'E';}},
        {"SF", []()->char {return 'S';}},
        {"SL", []()->char {return 'E';}},
        {"SR", []()->char {return 'W';}},
        {"WF", []()->char {return 'W';}},
        {"WL", []()->char {return 'S';}},
        {"WR", []()->char {return 'N';}},
        {"EF", []()->char {return 'E';}},
        {"EL", []()->char {return 'N';}},
        {"ER", []()->char {return 'S';}},
};
int main(int argc, char *argv[]){
//    cout << argv[1] << endl;
    const string &path = "/home/xiaosong/CLionProjects/ACM/UVa816-Abbott的复仇/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    string s;
    getline(ifstrm, s);
    istringstream istr(s);
    pair<int, int> pairr1, pairr2;
    char c;
    istr >> pairr1.first >> pairr1.second >> c >> pairr2.first >> pairr2.second;
    pairr1.first -= 1, pairr1.second -= 1, pairr2.first -= 1, pairr2.second -= 1;
    vector<Point> m_sub(3, Point());
    vector<vector<Point>> m(3, m_sub); //初始化迷宫
    while (getline(ifstrm, s)){
        Point p(s);
        m[p.zuobiao.first][p.zuobiao.second] = p;
    }
    ifstrm.close();
    //写入起始点和终点坐标
    m[pairr1.first][pairr1.second].zuobiao = pairr1;
    m[pairr1.first][pairr1.second].come2go = {{'N', {'F'}}};
    m[pairr2.first][pairr2.second].zuobiao = pairr2;
    m[pairr1.first][pairr1.second+1].zuobiao = {2, 1};
    shared_ptr<Abbott> ab = make_shared<Abbott>(pairr1, pairr2, c, m);
    ab->show(cout);
    ab->moving_BFS();
    ab->print_line(cout);
    return 0;
}
using pairr = pair<pair<int, int>, vector<pair<int, int>>>;
using tup_map = vector<pair<char, pairr>>;
void BFS(const int &tar_x, const int &tar_y, tup_map &stack, const vector<vector<Point>> &migong, int &x, int &y, const char &dir){
    if (x == tar_x && y == tar_y) stack.begin()->second.second.push_back({x, y});
    else if (!migong[x][y].come2go.empty()){
        Point p = migong[x][y];
        //可选择的动作列表
        vector<char> action_choice = p.come2go[dir];
        for (const auto &e : action_choice){
            pair<int, int> pos = moving_xy[e](dir, x, y);
            string dir_dir;
            dir_dir.push_back(dir);
            dir_dir.push_back(e);
            stack.push_back({nextdir[dir_dir](), {pos, stack.cbegin()->second.second}});
            (stack.end()-1)->second.second.push_back({x, y});
        }
        //删除队列中首元素
        stack.erase(stack.begin());
        //递归遍历
        BFS(tar_x, tar_y, stack, migong, stack.begin()->second.first.first, stack.begin()->second.first.second,
                stack.begin()->first);
    }
}
