#include<bits/stdc++.h>
using namespace std;

vector<double> LU(vector<vector<double>> a, vector<double>b, int n){	
    double l[n][n];
	double u[n][n];
	double m[n][n];
	double temp[n];
	vector<double> res;
    
    for(int i=0; i<n; i++){
		res.push_back(0.0);
        for(int j=0; j<n; j++){
            m[i][j]=a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double alpha;
            alpha = a[j][i]/a[i][i];
			for(int k=0; k<n; k++){ 
				a[j][k] = a[j][k] - alpha*a[i][k];
			}
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            u[i][j]=a[i][j];
        }
    }
	//..............LOWER TRIANGULAR MATRIX...........................//
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				l[i][j]=1;
			}
			else
				l[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			l[j][i]=m[j][i];
			for(int k=0; k<i; k++){
				l[j][i] -= l[j][k]*u[k][i];
			}
			l[j][i] = l[j][i]/u[i][i];
		}
	}
	temp[0]= b[0]/l[0][0];
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			b[j] -= l[j][i]*temp[i];
			temp[j]= b[j]/l[j][j];
		}
	}
	res[n-1]=temp[n-1]/u[n-1][n-1];
	for(int i=n-1; i>0; --i){
		for(int j=i-1; j>=0; --j){
			temp[j] -= u[j][i]*res[i];
			res[j]= temp[j]/u[j][j];
		}
	}
	return res;
}
