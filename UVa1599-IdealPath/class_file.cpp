//
// Created by xiaosong on 2019/11/7.
//

#include "class_file.h"

graph::graph(const string &paths): path(paths) {

}

graph::graph(const graph &g) {

}

graph::graph(graph &&g) {

}

graph &graph::operator=(const graph &) {
    return *this;
}

graph &graph::operator=(graph &&) {
    return *this;
}

