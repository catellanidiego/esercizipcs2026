#pragma once
#include <vector>
#include "partition.hpp"
#include "insertionsort.hpp"
template <typename T>
void quicksort_evo(std::vector<T> &vec, int p, int r)  {
	if (p<r) {
		int n = r - p + 1; //dimensione del vettore da ordinare
		if (n <= 56) {
			insertionsort(vec);
		}
		else {
			int q = partition(vec, p, r);
			quicksort(vec, p, q - 1);
			quicksort(vec, q + 1, r);
		}
	}
}