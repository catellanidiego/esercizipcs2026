#pragma once
#include <vector>
template<typename T>
void selectionsort(std::vector<T>& vec) {
	int n = vec.size();
	for (int i = 0; i < n-1; i++) {
		int minimo = i;
		for (int j=i+1; j <n; j++) {
			if (vec[j] < vec[minimo]) {
				minimo = j;
			};
		};
		T temp = vec[minimo];
		vec[minimo] = vec[i];
		vec[i] = temp;
	};
};