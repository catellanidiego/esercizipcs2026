#pragma once
#include <Eigen/Dense>
#include <iostream>
template <typename DerivedA, typename Derivedb, typename Derivedx_0> 
void gradiente_coniugato (
	const Eigen::MatrixBase<DerivedA>& A,
	const Eigen::MatrixBase<Derivedb>& b,
	Eigen::MatrixBase<Derivedx_0>& x_0, //considerando che venga fornito in input il vettore iniziale, altrimenti può essere randomizzato o scelto un vettore di uni
	const double& tol) 
{
	using Scalarb = typename Derivedb::Scalar;
	Eigen::Matrix<Scalarb, Eigen::Dynamic, 1> r = b - A * x_0;
	Eigen::Matrix<Scalarb, Eigen::Dynamic, 1> p = r;
	while (r.norm() > tol) {
		auto alpha = p.dot(r)/(p.dot(A*p)); //reperita documentazione online per fare i prodotti scalari
		x_0 = x_0 + alpha * p;
		r = b - A * x_0;
		auto beta = p.dot(A*r)/(p.dot(A*p));
		p = r - beta * p;
	}
}