#include<bits/stdc++.h>
#include"LU.cpp"
using namespace std;

vector<double> compact_periodic(double left, double right, int n, vector<double> func, int order){
    
    double l_a, l_b;
    double r_a, r_b, r_c;
    double delx = (right - left)/double(n);
    vector<vector<double>>l_arr, r_arr;
    vector<double> mul, res, compact_fds_res;
    if(order == 4){
        l_a = 1.0/4.0; l_b = 0;
        r_a = 3.0/2.0; r_b = 0; r_c = 0;
    }
    else if(order == 6){
        l_a = 1.0/3.0; l_b = 0;
        r_a = 14.0/9.0; r_b = 1.0/9.0; r_c = 0;
    }
    else if(order == 8){
        l_a = 4.0/9.0; l_b = 1.0/36.0;
        r_a = 40.0/27.0; r_b = 25.0/54.0; r_c = 0;
    }
    else if(order == 10){
        l_a = 1.0/2.0; l_b = 1.0/20.0;
        r_a = 17.0/12.0; r_b = 101.0/150.0; r_c = 1.0/100.0;
    }
    else{
        cout<<"Cannot Process \n";
        return compact_fds_res;
    }
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
        if(i-2 >= 0)
            l_arr[i-2][i] = l_b;
            
        if(i+1 <= n-1)
            l_arr[i+1][i] = l_a;
        if(i+2 <= n-1)
            l_arr[i+2][i] = l_b;
    }
    
    for(int i=0; i<n; ++i){
        if(i-1 >= 0)
            r_arr[i-1][i] = (r_a)/(2*delx);
        if(i-2 >= 0)
            r_arr[i-2][i] = (r_b)/(4*delx);
        if(i-3 >= 0)
            r_arr[i-3][i] = (r_c)/(6*delx);
        
        if(i+1 <= n-1)
            r_arr[i+1][i] = (r_a)/(-2*delx);
        if(i+2 <= n-1)
            r_arr[i+2][i] = (r_b)/(-4*delx);
        if(i+3 <= n-1)
            r_arr[i+3][i] = (r_c)/(-6*delx);
    }

    l_arr[0][n-1] = l_a; l_arr[n-1][0] = l_a;
    l_arr[0][n-2] = l_b; l_arr[n-2][0] = l_b;
    l_arr[1][n-1] = l_b; l_arr[n-1][1] = l_b;

    r_arr[0][n-1] = (r_a)/(-2*delx); r_arr[n-1][0] = (r_a)/(2*delx);
    r_arr[0][n-2] = (r_b)/(-4*delx); r_arr[n-1][1] = (r_b)/(4*delx);
    r_arr[0][n-3] = (r_c)/(-6*delx); r_arr[n-1][2] = (r_c)/(6*delx);

    r_arr[1][n-1] = (r_b)/(-4*delx); r_arr[n-2][0] = (r_b)/(4*delx);
    r_arr[1][n-2] = (r_c)/(-6*delx); r_arr[n-2][1] = (r_c)/(6*delx);
    
    r_arr[2][n-1] = (r_c)/(-6*delx); r_arr[n-3][0] = (r_c)/(6*delx);

    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           mul[i] = mul[i] + (func[j]*r_arr[i][j]);
       }
    }
    
    compact_fds_res = LU(l_arr, mul, n);
    return compact_fds_res;
}