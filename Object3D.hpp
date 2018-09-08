#ifndef Transformation_H
#define Transformation_H

#include<iostream>
#include<string>
#include<Eigen/Dense>
#include<vector>

using namespace Eigen;
using namespace std;

class Object3D{
	public:
		Object3D(vector<vector<string>> file, string filename);
		friend ostream& operator<<(ostream& os, const Object3D& object);

	private:
		vector<Matrix<double, 3, 1>> vertices;
		vector<vector<string>> model_file;
        string filename;
		void extractVertices();
};

#endif
