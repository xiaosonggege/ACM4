//
// Created by xiaosong on 2019/11/2.
//

#include "graph_building.h"
#include "fuzhu.h"
#include <algorithm>
#include <iomanip>
#include <set>
#include <utility>
using namespace std;
Graph::Graph(const string &datas): data(datas) {
    istringstream istr(this->data);
    string str_temp;
    vector<string> str_temp_;
    while (istr >> setw(2) >> str_temp) str_temp_.push_back(str_temp);
    //print
    for (auto const &e : str_temp_)  cout << e << " ";
    cout << endl;
    //生成data_
    vector<string> str_temp2_(str_temp_); //复制用于生成成员datas_
    auto duiying = [](const string &s)->string {
        if (s[1] == '+') return string(s, 0, 1)+"-";
        return string(s, 0, 1)+"+";
    };
    for (unsigned int i = 0; i != str_temp_.size(); i += 4){
        //正向判断
        if (str_temp_[i+2] != "00" && find(str_temp_.begin(), str_temp_.end(), duiying(str_temp_[i+2])) != str_temp_.end()){
            this->data_.push_back(make_pair(str_temp_[i], duiying(str_temp_[i+2])));
        }
        //反向判断
        if (str_temp_[i] != "00" && find(str_temp_.begin(), str_temp_.end(), duiying(str_temp_[i])) != str_temp_.end()){
            this->data_.push_back(make_pair(str_temp_[i+2], duiying(str_temp_[i])));
        }
        //正向判断
        if (str_temp_[i+3] != "00" && find(str_temp_.begin(), str_temp_.end(), duiying(str_temp_[i+3])) != str_temp_.end()){
            this->data_.push_back(make_pair(str_temp_[i+1], duiying(str_temp_[i+3])));
        }
        //反向判断
        if (str_temp_[i+1] != "00" && find(str_temp_.begin(), str_temp_.end(), duiying(str_temp_[i+1])) != str_temp_.end()){
            this->data_.push_back(make_pair(str_temp_[i+3], duiying(str_temp_[i+1])));
        }
    }
    //data_去重
    sort(this->data_.begin(), this->data_.end());
    this->data_.erase(unique(this->data_.begin(), this->data_.end()), this->data_.end());
    //print
    for (auto const &e : this->data_)
        cout << e.first << "->" << e.second << endl;
    //生成symbol_level
    sort(str_temp_.begin(), str_temp_.end());
    vector<string>::iterator iter_mid = unique(str_temp_.begin(), str_temp_.end());
    str_temp_.erase(iter_mid, str_temp_.end());
    //copy str_temp_
    decltype(str_temp_) str_temp3_(str_temp_);
    int len = str_temp_.size();
    int level = 0;
    while (str_temp_.size()){
        this->symbol_level[str_temp_.front()] = level;
        ++level;
        str_temp_.erase(str_temp_.begin());
    }
    //print
    for (auto const &e : this->symbol_level)
        cout << e.first << ": " << e.second << endl;
    //邻接表矩阵graph_matrix
    this->graph_matrix = vector<vector<int>>(len, vector<int>(len, 0));
//    cout << this->graph_matrix.size() << " " << this->graph_matrix[0].size() << endl;
    for (auto const &e : this->data_){
        unsigned int index1 = this->symbol_level[e.first], index2 = this->symbol_level[e.second];
        this->graph_matrix[index1][index2] = 1;
    }
    //print
    for (int i = 0; i != len; ++i){
        for (int j = 0; j != len; ++j)
            cout << this->graph_matrix[i][j];
        cout << endl;
    }
}
Graph::Graph(const Graph &g) {
    this->data = g.data;
    this->data_ = g.data_;
    this->is_bound = g.is_bound;
    this->graph_matrix = g.graph_matrix;
    this->symbol_level = g.symbol_level;
}

Graph::Graph(Graph &&g) {
    this->data = g.data;
    this->data_ = g.data_;
    this->is_bound = g.is_bound;
    this->graph_matrix = g.graph_matrix;
    this->symbol_level = g.symbol_level;
    g.data.clear();
    g.data_.clear();
    g.is_bound = false;
    g.graph_matrix.clear();
    g.symbol_level.clear();
}

Graph &Graph::operator=(const Graph &g) {
    this->data = g.data;
    this->data_ = g.data_;
    this->is_bound = g.is_bound;
    this->graph_matrix = g.graph_matrix;
    this->symbol_level = g.symbol_level;
    return *this;
}

Graph &Graph::operator=(Graph &&g) {
    this->data = g.data;
    this->data_ = g.data_;
    this->is_bound = g.is_bound;
    this->graph_matrix = g.graph_matrix;
    this->symbol_level = g.symbol_level;
    g.data.clear();
    g.data_.clear();
    g.is_bound = false;
    g.graph_matrix.clear();
    g.symbol_level.clear();
    return *this;
}

bool Graph::is_bounding() {
    Graph_friend gf;
    vector<int> v;
    vector<string> all_point;
    for (auto const &e : this->symbol_level) all_point.push_back(e.first);
    gf.fun(*this, v, all_point);
    return this->is_bound;
}

