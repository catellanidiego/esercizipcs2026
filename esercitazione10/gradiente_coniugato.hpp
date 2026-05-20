#pragma once
#include <Eigen/Dense>
void gradiente_coniugato (
	const Eigen::MatrixXd& A,
	const Eigen::MatrixXd& b,
	Eigen::VectorXd& x_0, //considerando che venga fornito in input il vettore iniziale, altrimenti può essere randomizzato o scelto un vettore di uni
	const double& tol) 
{
	Eigen::VectorXd r = b - A * x_0;
	Eigen::VectorXd p = r;
	while (r.norm() > tol) {
		auto alpha = p.dot(r)/(p.dot(A*p)); //reperita documentazione online per fare i prodotti scalari
		x_0 = x_0 + alpha * p;
		r = b - A * x_0;
		auto beta = p.dot(A*r)/(p.dot(A*p));
		p = r - beta*p;
		}
}