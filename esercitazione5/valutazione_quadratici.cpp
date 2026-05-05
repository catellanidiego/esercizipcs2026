//L'intento di questo programma è valutare quale tra gli algoritmi quadratici sia il più efficiente per dimensioni < 56
#include <iostream>
#include <vector>
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"
#include "timecounter.h"
int main() {
	randfiller rf;
	timecounter tc;
	int win_b = 0;
	int win_s = 0;
	int win_i = 0;
	for (int dim = 2; dim < 56; dim++) {
		std::vector<std::vector<int>> v_ext(100);
		for (int i = 0; i < 100; i++) {
				v_ext[i].resize(dim);
				rf.fill(v_ext[i], -100, 100);
		}
		
		std::vector<std::vector<int>> v_ext_bubble = v_ext;
		std::vector<std::vector<int>> v_ext_selection = v_ext;
		std::vector<std::vector<int>> v_ext_insertion = v_ext;
		
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
		
		double minimo = secs_b;
		
		if (secs_s <= minimo) {
			minimo = secs_s;
		}
		
		if (secs_i <= minimo) {
			minimo = secs_i;
		}
		
		if (minimo == secs_b) {
			win_b ++;
		}
		
		if (minimo == secs_s) {
			win_s ++;
		}
		
		if (minimo == secs_i) {
			win_i ++;
		}
	}
	std::cout << "WIN BUBBLESORT = " << win_b << "\n";
	std::cout << "WIN SELECTIONSORT = " << win_s << "\n";
	std::cout << "WIN INSERTIONSORT = " << win_i << "\n";
	return 0;
}