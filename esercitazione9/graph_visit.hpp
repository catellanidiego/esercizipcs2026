#pragma once
#include <iostream>
#include <set>
#include <map>
#include "grafi.hpp"
#include "archi.hpp"

template <typename T, typename C>
undirected_graph<T> graph_visit(const undirected_graph<T>& G, const T& v, C& t) {
	undirected_graph<T> H;
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
				undirected_edge<T> a(u,w);
				H.add_edge(a);
			}
		}
	}
	
	return H;
}