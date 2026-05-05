#pragma once
#include <vector>
template <typename T>
void merge(std::vector<T> &A, int p, int q, int r) {
	int n_1 = q - p + 1;
	int n_2 = r - q;
	std::vector<T> L(n_1+1);
	std::vector<T> R(n_2+1);
	for (int i = 0; i < n_1; i++) {
		L[i] = A[p+i];
	}
	for (int j = 0; j < n_2; j++) {
		R[j] = A[q+j+1];
	}
	int i = 0;
	int j = 0;
	for (int k=p; k<=r; k++) {
		if (i < n_1 && (j == n_2 || L[i] <= R[j])) { //utilizzato questo controllo poiché gli infiniti davano seg fault con le stringhe
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}