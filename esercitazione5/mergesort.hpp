#pragma once
#include <vector>
#include "merge.hpp"
template<typename T>
void mergesort(std::vector<T>& vec, int p, int r) {
	if (p<r) {
		int q = (p+r)/2;
		mergesort(vec, p, q);
		mergesort(vec, q + 1, r);
		merge(vec, p, q, r);
	}
}