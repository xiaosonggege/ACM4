//
// Created by xiaosong on 2019/11/9.
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;
shared_ptr<int> fun(shared_ptr<int> p){
    shared_ptr<int> p33 = p;
    cout << p.use_count() << endl;
    return p;
}
int main(int argc, char *argv[]){
    string s = "1 2 3 4";
    istringstream istr(s);
    int a, b, c, d;
    istr >> a >> b >> c >> d;
    cout << a << " " << b << " " << d << endl;
    return 0;
}

