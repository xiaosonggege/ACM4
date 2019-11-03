//
// Created by xiaosong on 2019/11/2.
//

#include "graph_building.h"
#include <algorithm>
#include <iomanip>
using namespace std;
Graph::Graph(const string &datas): data(datas) {
    istringstream istr(this->data);
    string str_temp;
    vector<string> str_temp_;
    while (istr >> setw(2) >> str_temp) str_temp_.push_back(str_temp);
    //生成data_
    vector<string> str_temp2_(str_temp_); //复制用于生成成员datas_
    try{
        auto iter = str_temp2_.begin();
        while (true){
            pair<string, string> ss = {*iter++, *iter++};
            this->data_.push_back(ss);
            if (iter == str_temp2_.end()) throw string("转移对统计完成!");
        }
    }
    catch (string &error) {cout << error;}
    //print
//    for (auto const &e : this->data_)
//        cout << e.first << "->" << e.second << endl;
    //生成symbol_level
    sort(str_temp_.begin(), str_temp_.end());
    vector<string>::iterator iter_mid = unique(str_temp_.begin(), str_temp_.end());
    str_temp_.erase(iter_mid, str_temp_.end());
    int level = 0;
    while (str_temp_.size()){
        this->symbol_level[str_temp_.front()] = level;
        ++level;
        str_temp_.erase(str_temp_.begin());
    }
    //print
//    for (auto const &e : this->symbol_level)
//        cout << e.first << ": " << e.second << endl;
    //邻接表矩阵graph_matrix


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

