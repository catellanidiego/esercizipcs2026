#pragma once
#include <vector>
template<typename T>
void bubblesort(std::vector<T>& vec) {
	int n = vec.size();
	for (int i=0; i < n-1; i++) {
		for (int j=n-1; j>i; j--) {
			if (vec[j] < vec[j-1]) {
				T temp = vec[j-1];
				vec[j-1] = vec[j];
				vec[j] = temp;
			};
		};
	};
};