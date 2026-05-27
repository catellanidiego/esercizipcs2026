#include <iostream>
#include <Eigen/Dense>
#include <map>
#include "gradiente_coniugato.hpp"
int main() {
	std::map<int, bool> results;
	const double tol = 1e-9;
	int n = 5; //dimensione matrice A
	for (int exp = 0; exp < 3; exp++) {
		Eigen::MatrixXd M = Eigen::MatrixXd::Random(n,n);
		const Eigen::MatrixXd A = M.transpose()*M; //A simmetrica definita positiva per costruzione
		Eigen::VectorXd x_star = Eigen::VectorXd::Ones(n); //vettore di uni 
		const Eigen::VectorXd b = A * x_star; //fatto apposta per avere una soluzione esatta (x_star)
		Eigen::VectorXd x_0 = Eigen::VectorXd::Zero(n);
		gradiente_coniugato(A, b, x_0, tol);
		Eigen::VectorXd r_final = b - A * x_0;
		results[n] = (r_final.norm() < tol);
		n = n * 10;
	}
int res = EXIT_SUCCESS;
for (auto& pair: results) {
	if (pair.second == false) {
		std::cout << "Test fallito alla matrice di dimensione " << pair.first << "con tolleranza" << tol << "\n";
		res = EXIT_FAILURE;
	}
}

if (res == EXIT_SUCCESS) {
	std::cout << "Tutti i test riusciti" << "\n";	
}

return res;
};