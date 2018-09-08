#ifndef Transformation_H
#define Transformation_H

#include<iostream>
#include<string>
#include<vector>
#include<Eigen/Dense>

using namespace Eigen;
using namespace std;

class Transformation {
    
public:
    Transformation(vector<string> values);
private:
    Matrix<double,4,4> transformation;
    Matrix<double,4,1> translate;
    Matrix<double,4,1,> rotate;
    double theta;
    double scale;
    void createTransformationMatrix();
}

#endif
