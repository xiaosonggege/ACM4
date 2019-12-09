//
// Created by 宋云龙 on 2019/12/5.
//
#include "knightmoves.h"
#include <algorithm>
#include <sstream>
#include <string>
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
    this->start_axis = make_pair(mapping(first_), second_);
    str_iter.clear();
    str_iter << this->end;
    str_iter >> first_ >> second_;
    this->qipan[mapping(first_)][second_] = 1;
    this->end_axis = make_pair(mapping(first_), second_);
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
    os << "所走步数为: " << this->result << endl;
    return os;
}

void KnightMoves::move(vector<tuple<int, int, int>> &stack, int x, int y, int step) {
    if (x-1 >= 0 && y-2 >=0){
        if (this->qipan[x-1][y-2] != 2) {
            if (this->qipan[x-1][y-2] != 1) {
                stack.push_back(make_tuple(x-1, y-2, step+1));
                this->qipan[x-1][y-2] = 2;
            }
            else this->result = step;
        }
    }
    else if (x-1 >= 0 && y+2 <= this->qipan[0].size()){
        if (this->qipan[x-1][y+2] != 2) {
            if (this->qipan[x-1][y+2] != 1) {
                stack.push_back(make_tuple(x-1, y+2, step+1));
                this->qipan[x-1][y+2] = 2;
            }
            else this->result = step;
        }
    }
    else if (x+1 <= this->qipan.size() && y-2 >= 0){
        if (this->qipan[x+1][y-2] != 2) {
            if (this->qipan[x+1][y-2] != 1) {
                stack.push_back(make_tuple(x+1, y-2, step+1));
                this->qipan[x+1][y-2] = 2;
            }
            else this->result = step;
        }
    }
    else if (x+1 <= this->qipan.size() && y+2 <= this->qipan[0].size()){
        if (this->qipan[x+1][y+2] != 2) {
            if (this->qipan[x+1][y+2] != 1) {
                stack.push_back(make_tuple(x+1, y+2, step+1));
                this->qipan[x+1][y+2] = 2;
            }
            else this->result = step;
        }
    }
    else if (x-2 >= 0 && y-1 >= 0){
        if (this->qipan[x-2][y-1] != 2) {
            if (this->qipan[x-2][y-1] != 1) {
                stack.push_back(make_tuple(x-2, y-1, step+1));
                this->qipan[x-2][y-1] = 2;
            }
            else this->result = step;
        }
    }
    else if (x-2 >= 0 && y+1 <= this->qipan[0].size()){
        if (this->qipan[x-2][y+1] != 2) {
            if (this->qipan[x-2][y+1] != 1) {
                stack.push_back(make_tuple(x-2, y+1, step+1));
                this->qipan[x-2][y+1] = 2;
            }
            else this->result = step;
        }
    }
    else if (x+2 <= this->qipan.size() && y-1 >= 0){
        if (this->qipan[x+2][y-1] != 2) {
            if (this->qipan[x+2][y-1] != 1) {
                stack.push_back(make_tuple(x+2, y-1, step+1));
                this->qipan[x+2][y-1] = 2;
            }
            else this->result = step;
        }
    }
    else if (x+2 <= this->qipan.size() && y+1 <= this->qipan[0].size()){
        if (this->qipan[x+2][y+1] != 2) {
            if (this->qipan[x+2][y+1] != 1) {
                stack.push_back(make_tuple(x+2, y+1, step+1));
                this->qipan[x+2][y+1] = 2;
            }
            else this->result = step;
        }
    }
    else{
        tuple<int, int, int> stack_head = stack.front();
        stack.erase(stack.begin());
        this->move(stack, get<0>(stack_head), get<1>(stack_head), get<2>(stack_head));
    }
}
void KnightMoves::BFS() {
    shared_ptr<vector<tuple<int, int, int>>> stack = make_shared<vector<tuple<int, int, int>>>();
    stack->push_back(make_tuple(this->start_axis.first, this->start_axis.second, 0));
    this->move(*stack, this->start_axis.first, this->start_axis.second, 0);
}
