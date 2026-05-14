#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "fifo.hpp"
#include "lifo.hpp"
#include "grafi.hpp"
#include "graph_visit.hpp"
#include "stampa_grafi.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"
int main(){
	fifo<int> q;
	q.put(10); 
	q.put(20);
	int x = q.get(); 
	std::cout << "Valore estratto dalla coda: " << x << "\n"; //DEVE USCIRE 10
	int y = q.get();
	std::cout << "Valore estratto dalla coda: " << y << "\n"; //DEVE USCIRE 20
	if ( q.empty() ) { 
		std::cout << "Coda vuota" << "\n";
	}

	std::cout << "\n";
	lifo<int> L;
	L.put(10);
	L.put(20);
	int z = L.get();
	std::cout << "Valore ottenuto: " << z << "\n"; //DEVE USCIRE 20
	int w = L.get();
	std::cout << "Valore ottenuto: " << w << "\n"; //DEVE USCIRE 10
	if (L.empty ()) {
		std::cout << "Stack vuoto" << "\n";
	}

	undirected_graph<int> G;
	undirected_edge<int> a(1,2);
	undirected_edge<int> b(1,3);
	undirected_edge<int> c(1,4);
	undirected_edge<int> d(1,6);
	undirected_edge<int> e(2,4);
	undirected_edge<int> f(2,5);
	undirected_edge<int> g(2,7);
	undirected_edge<int> h(3,6);
	undirected_edge<int> i(4,6);
	undirected_edge<int> j(4,7);
	undirected_edge<int> k(5,7);
	undirected_edge<int> l(6,7);
	undirected_edge<int> m(6,8);
	undirected_edge<int> n(7,9);
	undirected_edge<int> o(8,9);
	G.add_edge(a);
	G.add_edge(b);
	G.add_edge(c);
	G.add_edge(d);
	G.add_edge(e);
	G.add_edge(f);
	G.add_edge(g);
	G.add_edge(h);
	G.add_edge(i);
	G.add_edge(j);
	G.add_edge(k);
	G.add_edge(l);
	G.add_edge(m);
	G.add_edge(n);
	G.add_edge(o);
	
	std::cout << "\n";
	std::cout << "Grafo originale" << "\n";
	print_graphviz(G);
	
	std::cout << "\n";
	fifo<int> Q;
	undirected_graph<int> bfsG = graph_visit (G, 1, Q);
	std::cout << "Grafo bfsG" << "\n";
	print_graphviz (bfsG);
	
	std::cout << "\n";
	lifo<int> S;
	undirected_graph<int> dfsG = graph_visit(G, 1, S);
	std::cout << "Grafo dfsG" << "\n";
	print_graphviz (dfsG);

	std::cout << "\n";
	undirected_graph<int> H = recursive_dfs(G, 1);
	std::cout << "Grafo dfs ricorsiva" << "\n";
	print_graphviz (H);

	std::map<undirected_edge<int>, double> W;
	W[a] = 2.0;
	W[b] = 1.0; 
	W[c] = 20.0;  
	W[d] = 50.0;  
	W[e] = 2.0;   
	W[f] = 3.0;   
	W[g] = 1.0;   
	W[h] = 2.0;   
	W[i] = 5.0;   
	W[j] = 25.0;  
	W[k] = 2.0;   
	W[l] = 10.0;  
	W[m] = 2.0;   
	W[n] = 100.0; 
	W[o] = 1.0;
	
	std::cout << "\n";
	int sorgente = 1;
	std::map<int, double> distanze = Dijkstra(G, sorgente, W);
	std::set<int> V = G.all_nodes();
	std::cout << "Distanza minima con partenza: " << sorgente << "\n";
	for (const int& v : V) {
		std::cout << "arrivo: " << v << " : " << distanze[v] << "\n";
	}
	
	return 0;
}