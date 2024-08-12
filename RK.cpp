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
double* f(double x, double y, double* args,double integral_y) {
	// Unpack arguments for clarity
	double m = args[0];
	double P = args[1];
	double k = args[2];
	double r = args[3];
	double Lymax = args[4];
	double rho = args[5];
	double g = args[6];
	double V_0 = args[7];
	double height = args[8];
	double theta = args[9];
	double dxdt = 1 / m * (P / x) - k * x * sqrt(pow(x, 2) + pow(y, 2));
	double dydt = 1 / m * (r * (-integral_y)
		+ rho * g * V_0 * f_float_ratio(integral_y, height, theta)
		- m * g - k * abs(x) * sqrt(pow(x, 2) + pow(y, 2))
		);
	double diff[2] = { dxdt, dydt };
	return diff;
}
double integral_trap(vector<double> x_values, vector<double> t_values) {
	double result=0.0;
	// Check if the input vectors have the same size and contain at least two points
	if (x_values.size() != t_values.size() || x_values.size() < 2) {
		std::cerr << "Error: x_values and t_values must be of the same size and contain at least two elements." << std::endl;
		return 0.0; // Return 0 in case of error
	}
	for (size_t i = 0; i < t_values.size()-1; i++) {
		double upper = x_values.at(i);
		double lower = x_values.at(i + 1);
		double height = t_values.at(i + 1) - t_values.at(i);
		result = result + 0.5 * (upper + lower) * height;
	}
	return result;
};
double* rk_step(double x, double y,double h,
	double args[], vector<double> y_values, vector<double> t_values) {
	//double* (*func)(double x, double y, double args[], double integral_y);
	//func = f;
	double integral_y = integral_trap(y_values, t_values);
	auto k1 = f(x, y, args, integral_y);
	auto k2 = f(x+h/2 * k1[0], y+h/2*k1[1], args, integral_y);
	auto k3 = f(x+h/2 * k2[0], y+h/2*k2[1], args, integral_y);
	auto k4 = f(x+h * k3[0], y+h*k3[1], args, integral_y);
	double x_y_next[2] = {x + h / 6 * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]),
	y + h / 6 * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) };
	return x_y_next;
}