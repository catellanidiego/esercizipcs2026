#pragma once
#include "graph.hpp"
#include "edge.hpp"
#include <iostream>

template <typename T>
void print_graphviz(const graph<T>& G) {
    std::cout << "graph G {" << "\n";
    std::vector<edge<T>> V = G.all_edges(); 
    
    for (const edge<T>& e : V) {
        std::cout << "    " << e.from() << " -- " << e.to() << ";" << "\n";
    }
    
    std::cout << "}" << "\n";
}