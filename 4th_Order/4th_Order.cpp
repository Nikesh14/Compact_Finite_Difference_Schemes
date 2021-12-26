#include<bits/stdc++.h>
#include"LU.cpp"
using namespace std;

vector<double> compact_4th_order(double left, double right, int n, vector<double> func){
    
    double delx = (right - left)/double(n);
    double l_a = 0.25, l_b = 0;
    double r_a = 1.5, r_b = 0, r_c = 0;
    vector<vector<double>>l_arr, r_arr;
    vector<double> mul, res;
    for(int i=0; i<n; ++i){
        vector<double> temp;
        mul.push_back(0);
        for(int j=0; j<n; ++j){
            temp.push_back(0.0);
        }
        l_arr.push_back(temp);
        r_arr.push_back(temp);
    }

    for(int i=0; i<n; ++i){
        l_arr[i][i] = 1;
        if(i-1 >= 0)
            l_arr[i-1][i] = l_a;
        else if(i-2 >= 0)
            l_arr[i-2][i] = l_b;
            
        if(i+1 <= n-1)
            l_arr[i+1][i] = l_a;
        else if(i+2 <= n-1)
            l_arr[i+2][i] = l_b;
    }
    
    for(int i=0; i<n; ++i){
        if(i-1 >= 0)
            r_arr[i-1][i] = (r_a)/(2*delx);
        else if(i-2 >= 0)
            r_arr[i-2][i] = (r_b)/(4*delx);
        else if(i-3 >= 0)
            r_arr[i-3][i] = (r_c)/(6*delx);
        
        if(i+1 <= n-1)
            r_arr[i+1][i] = (r_a)/(-2*delx);
        else if(i+2 <= n-1)
            r_arr[i+2][i] = (r_b)/(-4*delx);
        else if(i+3 <= n-1)
            r_arr[i+3][i] = (r_c)/(-6*delx);
    }

    l_arr[0][1] = 3;
    l_arr[n-1][n-2] = 3;

    r_arr[0][0] = -17.0/(6.0*delx);
    r_arr[0][1] = 3.0/(2.0*delx);
    r_arr[0][2] = r_arr[0][1];
    r_arr[0][3] = -1.0/(6.0*delx);

    r_arr[n-1][n-1] = 17.0/(6.0*delx);
    r_arr[n-1][n-2] = -3.0/(2.0*delx);
    r_arr[n-1][n-3] = r_arr[n-1][n-2];
    r_arr[n-1][n-4] = 1.0/(6.0*delx);


    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           mul[i] = mul[i] + (func[j]*r_arr[i][j]);
       }
    }
    
    vector<double> compact_fds_res;
    compact_fds_res = LU(l_arr, mul, n);
    return compact_fds_res;
}