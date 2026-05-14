#pragma once
#include <iostream>
#include "archi.hpp"
template<typename I>
std::ostream& operator<<(std::ostream& os, const undirected_edge<I>& e) {
	I nodo_f = e.from();
	I nodo_t = e.to();
	os << "(" << nodo_f << ", " << nodo_t << ")";
	return os;
}