#pragma once
#include "archi.hpp"
#include <map>
#include <set>
#include <vector>
#include <algorithm>
template <typename T>
class undirected_graph {
	std::map<T, std::set<T>> adj;
	std::vector<undirected_edge<T>> E;
	public:
		undirected_graph() {
			adj = {};
			E = {};
		}
		
		undirected_graph (const undirected_graph & other) {
			adj = other.adj;
			E = other.E;
		}
		
		void add_edge(const undirected_edge<T> & e) {
			adj[e.from()].insert(e.to());
			adj[e.to()].insert(e.from());
			E.push_back(e);
			std::sort(E.begin(), E.end());
			auto it = std::unique(E.begin(), E.end());
			E.erase (it, E.end());
		}
		
		const std::vector<undirected_edge<T>>& all_edges() const {
			return E;
		}
		
		const std::set<T>& neighbours(const T& v) const {
			return adj.at(v);
		}
		
		std::set<T> all_nodes() const{
			std::set<T> res;
			for (const auto& p: adj) {
				res.insert(p.first);
			}
			return res;
		}
		
		int edge_number(const undirected_edge<T>& e) const {
			for (size_t i = 0; i < E.size(); i++) {
				if (E[i] == e) {
					return i;
				}
			}
			return -1;
		}
		
		undirected_edge<T> edge_at(int i) const {
			return E[i];
		}
		
		undirected_graph operator-(const undirected_graph& G_2) const {
			undirected_graph G_f;
			for (size_t i = 0; i < E.size(); i++) {
				int n = G_2.edge_number(E[i]);
				if (n == -1) {
					G_f.add_edge(E[i]);
				}
			}
			return G_f;
		}
};