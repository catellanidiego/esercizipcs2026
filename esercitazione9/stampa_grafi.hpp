#pragma once
#include "grafi.hpp"
#include "archi.hpp"
#include <iostream>

template <typename T>
void print_graphviz(const undirected_graph<T>& G) {
    std::cout << "graph G {" << "\n";
    std::vector<undirected_edge<T>> V = G.all_edges(); 
    
    for (const undirected_edge<T>& e : V) {
        std::cout << "    " << e.from() << " -- " << e.to() << ";" << "\n";
    }
    
    std::cout << "}" << "\n";
}