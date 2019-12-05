//
// Created by 宋云龙 on 2019/12/5.
//

#ifndef ACM3_CLION_KNIGHTMOVES_H
#define ACM3_CLION_KNIGHTMOVES_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class KnightMoves{
private:
    vector<vector<int>> qipan;
    string start;
    string end;
    int result = 0;
public:
    KnightMoves() = default;
    virtual ~KnightMoves() = default;
    KnightMoves(const string &, const string &);
    KnightMoves(const KnightMoves &);
    KnightMoves(KnightMoves &&);
    KnightMoves & operator=(const KnightMoves &);
    KnightMoves & operator=(KnightMoves &&);
    ostream & operator()(ostream &) const;
    void move(); //移动函数
};
#endif //ACM3_CLION_KNIGHTMOVES_H
