#pragma once
#include <set>
#include <map>
#include "grafi.hpp"
#include "archi.hpp"

template <typename T>
void dfs_ricorsive_helper(const undirected_graph<T>& G_1, const T& u, undirected_graph<T>& H_1, std::map<T, bool>& reached_1) {
	std::set<T> neigh = G_1.neighbours(u);
	for (const auto & w :neigh) {
		if (reached_1[w] == false) {
			undirected_edge<T> a(u,w);
			H_1.add_edge(a);
			reached_1[w] = true;
			dfs_ricorsive_helper(G_1, w, H_1, reached_1);
		}
	}
}

template <typename T>
undirected_graph<T> recursive_dfs(const undirected_graph<T>& G, const T& v) {
	undirected_graph<T> H;
	std::set<T> V = G.all_nodes();
	std::map<T, bool> reached;
	for (const auto& nodo : V) {
		reached[nodo] = false;
	}
	reached[v] = true;
	dfs_ricorsive_helper(G, v, H, reached);
	return H;
}
