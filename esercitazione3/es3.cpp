#include <iostream>
#include "header1.hpp"
#include "header2.hpp"
int main() {
	rational<int> a(-2,3);
	int b = 6;
	rational<int> somma_1 = b+a;
	rational<int> differenza_1 = b - a;
	rational<int> prodotto_1 = b*a;
	rational<int> divisione_1 = b/a;
	std::cout << "Primo operando: " << b << " secondo operando: " << a << "\n";
	std::cout << "somma: " << somma_1 << "\n";
	std::cout << "differenza: " << differenza_1 << "\n";
	std::cout << "prodotto: " << prodotto_1 << "\n";
	std::cout << "divisione: " << divisione_1 << "\n";
	
	rational<int> somma_2 = a+b;
	rational<int> differenza_2 = a - b;
	rational<int> prodotto_2 = a*b;
	rational<int> divisione_2 = a/b;
	std::cout << "Primo operando: " << a << " secondo operando: " << b << "\n";
	std::cout << "somma: " << somma_2 << "\n";
	std::cout << "differenza: " << differenza_2 << "\n";
	std::cout << "prodotto: " << prodotto_2 << "\n";
	std::cout << "divisione: " << divisione_2 << "\n";
	return 0;
}