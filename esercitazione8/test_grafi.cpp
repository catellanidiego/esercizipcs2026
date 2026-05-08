#include "archi.hpp"
#include "grafi.hpp"
#include "stampa_archi.hpp"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>
int main() {
	int global_result = EXIT_SUCCESS;
	std::map<std::string, int> T; //chiavi: tipo di test, valori: risultato.
	undirected_graph<char> Z;
	undirected_edge<char> v('A', 'B');
	undirected_edge<char> w('B', 'C');
	undirected_edge<char> u('C', 'D');
	Z.add_edge(v);
	Z.add_edge(w);
	Z.add_edge(u);
	
	std::set<char> test_neighbours = Z.neighbours('B');
	std::set<char> giusto_1 = {'A', 'C'};
	if (test_neighbours != giusto_1) {
		T["test_neighbours"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_neighbours"] = EXIT_SUCCESS;
	}
	
	std::vector<undirected_edge<char>> test_all_edges = Z.all_edges();
	std::vector<undirected_edge<char>> giusto_2 = {v, w, u};
	if (test_all_edges != giusto_2) {
		T["test_all_edges"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_all_edges"] = EXIT_SUCCESS;
	}
	
	std::set<char> test_all_nodes = Z.all_nodes();
	std::set<char> giusto_3 = {'A', 'B', 'C', 'D'};
	if (test_all_nodes != giusto_3) {
		T["test_all_nodes"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_all_nodes"] = EXIT_SUCCESS;
	}
	
	undirected_edge<char> test_edge_at = Z.edge_at(2);
	undirected_edge<char> giusto_4 = u;
	if (test_edge_at != giusto_4) {
		T["test_edge_at"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_edge_at"] = EXIT_SUCCESS;
	}
	
	int test_edge_number = Z.edge_number(w);
	int giusto_5 = 1;
	if (test_edge_number != giusto_5) {
		T["test_edge_number"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_edge_number"] = EXIT_SUCCESS;
	}
	
	std::vector<undirected_edge<char>> test_add_edge_prima = Z.all_edges();
	undirected_edge<char> p('D', 'A');
	Z.add_edge(p);
	std::vector<undirected_edge<char>> test_add_edge_dopo = Z.all_edges();
	std::vector<undirected_edge<char>> giusto_prima = {v, w, u};
	std::vector<undirected_edge<char>> giusto_dopo = {v, p, w, u};
	if (test_add_edge_prima != giusto_prima || test_add_edge_dopo != giusto_dopo) {
		T["test_add_edge"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_add_edge"] = EXIT_SUCCESS;
	}
	
	undirected_graph<char> G;
	G.add_edge(v);
	G.add_edge(p);
	undirected_graph<char> H = Z - G;
	std::vector<undirected_edge<char>> H_edges = H.all_edges();
	std::vector<undirected_edge<char>> giusto_6 = {w, u};
	if (H_edges != giusto_6) {
		T["test_graph_difference"] = EXIT_FAILURE;
		global_result = EXIT_FAILURE;
	}
	else {
		T["test_graph_difference"] = EXIT_SUCCESS;
	}
	
	if (global_result == EXIT_SUCCESS) {
		std::cout << "Tutti i test sono riusciti!" << "\n";
		return global_result;
	}
	else {
		std::cout << "Test globale fallito, nello specifico:" << "\n";
		for (const auto& x : T) {
			if (x.second == EXIT_FAILURE) {
				std::cout << " - Test " << x.first << " fallito." << "\n";
			}
		}
		return global_result;
	}
}