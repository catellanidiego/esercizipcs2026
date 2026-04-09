#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //reperita documentazione online per fare le potenze //altrimenti si potrebbe utilizzare un ciclo for per calcolare le potenze come moltiplicazioni ripetute
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
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
	std::vector<double> y_standard(N-n+1);
	for (int i=n; i<=N; i++) {
		std::vector<int> v(pow(2,i));
		rf.fill(v, -100, 100);
		
		std::vector<int> v_bubble = v;
		std::vector<int> v_selection = v;
		std::vector<int> v_insertion = v;
		std::vector<int> v_std = v;
		
		tc.tic();
		bubblesort(v_bubble);
		double secs_b = tc.toc();
		y_bubble[i-n] = secs_b;
		
		tc.tic();
		selectionsort(v_selection);
		double secs_s = tc.toc();
		y_selection[i-n] = secs_s;
		
		tc.tic();
		insertionsort(v_insertion);
		double secs_i = tc.toc();
		y_insertion[i-n] = secs_i;

		tc.tic();
		std::sort(v_std.begin(), v_std.end());
		double secs_std = tc.toc();
		y_standard[i-n] = secs_std;
	};
	
	std::cout << "\nPerformance bubblesort: [";
	for (int j=0;j<N-n;j++) {
		std::cout << y_bubble[j] << ", ";
	};
	std::cout << y_bubble[N-n] <<"]\n";
	
	std::cout << "\nPerformance selectionsort: [";
	for (int j=0;j<N-n;j++) {
		std::cout << y_selection[j] << ", ";
	};
	std::cout << y_selection[N-n] <<"]\n";
	
	std::cout << "\nPerformance insertionsort: [";
	for (int j=0;j<N-n;j++) {
		std::cout << y_insertion[j] << ", ";
	};
	std::cout << y_insertion[N-n] <<"]\n";
	
	std::cout << "\nPerformance standardsort: [";
	for (int j=0;j<N-n;j++) {
		std::cout << y_standard[j] << ", ";
	};
	std::cout << y_standard[N-n] <<"]\n";
	
	return 0;
};