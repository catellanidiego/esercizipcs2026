#pragma once
#include <iostream>
template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& n) {
	I num2 = n.num();
	I den2 = n.den();
	if (den2 == 0 && num2 == 0 ){
		os << "NaN";
	};
	if (den2 == 0 && num2 != 0) {
		os << "inf";
	};
	if (den2 !=0) {
		os << num2 << "/" << den2;
	};
	return os;
};