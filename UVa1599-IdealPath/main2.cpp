//
// Created by xiaosong on 2019/11/9.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char *argv[]){
    int b[] = {1, 2, 3};
    vector<int> a(b, b+3);
    vector<int> *p = &a;
    cout << (*p)[2] << endl;
    return 0;
}

