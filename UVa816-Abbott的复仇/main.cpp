//
// Created by xiaosong on 2019/10/10.
//
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include "Abbott.h"
using namespace std;
map<char, function<void(int &, int &)>> moving_xy = {
        {'N', [](int &x, int &y)->void {--y;}},
        {'S', [](int &x, int &y)->void {++y;}},
        {'W', [](int &x, int &y)->void {--x;}},
        {'E', [](int &x, int &y)->void {++x;}}
};
int main(int argc, char *argv[]){
    string s = "WLF NR ER *";
//    istringstream istr(s);
//    string s1;
//    while (istr >> s1) cout << s1 << endl;
      auto a = vector<char>(s.begin(), s.end());
      for (auto const &e : a) cout << e << endl;
    return 0;
}

