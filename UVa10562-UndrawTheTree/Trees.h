//
// Created by xiaosong on 2019/10/13.
//

#ifndef ACM3_CLION_TREES_H
#define ACM3_CLION_TREES_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using Graph = vector<vector<char>>;
class UndrawTheTrees{
private:
    Graph graph2tree;
    string result; //最终遍历结果
public:
    UndrawTheTrees() = default;
    UndrawTheTrees(const Graph &);
    ostream &operator()(ostream &) const;
    UndrawTheTrees(const UndrawTheTrees &);
    UndrawTheTrees(UndrawTheTrees &&);
    UndrawTheTrees & operator=(const UndrawTheTrees &);
    UndrawTheTrees & operator=(UndrawTheTrees &&);
    ~UndrawTheTrees();
    void reading();
    ostream & show(ostream &) const &;
};
#endif //ACM3_CLION_TREES_H
