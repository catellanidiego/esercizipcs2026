#pragma once
#include <vector>
template <typename T>
int partition (std::vector<T> &A, int p, int r) {
	int i = p - 1;
	for (int j = p; j < r ; j++) {
		if (A[j] <= A[r]) {
			i++;
			T temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	if (i != r) {
		T temp = A[i+1];
		A[i+1] = A[r];
		A[r] = temp;
	}
	return (i+1);
}