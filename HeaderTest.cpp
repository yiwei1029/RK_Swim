
#include <iostream>
#include"Algo.h"
#include<vector>
int main()

{
    //Sum(1, 2);
    //y_next(2);
    vector<double> t;
    for (int i = 0; i < 1000; ++i) {
        t.push_back(i * 0.1);
    }
    //for (auto i : t) {
    //    cout << i;
    //}
    double y0 = 1;
    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < t.size()-1;++i) {
        double temp = y_next(y.at(i),t.at(1)-t.at(0));
        y.push_back(temp);
        cout << temp << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
