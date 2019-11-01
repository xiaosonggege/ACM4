//
// Created by xiaosong on 2019/10/23.
//

#include "Sculpture.h"
#include "Discretization.h"
#include <iterator>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
using axis3_g = vector<vector<vector<pair<char, vector<int>>>>>;
using axis2_g = vector<vector<pair<char, vector<int>>>>;
using axis1_g = vector<pair<char, vector<int>>>;
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
}

Sculpture::Sculpture(Sculpture &&s) noexcept {
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

Sculpture &Sculpture::operator=(Sculpture &&s) noexcept {
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

void Sculpture::V_calc() {
    discretization xyz_dis;
    auto xyz = xyz_dis(this->boxes); //xyz为xyz三轴离散坐标
    vector<int> x_delta = get<0>(xyz), y_delta = get<1>(xyz), z_delta = get<2>(xyz);
    //添加外围坐标点对应的实际长度
    void buchong(vector<int> &series);
    buchong(x_delta);
    buchong(y_delta);
    buchong(z_delta);
    Blocking blocking({x_delta, y_delta, z_delta});
//    blocking.show(cout);
    //经过坐标离散化后用左上角坐标代替长方体后的所有坐标值
    vector<vector<int>> left_up_points = blocking(this->boxes);
    //建立相对坐标空间
//    using axis3_g = vector<vector<vector<pair<char, int>>>>;
//    using axis2_g = vector<vector<pair<char, int>>>;
//    using axis1_g = vector<pair<char, int>>;
    axis1_g v1(z_delta.size()-1, make_pair(' ', vector<int>(3, 0)));
    axis2_g v2(y_delta.size()-1, v1);
    axis3_g graph(x_delta.size()-1, v2);
    bool judge(const vector<vector<int>> &v, const int &i, const int &j, const int &k);
    for (unsigned int axis1 = 0; axis1 != graph.size(); ++axis1){
        for (unsigned int axis2 = 0; axis2 != v2.size(); ++axis2){
            for (unsigned int axis3 = 0; axis3 != v1.size(); ++axis3){
                if (judge(left_up_points, axis1, axis2, axis3))graph[axis1][axis2][axis3].first = '*';
                graph[axis1][axis2][axis3].second = vector<int>({x_delta[axis1+1]-x_delta[axis1],
                        y_delta[axis2+1]-y_delta[axis2], z_delta[axis3+1]-z_delta[axis3]});
            }
        }
    }
    //////////验证输出//////////
//    for (const auto &e1 : graph)
//        for (const auto &e2 : e1)
//            for (const auto &e3 : e2)
//                cout << e3.first <<  " " << e3.second << endl;
    //计算总体积
    int Vtotal = x_delta.back() * y_delta.back() * z_delta.back();
    cout << "总体积为:" << Vtotal << endl;
    void DFS(int x, int y, int z, const axis3_g &graph, int &v_water, int &s, vector<vector<int>> &after);
    int v_water = 0;
    vector<vector<int>> after;
    DFS(0, 0, 0, graph, v_water, this->S, after);
    this->V = Vtotal - v_water;
    cout << this->V << " " << this->S << endl;
}
void buchong(vector<int> &series){
    series.insert(series.begin(), series[0]-1);
    series.push_back(*(series.end()-1)+1);
}
bool judge(const vector<vector<int>> &v, const int &i, const int &j, const int &k){
    if (find(v.cbegin(), v.cend(), vector<int>({i, j, k})) != v.cend())
        return 1;
    return 0;
}
void DFS(int x, int y, int z, const axis3_g &graph, int &v_water, int &s, vector<vector<int>> &after){
    tuple<int, int> s_cum(int i, int j, int k);
    for (int i = -1; i != 2; ++i){
        for (int j = -1; j != 2; ++j){
            for (int k = -1; k != 2; ++k){
                if ((i || j || k) && x+i >= 0 && x+i < graph.size()
                && y+j >=0 && y+j < graph[0].size() && z+k >= 0 && z+k < graph[0][0].size()) {
                    vector<int> axis = {x+i, y+j, z+k};
                    if (find(after.begin(), after.end(), axis) == after.end() && graph[axis[0]][axis[1]][axis[2]].first != '*') {
                        after.push_back(axis);
                        v_water += graph[axis[0]][axis[1]][axis[2]].second[0]*graph[axis[0]][axis[1]][axis[2]].second[1]*
                                graph[axis[0]][axis[1]][axis[2]].second[2];
                        DFS(axis[0], axis[1], axis[2], graph, v_water, s, after);
                    }
                    if (graph[axis[0]][axis[1]][axis[2]].first == '*' && abs(i) + abs(j) + abs(k) == 1){
                            auto ax = s_cum(i, j, k);
                            s += graph[axis[0]][axis[1]][axis[2]].second[get<0>(ax)] * graph[axis[0]][axis[1]][axis[2]].second[get<1>(ax)];
                    }
                }
            }
        }
    }
}
tuple<int, int> s_cum(int i, int j, int k){
    if (abs(i) == 1) return make_tuple(1, 2);
    else if (abs(j) == 1) return make_tuple(0, 2);
    else return make_tuple(0, 1);
}
