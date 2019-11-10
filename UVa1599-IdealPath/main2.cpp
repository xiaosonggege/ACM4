//
// Created by xiaosong on 2019/11/9.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int fun1(int a, int b){
    return a*b;
}
int fun2(int a, int b, int (*funp)(int, int)){
    return (*funp)(a, b);
}
int main(int argc, char *argv[]){
    cout << fun2(2, 3, *fun1) << endl;
    return 0;
}

