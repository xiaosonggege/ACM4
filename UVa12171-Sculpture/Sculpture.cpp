//
// Created by xiaosong on 2019/10/23.
//

#include "Sculpture.h"
#include <iterator>
#include <iomanip>
using namespace std;
int Sculpture::count = 0;
Sculpture::Sculpture(const string &path): file_path(path) {
    ifstream ifstrm;
    ifstrm.open(this->file_path, ios::in);
    string s_temp;
    while (getline(ifstrm, s_temp)){
        istringstream istr(s_temp);
        istream_iterator<int> in_iter(istr), eof;
        this->boxes.push_back(vector<int>(in_iter, eof));
    }
    ifstrm.close();
}

Sculpture::Sculpture(const Sculpture &s) {
    this->file_path = s.file_path;
    this->boxes = s.boxes;
    this->S = s.S;
    this->V = s.V;
//    this->count = s.count;
}

Sculpture::Sculpture(Sculpture &&s) {
    this->file_path = s.file_path;
    this->boxes = s.boxes;
    this->S = s.S;
    this->V = s.V;
    s.file_path.clear();
    s.boxes.clear();
    s.S = 0;
    s.V = 0;
}

Sculpture &Sculpture::operator=(const Sculpture &s) {
    this->file_path = s.file_path;
    this->boxes = s.boxes;
    this->S = s.S;
    this->V = s.V;
    return *this;
}

Sculpture &Sculpture::operator=(Sculpture &&s) {
    this->file_path = s.file_path;
    this->boxes = s.boxes;
    this->S = s.S;
    this->V = s.V;
    s.file_path.clear();
    s.boxes.clear();
    s.S = 0;
    s.V = 0;
    return *this;
}

ostream &Sculpture::show(ostream &os) {
    os << "文件中需要统计的立方体个数为:" << endl;
    os << Sculpture::count << endl;
    return os;
}

ostream &Sculpture::print(ostream &os) {
    cout << "立方体的组成盒子信息分别为:" << endl;
    cout << setw(4) << left << "x0" << setw(4) << left << "y0" << setw(4) << left << "z0" <<
    setw(4) << left << "x" << setw(4) << left << "y" << setw(5) << left << "z" << endl;
    for (const auto &e : this->boxes){
        for (const auto &e2 : e)
            cout << setw(4) << left << e2;
        cout << endl;
    }
    return os;
}

Sculpture::~Sculpture() {

}

