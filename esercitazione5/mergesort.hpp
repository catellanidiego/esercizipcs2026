#pragma once
#include <vector>
#include <cmath> //reperita documentazione online per l'implementazione di floor
#include "merge.hpp"
template<typename T>
void mergesort(std::vector<T>& vec, int p, int r) {
	if (p<r) {
		int q = std::floor((p+r)/2);
		mergesort(vec, p, q);
		mergesort(vec, q + 1, r);
		merge(vec, p, q, r);
	}
}