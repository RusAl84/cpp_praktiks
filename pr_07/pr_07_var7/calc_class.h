#pragma once
#include <cmath>
#include <iostream>

class calc_class
{
private:
	double x;
	double y;
	double z;
	double beta;
	double gamma;
	double result;
	int variant;
public:
	calc_class(int _var) {
		variant = _var;
	}
	calc_class() {
		variant = 7;
	}
	void set(double _x, double _y) {
		x = _x;
		y = _y;
	}
	void set() {
		switch (variant)
		{
		case 6: {
			x = 16.55*pow(10, -3);
			y = -2.75;
			z = 0.15;
			beta = -40.630;
			break; }
		case 7: {
			x = 0.1722;
			y = 6.33;
			z = 3.25 * pow(10, -4);
			gamma = -205.305;
			break; }
		default:
			break;
		}
	}
	void run() {
		switch (variant)
		{
		case 6: {
			double mnozh1 = sqrt(10*(pow(x,1/3)+pow(x,y+2)));
			double mnozh2 = asin(z)* asin(z) - abs(x - y);
			result = mnozh1* mnozh2;
			break; }
		case 7:{
			double chisl = exp(abs(x - y)) * pow(abs(x - y), (x + y));
			double znam = atan(x) + atan(z);
			double slagaemoe = pow((pow(x,6)+ log(y)* log(y)), 1 / 3);
			result = chisl / znam + slagaemoe;
			break; }
		default:
			break;
		}
	}
	void dislay() {
		std::cout << "Result = " << result << std::endl;
	}


};

