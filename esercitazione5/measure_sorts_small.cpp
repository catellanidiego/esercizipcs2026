#include <iostream>
#include <vector>
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"
#include "timecounter.h"
int main() {
	randfiller rf;
	timecounter tc;
	double min_bsi = 1.0; //bsi sta per bubble, selection, insertion
	double min_mq = 0.0; //mq sta per merge, quick, inizializzato a 0 per poter entrare la prima volta nel ciclo while
	int sum_limits = 0;
	for (int j = 0; j < 100; j++) {
		min_bsi = 1.0;
		min_mq = 0.0;
		int dim = 100;
		while (min_mq < min_bsi && dim >= 2) {
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
			
			tc.tic();
			for (int i = 0; i < 100; i++) {
				bubblesort(v_ext_bubble[i]);
			}
			double secs_b = tc.toc();
			
			tc.tic();
			for (int i = 0; i < 100; i++) {
				selectionsort(v_ext_selection[i]);
			}
			double secs_s = tc.toc();
			
			tc.tic();
			for (int i = 0; i < 100; i++) {
				insertionsort(v_ext_insertion[i]);
			}
			double secs_i = tc.toc();
			
			tc.tic();
			for (int i = 0; i < 100; i++) {
				mergesort(v_ext_merge[i], 0, dim - 1);
			}
			double secs_m = tc.toc();
			
			tc.tic();
			for (int i = 0; i < 100; i++) {
				quicksort(v_ext_quick[i], 0, dim - 1);
			}
			double secs_q = tc.toc();
			
			if (secs_b < secs_s) {
				min_bsi = secs_b;
			}
			else {
				min_bsi = secs_s;
			}
			if (secs_i < min_bsi) {
				min_bsi = secs_i;
			}
			
			if (secs_m < secs_q) {
				min_mq = secs_m;
			}	
			else {
				min_mq = secs_q;
			}
			dim --;
		}
		sum_limits += dim + 1;
	}
	int avg_limits = sum_limits / 100;
	std::cout << avg_limits << "\n";
	return 0;
}