#include<bits/stdc++.h>
#include"4th_Order.cpp"
using namespace std;
#define pi 3.142

int main(){

    int grid_point; cout<<"Enter the number of grid points \n"; cin>> grid_point;
    double left_end, right_end;
    cout<< "The range in which the function is calculated \n";
    cout<<"Minimum: "; cin>> left_end;
    cout<<"Maximum: "; cin>> right_end;
    vector<double> func;
    for(int i=0; i<grid_point; ++i){
        vector<double> temp;
        double cal_func = double(sin(2*(pi)*(i*((right_end-left_end)/grid_point))));
        func.push_back(cal_func);
    }
    compact_4th_order(left_end, right_end, grid_point, func);

    vector<double>numerical_res;
    numerical_res = compact_4th_order(left_end, right_end, grid_point, func);
    for(int i=0; i<grid_point; ++i){
	    cout<< numerical_res[i] << "\n";
	}
    return 0;

}
