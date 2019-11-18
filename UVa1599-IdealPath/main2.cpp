//
// Created by xiaosong on 2019/11/9.
//
#include <memory>
#include <utility>
#include <fstream>
#include <sstream>
#include <iterator>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void find_weizhi(string &str, int &xishu_weizhi){
    string::iterator variable = find_if(str.begin(), str.end(),
            [](const char &c)->bool {if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;return 0;});
    if (variable == str.end()) xishu_weizhi = 0;
    else {
        int i = 0;
        auto it = variable-1;
        str.erase(variable);
        while (it >= str.begin()){
            if (*it >= '0' && *it <= '9') {xishu_weizhi = (*it - 48) * pow(10, i) + xishu_weizhi; ++i;}
            else if (*it == '-') {xishu_weizhi *= -1; str.erase(it); break;}
            else if (*it == '+') {str.erase(it); break;}
            it = str.erase(it);
            --it;
        }
    }
}
void calc_xishu(string str, int &xishu_yizhi){
    auto calc = [&](const char &fuhao, int &num)->int
            {if (fuhao == '+') return xishu_yizhi+=num; else return xishu_yizhi-=num;};
    auto iter = str.begin();
    char fuhao = '+';
    int num = 0;
    while (!str.empty()){
        if (*iter >= '0' && *iter <= '9') num = num * 10 + *iter - 48;
        else {
            calc(fuhao, num);
            fuhao = *iter;
            num = 0;
        }
        if (str.size() == 1) calc(fuhao, num);
        iter = str.erase(iter);
    }
}
int main(int argc, char *argv[]){
//    string equal = "6a-5+1=2-2a";
//    string equal = "4+3x=8";
    string equal = "-5+12y=0";
    int xishu_weizhi1 = 0, xishu_weizhi2 = 0, xishu_yizhi1 = 0, xishu_yizhi2 = 0;
    //将等号两边区分开
    auto judge = bind2nd(equal_to<char>(), '=');
    string::iterator left_ = find_if(equal.begin(), equal.end(), judge);
    string left(equal.begin(), left_), right(left_+1, equal.end());
    //找到等式两边未知数位置，并将未知数前系数存储
    find_weizhi(left, xishu_weizhi1);
    cout << left << " " << xishu_weizhi1 << endl;
    find_weizhi(right, xishu_weizhi2);
    cout << right << " " << xishu_weizhi2 << endl;
    calc_xishu(left, xishu_yizhi1);
    calc_xishu(right, xishu_yizhi2);
    cout << static_cast<double>(xishu_yizhi1 - xishu_yizhi2) / (xishu_weizhi2 - xishu_weizhi1) << endl;
    return 0;
}

