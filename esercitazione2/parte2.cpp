#include <iostream>
#include <cmath>

int main()
{
 static const int N = 10;
 double arr[N] = {57.3, 12.8, 94.0, 3.55, 41.7, 88.2, 25.9, 66.3, 2.4, 12.6};
 double minimo = arr[0];
 double massimo = arr[0];
 double somma = 0;
 for (int i = 0; i < N; i ++){
	if (arr[i]> massimo) {
		massimo = arr[i];
		}
	if (arr[i] < minimo) {
		minimo = arr[i];
		}
	somma += arr[i];
	}
 double media = somma/N;
 double variazione_standard = 0;
 double devianza = 0;
 for (int i = 0; i < N; i ++){
	devianza += (arr[i]-media)*(arr[i]-media);
	}
 double deviazione_standard = std::sqrt (devianza/N);
 std::cout << "Minimo: " << minimo << "\n";
 std::cout << "Massimo: " << massimo << "\n";
 std::cout << "Media: " << media << "\n";
 std::cout << "Deviazione_standard: " << deviazione_standard << "\n";
 return 0;
}