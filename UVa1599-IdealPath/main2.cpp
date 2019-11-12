//
// Created by xiaosong on 2019/11/9.
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
using namespace std;
int fun(shared_ptr<int> p){
    cout << p.use_count() << endl;
    return 0;
}
int main(int argc, char *argv[]){
    shared_ptr<int> p = make_shared<int>();
    shared_ptr<int> &p2 = p;
    *p2 = 1;
    fun(p);
    cout << p.use_count() << endl;
    return 0;
}

