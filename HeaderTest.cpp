#include <iostream>
#include"Algo.h"
#include<vector>
#include"RK.h"
#include<cmath>
#include"Utils.h"
#define M_PI 3.14159265358979323846
using namespace std;
int main()
{
	vector<double> t;
	for (int i = 0; i < 10000; i++) {
		t.push_back(i * 0.001);
   }
	vector<double> x = { 1 };
	vector<double> y = { 1 };
	cout << x.at(0) << endl;
	double args[10] = { 65,100,0.5,100,1 ,
				1000,10,0.06,1.7,M_PI / 6 };
	for (size_t i = 0; i < t.size()-1; i++) {
		double* xynext = rk_step(x.at(i), y.at(i),t.at(i+1)-t.at(i), args,
			y, slice(t, 0, i + 1));
		x.push_back(xynext[0]);
		y.push_back(xynext[1]);
		//cout << x.at(i) << "  ";

	}
	print_vec2file(y, 
		"C:\\Users\\Administrator\\Documents\\cpp_projects\\HeaderTest\\v_y.txt");

}




