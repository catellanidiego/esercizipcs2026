#pragma once
template<typename T> requires std::integral<T>
class rational {
	T numerator;
	T denominator;
	rational () {
		numerator = 0;
		denominator = 0;
	};
	public:
		rational(T num1, T den1) {
			T m = mcd(num1, den1);
			numerator = num1;
			denominator = den1;
			if (m != 0) {
				numerator = num1 / m;
				denominator = den1 / m;
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
		
		rational& operator+=(const rational& other) {
			T num3 = other.num();
			T den3 = other.den();
			T num4 = numerator;
			T den4 = denominator;
			if (den3 == 0 && den4 == 0 && num3 != 0 && num4 != 0) {
				numerator = 1; //scelto 1 su 0 per rappresentare inf
				denominator = 0;
			}
			else {
				denominator = den4 * den3;
				numerator = num3 * den4 + num4 * den3;
				T m = mcd(denominator, numerator);
				if (m != 0) {
					denominator = denominator / m;
					numerator = numerator / m;
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
				denominator = denominator / m;
				numerator = numerator / m;
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
			T m = mcd(denominator, numerator);
			if (m != 0) {
				denominator = denominator / m;
				numerator = numerator / m;
			};
			return *this;
		};
		
		rational operator*(const rational& other) const {
			rational ret = *this;
			ret *= other;
			return ret;
		};
		
		rational& operator/=(const rational& other) {
			//do per dividendo4, de per divisore
			T num_de = other.num();
			T den_de = other.den();
			T num_do = numerator;
			T den_do = denominator;
			denominator = den_do * num_de;
			numerator = num_do * den_de;
			T m = mcd(denominator, numerator);
			if (m != 0) {
				denominator = denominator / m;
				numerator = numerator / m;
			};
			return *this;
		};
		
		rational operator/(const rational& other) const {
			rational ret = *this;
			ret /= other;
			return ret;
		};
};	
