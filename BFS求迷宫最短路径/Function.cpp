//
// Created by xiaosong on 2019/10/9.
//
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using tup_map = map<pair<int, int>, vector<char>>;
extern int len_row;
extern int len_col;
extern vector<vector<char>> vv;
extern int x_end;
extern int y_end;
bool find_point(const vector<pair<pair<int, int>, vector<char>>> &m, const int &x, const int &y, const vector<vector<char>> &migong){
    for (auto iter=m.cbegin(); iter!=m.cend(); ++iter){
        if (iter->first.first == x && iter->first.second == y) return 1;
        else if (find(iter->second.cbegin(), iter->second.cend(), migong[x][y]) != iter->second.cend()) return 1;
    }
    return 0;
}
//递归广度优先搜索矩阵
int bfs(vector<pair<pair<int, int>, vector<char>>> &m, const int &x, const int &y){
    //如果位置未遍历过
    if (x == x_end && y == y_end) {
        return 0;
    }
    else if (!find_point(m, x, y, vv)){
        if (x-1 >= 0 && vv[x-1][y] != '*') {
            m.push_back({{x-1, y}, vector<char>(m.begin()->second.begin(), m.begin()->second.end())});
            (m.end()-1)->second.push_back(vv[x][y]);
        }
        if (x+1 <= len_col && vv[x+1][y] != '*') {
            m.push_back({{x+1, y}, vector<char>(m.begin()->second.begin(), m.begin()->second.end())});
            (m.end()-1)->second.push_back(vv[x][y]);
        }
        if (y-1 >= 0 && vv[x][y-1] != '*') {
            m.push_back({{x, y-1}, vector<char>(m.begin()->second.begin(), m.begin()->second.end())});
            (m.end()-1)->second.push_back(vv[x][y]);
        }
        if (y+1 <= len_row && vv[x][y+1] != '*') {
            m.push_back({{x, y+1}, vector<char>(m.begin()->second.begin(), m.begin()->second.end())});
            (m.end()-1)->second.push_back(vv[x][y]);
        }
        //将栈内首元素出栈
        m.erase(m.begin());
        bfs(m, m.begin()->first.first, m.begin()->first.second);
    }
    return 0;
}
