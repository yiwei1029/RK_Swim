#include"RK.h"
#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
double f_float_ratio(double integral_y, double h,double theta) {
	double ratio_under_water = 1 - integral_y / (h * sin(theta));
	return min(max(ratio_under_water, 0.0), 1.0);
}
double* f(double x, double y, double args[],double integral_y) {
	double m, P, k, r, Lymax = 
		args[0], args[1], args[2], args[3], args[4];
	double rho, g, V_0, h, theta =
		args[5], args[6], args[7], args[8], args[9];
	double dxdt = 1 / m * (P / x) - k * x * sqrt(pow(x, 2) + pow(y, 2));
	double dydt = 1 / m * (r * (-integral_y)
		+ rho * g * V_0 * f_float_ratio(integral_y, h, theta)
		- m * g - k * abs(x) * sqrt(pow(x, 2) + pow(y, 2))
		);
	double diff[2] = { dxdt, dydt };
	return diff;
}

double* rk_step(double x, double y, double args[],vector<double> y_values) {

}