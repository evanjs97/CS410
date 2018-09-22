#ifndef Transformation_H
#define Transformation_H

#include<iostream>
#include<string>
#include<vector>
#include<Eigen/Dense>


class Transformation {
    
public:
    Transformation(std::vector<std::string>& values);
    friend std::ostream& operator<<(std::ostream& os, const Transformation& object);
    static void addTransformation(Transformation t){ transformations.push_back(t); }
    static int getSize(){return transformations.size(); }
    static Transformation getTransformation(int i){return transformations.at(i); }
    Eigen::Matrix<double,4,4> transformation = Eigen::Matrix<double,4,4>::Zero();
private:
    Eigen::Vector3d translate;
    Eigen::Vector3d rotate;
    double theta = 0;
    double scale = 0;
    void createTransformationMatrix();
    Eigen::Matrix<double,4,4> setUpRotation();
    static std::vector<Transformation> transformations;
};

#endif
