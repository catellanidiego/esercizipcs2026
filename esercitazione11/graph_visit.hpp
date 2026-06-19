#pragma once
#include <iostream>
#include <set>
#include <map>
#include "graph.hpp"
#include "edge.hpp"

template <typename T, typename C>
graph<T> graph_visit(const graph<T>& G, const T& v, C& t) {
	graph<T> H;
	std::set<T> V = G.all_nodes();
	std::map<T, bool> reached;
	for (const auto& nodo : V) {
		reached[nodo] = false;
	}
	t.put(v);
	reached[v] = true;
	while(!t.empty()) {
		T u = t.get();
		std::set<T> neigh = G.neighbours(u);
		for (const auto & w : neigh) {
			if (reached[w] == false) {
				t.put(w);
				reached[w] = true;
				edge<T> a(u,w);
				H.add_edge(a);
			}
		}
	}
	
	return H;
}