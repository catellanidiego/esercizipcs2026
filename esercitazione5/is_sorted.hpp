#pragma once
#include <vector>
#include <cstdlib>
template<typename T>
int is_sorted (const std::vector<T>& vec) {
	int n = vec.size();
	int a = EXIT_SUCCESS;
	if (n != 0) {
		for (int i=0; i<n-1; i++)
			if (vec[i] > vec[i+1]) {
			a = EXIT_FAILURE;
			};
		};
	return a;
};