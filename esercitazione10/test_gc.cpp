#include <iostream>
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"
int main() {
	int n = 5; //dimensione matrice A
	Eigen::MatrixXd M = Eigen::MatrixXd::Random(n,n);
	const Eigen::MatrixXd A = M.transpose()*M; //A simmetrica definita positiva per costruzione
	Eigen::VectorXd x_star = Eigen::VectorXd::Ones(n); //vettore di uni 
	const Eigen::VectorXd b = A * x_star; //fatto apposta per avere una soluzione esatta (x_star)
	Eigen::VectorXd x_0 = Eigen::VectorXd::Zero(n);
	const double tol = 1e-9;
	gradiente_coniugato(A, b, x_0, tol);
	double err_ass = (x_0 - x_star).norm();
	int res = EXIT_SUCCESS;
	if (err_ass > tol) {
		std::cout << "Test fallito: errore assoluto " << err_ass << " maggiore della tolleranza" << tol << "\n";
		res = EXIT_FAILURE;
	}
	else {
		std::cout << "Test riuscito: errore assoluto " << err_ass << " minore della tolleranza " << tol << "\n";
	}
	return res;
};