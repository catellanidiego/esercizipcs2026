#include <iostream>
#include "header1.hpp"
#include "header2.hpp"
int main() {
	rational<int> a(-2,3);
	rational<int> b(3,0);
	rational<int> somma = b + a;
	rational<int> differenza = b - a;
	rational<int> prodotto = b*a;
	rational<int> divisione = b/a;
	std::cout << "operandi: " << a << " e " << b << "\n";
	std::cout << "somma: " << somma << "\n";
	std::cout << "differenza: " << differenza << "\n";
	std::cout << "prodotto: " << prodotto << "\n";
	std::cout << "divisione: " << divisione << "\n";
	return 0;
}