//
// Created by 宋云龙 on 2019/12/2.
//

#ifndef ACM3_CLION_TREERECOVERY_H
#define ACM3_CLION_TREERECOVERY_H
#include <string>
#include <vector>
using namespace std;
struct BiTreeNode{
    char data;
    BiTreeNode *lchild = nullptr;
    BiTreeNode *rchild = nullptr;
};
class treerecovery{
private:
    string input;
    BiTreeNode *root = nullptr;
    string result;
public:
    treerecovery() = default;
    virtual ~treerecovery();
    treerecovery(const string &);
    treerecovery(const treerecovery &);
    treerecovery(treerecovery &&);
    treerecovery & operator=(const treerecovery &) noexcept;
    treerecovery & operator=(treerecovery &&) noexcept ;
    ostream & operator()(ostream &) const;
    BiTreeNode *& build();
};
#endif //ACM3_CLION_TREERECOVERY_H
