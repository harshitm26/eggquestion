#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fstream>
#include <math.h>
#include <C:\Users\Harshit\SkyDrive\Documents\poly34.h>
#include <C:\Users\Harshit\SkyDrive\Documents\poly34.cpp>

using namespace std;

#define egg 10
#define floor 10000

int max(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

int minimum(int a, int b){
	if(a < b){
		return a;
	}
	return b;
}

int main(){
	ofstream file;
//	file.open("a.csv");
	
	int matrix[floor+1][egg+1];
	memset(matrix, 0, sizeof(matrix));
	for(int i=0; i<=floor; i++){
		matrix[i][0] = INT_MAX;
	}
	for(int i=0; i<=egg; i++){
		matrix[0][i] = 0;
	}
	for(int i=0; i<=floor; i++){
		matrix[i][1] = i; 
	}
	int temp, min;
	for(int j=2; j<=egg; j++){
		for(int i=2; i<=floor; i++){
			min = INT_MAX;
			for(int k=1; k<=i; k++){
				temp = 1 + max(matrix[k-1][j-1], matrix[i-k][j]);
				min = minimum(min, temp);
			}
			matrix[i][j] = min;
		}
	}
	for(int i=1; i<=egg; i++){
//		file<< "egg_count_" << i <<  ",";
	}
	for(int i=1; i<=egg; i++){
//		file << "power(1/" << i << "),";
	}
	file << endl;
	double x[3];
	for(int i=1; i<=floor; i++){
//		for(int j=1; j<=egg; j++){
//			cout << matrix[i][j] << ",";
//			file << matrix[i][j] << ",";
//		}
		for(int j=1; j<=egg; j++){
			if(j == 1 && i % 100 == 0){
				cout << matrix[i][j] << ",";
			}
			if(j == 2 && i%10 == 0){
//				cout << matrix[i][j] << ",";
//				cout << pow(2, 0.5) * pow(i, 1/(double)j) << ",";
//				file << pow(2, 0.5) * pow(i, 1/(double)j) << ",";	
			}
			else if(j == 3 && i%10 == 0){
				int temp = SolveP3(x, 0, 2, -6*i);
//				cout << x[0] << ",";
//				cout << matrix[i][j] << ",";
//				cout << pow(3, 1/(double)3) * pow(i, 1/(double)j) << ",";
//				file << pow(3, 1/(double)3) * pow(i, 1/(double)j) << ",";
			}
			else if(j == 10 && i%100 == 0){
//				cout << matrix[i][j] << ",";
			}
		}
//		cout << endl;
		file << endl;
	}
	
	file.close();
	return 0;
}
