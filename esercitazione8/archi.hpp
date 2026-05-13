#pragma once
template<typename T>
class undirected_edge {
	T edge_from;
	T edge_to;
	public:
		undirected_edge(T a, T b) {
			if (a < b) {
				edge_from = a;
				edge_to = b;
			}
			else {
				edge_from = b;
				edge_to = a;
			}
		}
		
		T from() const {
			return edge_from;
		}
		
		T to() const {
			return edge_to;
		}
		
		bool operator< (const undirected_edge& e_2) const {
			T from_2 = e_2.from();
			T to_2 = e_2.to();
			if (edge_from < from_2 || (edge_from== from_2 && edge_to < to_2) ) {
				return true;
			}
			else {
				return false;
			}			
		}
		
		bool operator== (const undirected_edge& e_2) const {
			T from_2 = e_2.from();
			T to_2 = e_2.to();
			if (edge_from == from_2 && edge_to == to_2) {
				return true;
			}
			else {
				return false;
			}
		}
};