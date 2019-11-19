//
// Created by xiaosong on 2019/11/7.
//

#include "class_file.h"
#include <tuple>
#include <algorithm>
using namespace std;
graph::graph(const string &paths, const int &points, const int &edges):
path(paths), point_num(points), edge_num(edges) {
    try{
        ifstream ifstrm;
        ifstrm.open(path, ios::in);
        if (!ifstrm) throw string("文件打开失败");
        string temp_s;
        int basic_info_finish = 0;
        vector<tuple<int, int, int>> info; //存储无向图中的结点间的连接信息
        while (getline(ifstrm, temp_s)){
            istringstream istr(temp_s);
            if (!basic_info_finish) {
                istr >> this->point_num >> this->edge_num;
                basic_info_finish = 1 - basic_info_finish;
            }
            else{
                int temp_p1, temp_p2, color;
                istr >> temp_p1 >> temp_p2 >> color;
                info.push_back(make_tuple(temp_p1, temp_p2, color));
            }
        }
        //筛选自环，查找并删除
        decltype(info)::iterator iter_info = info.begin();
        while (iter_info != info.end()){
            if (get<0>(*iter_info) == get<1>(*iter_info)) iter_info = info.erase(iter_info);
            else ++iter_info;
        }
        //
//    for (auto const &e : info){
//        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
//    }
        //对linjiebiao进行赋值
        this->linjiebiao = vector<node>(this->point_num, node());
        for (int num = 0; num != this->point_num; ++num) this->linjiebiao[num].number = num+1;
        node_ptr node_move; //建立邻接表中横向移动指针
        for (auto const &e : info){
            //判断该结点对是否已经存在，如果存在则直接将颜色加入对应序列中
//        node_move = &this->linjiebiao[get<0>(e)];
            if (find_node(get<0>(e), get<1>(e), *this, node_move)) node_move->color_level.push_back(get<2>(e));
            else node_move->next = new node(get<1>(e), vector<int>({get<2>(e)}));
            node_move = &this->linjiebiao[get<1>(e)];
            if (find_node(get<1>(e), get<0>(e), *this, node_move)) node_move->color_level.push_back(get<2>(e));
            else node_move->next = new node(get<0>(e), vector<int>({get<2>(e)}));
        }
        ifstrm.close();
    }
    catch (const string &error) {cerr << error;}
    //初始化dis2end
    int i = 1;
    while (i != this->point_num+1){
        this->dis2end.push_back(make_pair(i++, 0));
    }
    graph::calc_dis2end();
//    for (auto const &e : this->dis2end)
//        cout << e.first << " " << e.second << endl;
}

graph::graph(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
}

graph::graph(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    g.path.clear();
    g.linjiebiao.clear();
    g.dis2end.clear();
}

graph &graph::operator=(const graph &g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    return *this;
}

graph &graph::operator=(graph &&g) {
    this->point_num = g.point_num;
    this->edge_num = g.edge_num;
    this->path = g.path;
    this->linjiebiao = g.linjiebiao;
    this->dis2end = g.dis2end;
    g.path.clear();
    g.linjiebiao.clear();
    g.dis2end.clear();
    return *this;
}

graph::~graph() {
    //释放邻接表所占用的动态空间
    for (auto &e : this->linjiebiao){
        node_ptr move = e.next;
        while (move){
            node_ptr move_pre = move;
            move = move->next;
            shared_ptr<node> free_ptr(move_pre);
        }
    }
    for_each(this->linjiebiao.begin(), this->linjiebiao.end(), [](node &n)->void {n.next = nullptr;});
    this->linjiebiao.clear();
}

void graph::calc_dis2end() {
    //建立移动指针
    node_ptr node_p = &this->linjiebiao.back();
    vector<int> *stack = new vector<int>, *stack_2 = new vector<int>; //存储堆栈
    stack->push_back(node_p->number);
    //BFS部分
    //遍历当前node_p指向结点为表头的整个链表，压入栈
    while (!stack->empty()){
        while (node_p){
            if (find(stack->cbegin(), stack->cend(), node_p->number) == stack->cend() &&
            find(stack_2->cbegin(), stack_2->cend(), node_p->number) == stack_2->cend()){ //结点中的数值不在栈stack中,也不在stack_2中
                stack->push_back(node_p->number);
                this->dis2end[node_p->number-1].second = this->dis2end[stack->front()-1].second + 1;
            }
            node_p = node_p->next;
        }
        stack_2->push_back(*stack->begin());
        stack->erase(stack->begin()); //栈底编号结点已经被遍历完
        node_p = &this->linjiebiao[stack->front()];
    }
    shared_ptr<vector<int>> ptr_stack(stack), ptr_stack_2(stack_2);
    stack = nullptr;
    stack_2 = nullptr;
}

ostream &graph::BFS_min_dict(ostream &os) &{
    //建立存储结点的队列
    vector<tuple<int, vector<int>>> stack;
    vector<int> stack2;
    //存入起始结点
    stack.push_back(make_tuple(1, vector<int>({})));
    int num = 1, dis = 100, color = 100;
    //统计终点所连接的结点
    int count = 0;
    for (node_ptr p = this->linjiebiao[4-1].next; p; p=p->next) ++count;
    //
    node_ptr node_p = &this->linjiebiao[num-1];
    while (count){
        node_p = node_p->next;
        while (node_p){
            auto judge = [&](tuple<int, vector<int>> tup)->bool {return get<0>(tup) == node_p->number;};
            if (node_p->number != 4){
                if (find(stack2.cbegin(), stack2.cend(), node_p->number) != stack2.cend() ||
                    find_if (stack.begin(), stack.end(), judge) != stack.end()) {
                    node_p = node_p->next;
                    continue;
                }
            }
            num = node_p->number;

            decltype(color) color_lev = *min_element(node_p->color_level.begin(), node_p->color_level.end());
            if (this->dis2end[node_p->number-1].second <= dis && color_lev <= color) {
                dis = this->dis2end[node_p->number-1].second;
                color = color_lev;
                auto v = get<1>(*stack.begin());
                v.push_back(get<0>(*stack.begin()));
                stack.push_back(make_tuple(node_p->number, v));
            }
            if (node_p->number == 4) {--count; break;}
            node_p = node_p->next;
        }
        stack2.push_back(get<0>(*stack.begin()));
        stack.erase(stack.begin());
        node_p = &this->linjiebiao[get<0>(*stack.begin())-1];
        dis = 100, color = 100;
    }
    decltype(num) num_node = get<1>(stack.back()).size();
    os << num_node << endl;
    for (auto const &e : get<1>(stack.back())) os << e << " ";
    os << endl;
    return os;
}

