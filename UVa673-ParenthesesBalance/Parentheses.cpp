//
// Created by 宋云龙 on 2019/11/28.
//

#include "Parentheses.h"
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;
parentheses::parentheses(const string &zifuchuans): zifuchuan(zifuchuans) {}

parentheses::parentheses(const parentheses &p) {
    this->zifuchuan = p.zifuchuan;
    this->is_parented = p.is_parented;
}

parentheses::parentheses(parentheses &&p) {
    this->zifuchuan = p.zifuchuan;
    this->is_parented = p.is_parented;
    p.zifuchuan.clear();
    p.is_parented = 0;
}

parentheses &parentheses::operator=(const parentheses &p) {
    this->zifuchuan = p.zifuchuan;
    this->is_parented = p.is_parented;
    return *this;
}

parentheses &parentheses::operator=(parentheses &&p) {
    this->zifuchuan = p.zifuchuan;
    this->is_parented = p.is_parented;
    p.zifuchuan.clear();
    p.is_parented = 0;
    return *this;
}

ostream &parentheses::operator()(ostream &os) {
    //建立临时存储栈
    vector<char> stack1(this->zifuchuan.begin(), this->zifuchuan.end()), stack2;
    vector<char> choice_series = {'(', '[', '{'};
    vector<string> judge_series = {"()", "[]", "{}"};
    vector<char>::iterator iter = stack1.begin();
    int real_num = stack1.size();
    while (iter != stack1.end() || real_num){
        if (find(choice_series.begin(), choice_series.end(), *iter) != choice_series.end()){
            stack2.insert(stack2.begin(), *iter);
            iter = stack1.erase(iter);
        }
        else {
            string pinjie;
            if (stack1.empty()) {pinjie.push_back(stack2.front()), pinjie.push_back(' ');}
            else if (stack2.empty()) {pinjie.push_back(' '), pinjie.push_back(*iter);}
            else pinjie.push_back(stack2.front()), pinjie.push_back(*iter);
            if (find(judge_series.begin(), judge_series.end(), pinjie) == judge_series.end()) {
                this->is_parented = 0; break;
            }
            else {
                iter = stack1.erase(iter);
                stack2.erase(stack2.begin());
                real_num -= 2;
            }
        }
    }
    (this->is_parented == 1)? (os << "括号匹配!" << endl) : (os << "括号不匹配!" << endl);
    return os;
}

