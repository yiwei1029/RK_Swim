#pragma once
#include<vector>
using namespace std;
double* f(double x, double y,double args[], double integral_y);
double integral_trap(vector<double> x, vector<double> t);
double* rk_step(double x, double y,  double args[],
 vector<double> y_values, vector<double> t_values);
template<typename T>
vector<T> slice(const vector<T>& vec, size_t start, size_t end);
