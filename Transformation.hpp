#ifndef Transformation_H
#define Transformation_H

#include<iostream>
#include<string>
#include<vector>
#include<Eigen/Dense>


class Transformation {
    
public:
    Transformation(std::vector<std::string>& values);
private:
    Eigen::Matrix<double,4,4> transformation = Eigen::Matrix<double,4,4>::Zero();
    Eigen::Vector3d translate;
    Eigen::Vector3d rotate;
    double theta = 0;
    double scale = 0;
    void createTransformationMatrix();
    Eigen::Matrix<double,4,4> setUpRotation();
};

#endif
