//
// Created by 宋云龙 on 2019/12/5.
//
#include "knightmoves.h"
#include <algorithm>
#include <sstream>
using namespace std;
KnightMoves::KnightMoves(const string &starts, const string &ends): start(starts), end(ends) {
    const string &standard = "abcdefgh";
    auto mapping = [&](const char &target)->int {auto pos = find(standard.cbegin(), standard.cend(), target);
    return pos - standard.begin();};
    this->qipan = vector<vector<int>>(8, vector<int>(8));
    char first_;
    int second_;
    stringstream str_iter;
    str_iter.clear();
    str_iter << this->start;
    str_iter >> first_ >> second_;
    this->qipan[mapping(first_)][second_] = 1;
    str_iter.clear();
    str_iter << this->end;
    str_iter >> first_ >> second_;
    this->qipan[mapping(first_)][second_] = 1;
}

KnightMoves::KnightMoves(const KnightMoves &k) {
    this->qipan = k.qipan;
    this->start = k.start;
    this->end = k.end;
    this->result = k.result;
}

KnightMoves::KnightMoves(KnightMoves &&k) {
    this->qipan = k.qipan;
    this->start = k.start;
    this->end = k.end;
    this->result = k.result;
    k.qipan.clear();
    k.start.clear();
    k.end.clear();
    k.result = 0;
}

KnightMoves &KnightMoves::operator=(const KnightMoves &k) {
    this->qipan = k.qipan;
    this->start = k.start;
    this->end = k.end;
    this->result = k.result;
    return *this;
}

KnightMoves &KnightMoves::operator=(KnightMoves &&k) {
    this->qipan = k.qipan;
    this->start = k.start;
    this->end = k.end;
    this->result = k.result;
    k.qipan.clear();
    k.start.clear();
    k.end.clear();
    k.result = 0;
    return *this;
}

ostream &KnightMoves::operator()(ostream &os) const {
    os << "起点为: " << this->start << endl;
    os << "终点为: " << this->end << endl;
    return os;
}

void KnightMoves::move() {

}
