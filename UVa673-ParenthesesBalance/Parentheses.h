//
// Created by 宋云龙 on 2019/11/28.
//

#ifndef ACM3_CLION_PARENTHESES_H
#define ACM3_CLION_PARENTHESES_H
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class parentheses{
private:
    string zifuchuan;
    bool is_parented = 1;
public:
    parentheses() = default;
    virtual ~parentheses() = default;
    parentheses(const string &);
    parentheses(const parentheses &);
    parentheses(parentheses &&);
    parentheses & operator=(const parentheses &);
    parentheses & operator=(parentheses &&);
    ostream & operator()(ostream &);
};
#endif //ACM3_CLION_PARENTHESES_H
