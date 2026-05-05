#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"
#include "timecounter.h"
int main() {
	int n = 2; //potenza minima di 2
	int N = 13; //potenza massima di 2
	randfiller rf;
	timecounter tc;
	std::vector<double> y_bubble(N-n+1);
	std::vector<double> y_insertion(N-n+1);
	std::vector<double> y_selection(N-n+1);
	std::vector<double> y_merge(N-n+1);
	std::vector<double> y_quick(N-n+1);
	std::vector<double> y_standard(N-n+1);
	
	for (int k=n; k<=N; k++) {
		int dim = pow(2,k);
		std::vector<std::vector<int>> v_ext(100);
		for (int i = 0; i < 100; i++) {
			v_ext[i].resize(dim);
			rf.fill(v_ext[i], -100, 100);
		}
		
		std::vector<std::vector<int>> v_ext_bubble = v_ext;
		std::vector<std::vector<int>> v_ext_selection = v_ext;
		std::vector<std::vector<int>> v_ext_insertion = v_ext;
		std::vector<std::vector<int>> v_ext_merge = v_ext;
		std::vector<std::vector<int>> v_ext_quick = v_ext;
		std::vector<std::vector<int>> v_ext_std = v_ext;	
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			bubblesort(v_ext_bubble[i]);
		}
		double secs_b = tc.toc();
		y_bubble[k-n] = secs_b;
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			selectionsort(v_ext_selection[i]);
		}
		double secs_s = tc.toc();
		y_selection[k-n] = secs_s;
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			insertionsort(v_ext_insertion[i]);
		}
		double secs_i = tc.toc();
		y_insertion[k-n] = secs_i;
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			mergesort(v_ext_merge[i], 0, dim - 1);
		}
		double secs_m = tc.toc();
		y_merge[k-n] = secs_m;
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			quicksort(v_ext_quick[i], 0, dim - 1);
		}
		double secs_q = tc.toc();
		y_quick[k-n] = secs_q;
		
		tc.tic();
		for (int i = 0; i < 100; i++) {
			std::sort(v_ext_std[i].begin(), v_ext_std[i].end());
		}
		double secs_std = tc.toc();
		y_standard[k-n] = secs_std;
	}
	
	std::cout << "\nPerformance bubblesort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_bubble[j] << ", ";
	}
	std::cout << y_bubble[N-n] <<"]\n";
	
	std::cout << "\nPerformance selectionsort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_selection[j] << ", ";
	}
	std::cout << y_selection[N-n] <<"]\n";
	
	std::cout << "\nPerformance insertionsort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_insertion[j] << ", ";
	}
	std::cout << y_insertion[N-n] <<"]\n";
	
	std::cout << "\nPerformance mergesort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_merge[j] << ", ";
	}
	std::cout << y_merge[N-n] <<"]\n";	
	
	std::cout << "\nPerformance quicksort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_quick[j] << ", ";
	}
	std::cout << y_quick[N-n] <<"]\n";
	
	std::cout << "\nPerformance standardsort: [";
	for (int j = 0; j < N-n; j++) {
		std::cout << y_standard[j] << ", ";
	}
	std::cout << y_standard[N-n] <<"]\n";
	
	return 0;
}