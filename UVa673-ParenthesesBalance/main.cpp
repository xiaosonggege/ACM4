//
// Created by 宋云龙 on 2019/11/28.
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "Parentheses.h"
using namespace std;
int main(int argc, char *argv[]){
    const string path = "/Users/songyunlong/CLionProjects/ACM4/UVa673-ParenthesesBalance/file";
    ifstream ifstrm;
    ifstrm.open(path, ios::in);
    int num;
    string temp;
    getline(ifstrm, temp);
    istringstream istr1(temp);
    istr1 >> num;
    cout << num << "个匹配串的匹配结果如下:" << endl;
    while (getline(ifstrm, temp)){
        istringstream istr2(temp);
        cout << istr2.str() << endl;
        parentheses p1(istr2.str());
        p1(cout);
    }
    ifstrm.close();
    return 0;
}
