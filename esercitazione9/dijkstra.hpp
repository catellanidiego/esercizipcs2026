#pragma once
#include <set>
#include <map>
#include <queue>
#include <optional> //reperita documentazione online per rappresentare l'assenza di valori
#include <limits> //reperita documentazione online per rappresentare gli infiniti
#include "archi.hpp"
#include "grafi.hpp"

template <typename T>
std::map<T, double> Dijkstra (const undirected_graph<T>& G, const T& s, const std::map<undirected_edge<T>, double>& W) {
	std::set<T> V = G.all_nodes();
	std::map<T, std::optional<T>> pred;
	std::map<T, double> dist;
	for (const T& nodo : V) {
		pred[nodo] = std::nullopt;
		dist[nodo] = std::numeric_limits<double>::infinity();
	}
	pred.at(s) = s;
	dist.at(s) = 0;
	using pii = std::pair<double, T>;	
	std::priority_queue <pii, std::vector<pii>,std::greater<pii>> PQ;
	for (const T& nodo : V) {
		pii A(dist[nodo], nodo);
		PQ.push(A);
	}
	while (!PQ.empty()) {
		pii B = PQ.top();
		PQ.pop();
		double d_u = B.first;
		T u = B.second;
		if (d_u > dist[u]) {
			continue;
		}
		std::set<T> neigh = G.neighbours(u);
		for (const T& w : neigh) {
			undirected_edge<T> e(u,w);
			if (dist[w] > dist [u] + W.at(e)) {
				dist[w] = dist[u] + W.at(e);
				pred[w] = u;
				pii C(dist[w], w);
				PQ.push(C);
			}
		}
		
	}
	return dist;
}