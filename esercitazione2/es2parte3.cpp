#include <iostream>

int main() {
 static const int N = 10;
 double arr[N] = {57.3, 12.8, 94.0, 3.55, 41.7, 88.2, 25.9, 66.3, 2.4, 12.6};
 bool ancora = 1;
 while (ancora == 1) {
	ancora = 0;
	for (int i=0; i<N-1; i++) {
		if (arr[i]> arr[i+1]) {
		double temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
		ancora = 1;
		}
	}
 }
 for (int j = 0; j < N; j++) {
	std::cout << arr[j] << " ";
 }
 return 0;
}