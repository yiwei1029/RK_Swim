#include"Algo.h"
void Sum(int a,int b) {
	cout << a + b << endl;
}
double f(double y) {
	return 1 / y;
}

double y_next(double y,double h) {
	double (*func)(double);
	func = f; //  dy/dx = f(y) yn+1  = yn+h/2*(f(yn)+f(yn +hf(yn))) 
	double y1 = y + h / 2 * (f(y) + f(y + h * f(y)));
	//cout << func(2);
	return y1;
}