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
    int *p = new int(5), j = 3;
    int *d = p;
    delete p;
    p = nullptr;
//    delete p;
//    free(p);
    int e = *d;
    cout << e << endl;
    cout << *p << endl;
    return 0;
}

