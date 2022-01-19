#include<bits/stdc++.h>
#include"Periodic_Func.cpp" // use for periodic functions 
using namespace std;
#define pi 3.142

int main(){

    int grid_point; cout<<"Enter the number of grid points \n"; cin>> grid_point;
    double left_end, right_end;
    int order_accuracy;
    cout<< "The range in which the function is calculated \n";
    cout<< "Minimum: "; cin>> left_end;
    cout<< "Maximum: "; cin>> right_end;
    cout<< "Order of accuracy wanted (available- 4, 6, 8, 10):  \n"; cin>> order_accuracy; 
    double delx = (right_end-left_end)/grid_point;
    vector<double> func;
    for(int i=0; i<grid_point; ++i){
        vector<double> temp;
        double x = left_end + double(delx*(i));
        double cal_func = double(sin(2*(pi)*x));
        double res_func = double(2*pi*cos(2*pi*x));
        cout<< res_func <<"\n";
        //double res_func = double(2*pi*i*delx*cos(2*pi*i*delx)) + double(sin(2*(pi)*(i*delx)));
        //cout<< res_func <<"\n";
        func.push_back(cal_func);
    }
    cout<<"-------------------------------\n";
    compact_periodic(left_end, right_end, grid_point, func, order_accuracy);

    vector<double>numerical_res;
    numerical_res = compact_periodic(left_end, right_end, grid_point, func, order_accuracy);
    for(int i=0; i<grid_point; ++i)
	cout<< numerical_res[i] << "\n";
    return 0;

}
