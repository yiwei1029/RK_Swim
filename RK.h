#pragma once
double f(double x, double y,double args[]);
double integral_trap(vector<double> x, vector<double> t);
double* rk_step(double x, double y, double* (*f)(double x, double y, double args[], double integral_y),
	double args[], vector<double> y_values, vector<double> t_values);
