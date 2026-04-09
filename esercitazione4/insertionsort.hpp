#pragma once
#include <vector>
template<typename T>
void insertionsort(std::vector<T>& vec) {
	int n = vec.size();
	for (int i=1; i < n; i++) {
		T key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j+1] = vec[j];
			j = j-1;
		};
		vec[j+1] = key;
	};
};