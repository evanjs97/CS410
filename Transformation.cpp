#include "Transformation.hpp"

using namespace std;
using namespace Eigen;

Transformation::Transformation(vector<string>& values) {
    this->rotate << stod(values.at(0)), stod(values.at(1)), stod(values.at(2));
    this->theta = stod(values.at(3));
    this->scale = stod(values.at(4));
    this->translate << stod(values.at(5)),stod(values.at(6)),stod(values.at(7));
    this->createTransformationMatrix();
}

void Transformation::createTransformationMatrix() {
    Matrix<double,4,4> rotater = setUpRotation();
    Matrix<double,4,4> scaler = Matrix<double,4,4>::Identity();
    Matrix<double,4,4> translater = Matrix<double,4,4>::Identity();
    scaler(0,0) = this->scale;
    scaler(1,1) = this->scale;
    scaler(2,2) = this->scale;
    translater(0,3) = this->translate(0);
    translater(1,3) = this->translate(1);
    translater(2,3) = this->translate(2);
    this->transformation = translater * scaler * rotater;

    cout << "TRANSFORMATION_FINAL: \n" << transformation << endl;
    
}

Matrix<double,4,4> Transformation::setUpRotation() {
    this->rotate = this->rotate.normalized();
    int index = 0;
    double min = this->rotate(0);
    for(int i = 1; i <= 2; i++){
        if(this->rotate(i) < min)index = i;
    }
    Vector3d tempW = this->rotate;
    tempW(index) = 1;
    tempW = tempW.normalized();
    Vector3d tempV = tempW.cross(this->rotate);
    Matrix<double,4,4> tempRw;
    tempRw << this->rotate(0), this->rotate(1), this->rotate(2), 0, tempV(0), tempV(1), tempV(2), 0, tempW(0), tempW(1), tempW(2), 0, 0, 0, 0, 1;
    Matrix<double ,4,4> tempRwt = tempRw.transpose();
    double cosine = cos(this->theta);
    double sine = sin(this->theta);
    Matrix<double,4,4> tempRz;
    tempRz << cosine, -sine, 0, 0, sine, cosine, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
    cout << "TRANSFORMATION AFTER ROTATION: \n" << tempRw << endl;
    cout << "TRANSFORMATION AFTER ROTATION Z: \n" << tempRz << endl;
    return (tempRwt * tempRz * tempRw);
}
