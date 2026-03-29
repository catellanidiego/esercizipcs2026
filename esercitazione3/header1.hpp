#pragma once
#include <iostream>
template<typename T> requires std::integral<T>
class rational {
	T numerator;
	T denominator;
	rational () {
		numerator = 0;
		denominator = 0;
	};
	public:
	
		T abs (T n) {
			if (n < 0) {
				n = -n;
			}
		return n;
		};
		
		rational(T num1, T den1) {
			if (den1 < 0) { //pongo il segno meno al numeratore perché altrimenti il segno di x+inf; x-inf e inf-x sarebbe il segno del denominatore di x e del numeratore di inf, l'unico problema di avere il segno meno al numeratore (rispetto al denominatore) si pone nelle divisioni facendo inf/x ma viene gestito dal metodo sgn
				den1 = -den1;
				num1 = -num1;
			};
			T m = mcd(num1, den1);
			if (m != 0) {
				numerator = num1 / abs(m);
				denominator = den1 / abs(m);
			}
			else {
				numerator = num1;
				denominator = den1;
			};
		};
			
		T num() const {
			return numerator;
			};
			
		T den() const {
			return denominator;
			};
			
		T mcd(T c, T b) const{
			while (b != 0) {
				T r = c % b;
				c = b;
				b = r;
			};
			return c;
		};
		
		T sgn (T a, T b, T c, T d) {
			T valori[4] = {a,b,c,d};
			int count = 0;
			for (int i=0; i < 4; i++) {
				if (valori[i] < 0) {
					count ++;
				};
			};
			int res = 1;
			if (count % 2 == 1) {
				res = -1;
			};
			return res;
		};
		
		rational& operator+=(const rational& other) {
			T num3 = other.num();
			T den3 = other.den();
			T num4 = numerator;
			T den4 = denominator;
			//scelti +- 1 su 0 per rappresentare +-inf
			if (den3 == 0 && den4 == 0 && num3*num4 != 0) {
				if (num3*num4<0) {
					numerator = 0;
					denominator = 0;
				};
				if (num3 < 0 && num4 < 0) {
					numerator = -1;
					denominator = 0;					
				};
				if (num3 > 0 && num4 > 0) {
					numerator = 1;
					denominator = 0;
				};
			};

			if (den3 != 0 || den4 != 0) {
				denominator = den4 * den3;
				numerator = num3 * den4 + num4 * den3;
				T m = mcd(denominator, numerator);
				if (m != 0) {
					denominator = denominator / abs(m);
					numerator = numerator / abs(m);
				};
			};
			return *this;
		};
		
		rational operator+(const rational& other) const {
			rational ret = *this;
			ret += other;
			return ret;
		};
		
		rational& operator-=(const rational& other) {
			//s per sottraendo, m per minuendo
			T num_s = other.num();
			T den_s = other.den();
			T num_m = numerator;
			T den_m = denominator;
			denominator = den_m * den_s;
			numerator = num_m * den_s - num_s * den_m;
			T m = mcd(denominator, numerator);
			if (m != 0) {
				denominator = denominator / abs(m);
				numerator = numerator / abs(m);
			};
			return *this;
		};
		
		rational operator-(const rational& other) const {
			rational ret = *this;
			ret -= other;
			return ret;
		};
		
		rational& operator*=(const rational& other) {
			T num3 = other.num();
			T den3 = other.den();
			T num4 = numerator;
			T den4 = denominator;
			denominator = den4 * den3;
			numerator = num4 * num3;
			T segno = sgn(num3, den3, num4, den4);
			T m = mcd(denominator, numerator);
			if (m != 0) {
				denominator = abs(denominator / m);
				numerator = abs(numerator / m);
			};
			numerator = segno * numerator;
			return *this;
		};
		
		rational operator*(const rational& other) const {
			rational ret = *this;
			ret *= other;
			return ret;
		};
		
		rational& operator/=(const rational& other) {
			//do per dividendo, de per divisore
			T num_de = other.num();
			T den_de = other.den();
			T num_do = numerator;
			T den_do = denominator;
			denominator = den_do * num_de;
			numerator = num_do * den_de;
			T m = mcd(denominator, numerator);
			T segno = sgn(num_do, den_de, num_de, den_do);
			if (m != 0) {
				denominator = abs(denominator / m);
				numerator = abs(numerator / m);
			};
			numerator = segno * numerator;
			return *this;
		};
		
		rational operator/(const rational& other) const {
			rational ret = *this;
			ret /= other;
			return ret;
		};
};	