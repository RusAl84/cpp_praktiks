#pragma once
#include <iostream>

using namespace std;

class Maxtrix3Class
{
public:
	double matrix[3][3];
	Maxtrix3Class() {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++)
				matrix[i][j] = 0;

	}

	void Multiply(double in_matrix[3][3]) {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++)
				matrix[i][j] = matrix[i][0] * in_matrix[0][j] + matrix[i][1] * in_matrix[1][j] + matrix[i][2] * in_matrix[2][j];
	}	
	void Print() {
		for (int i = 0; i < 3; i++)
			cout << matrix[i][1] << " " << matrix[i][2] << " " << matrix[i][3] << endl;
	}
};

