#include "Transformation.hpp"

using namespace std;
using namespace Eigen;

#define PI 3.14159265358979

Transformation::Transformation(vector<string>& values) {
    this->rotate << stod(values.at(0)), stod(values.at(1)), stod(values.at(2));
    this->theta = stod(values.at(3));
    this->scale = stod(values.at(4));
    this->translate << stod(values.at(5)),stod(values.at(6)),stod(values.at(7));
    this->createTransformationMatrix();
}

void Transformation::createTransformationMatrix() {
    Matrix<double,4,4> rotater = setUpRotation();
// 	cout << "ROTATIONMATRIX:\n" << rotater << endl;
    Matrix<double,4,4> scaler = Matrix<double,4,4>::Identity();
    Matrix<double,4,4> translater = Matrix<double,4,4>::Identity();
    scaler(0,0) = this->scale;
    scaler(1,1) = this->scale;
    scaler(2,2) = this->scale;
    translater(0,3) = this->translate(0);
    translater(1,3) = this->translate(1);
    translater(2,3) = this->translate(2);
// 	cout << "SCALER:\n" << scaler << endl;
//     cout << "TRANSLATER:\n" << translater << endl;
    this->transformation = translater * scaler * rotater;

    //cout << "TRANSFORMATION_FINAL: \n" << transformation << endl;
    
}

ostream& operator<<(ostream& os, const Transformation& object) {
    os << object.transformation;
    return os;
}

Matrix<double,4,4> Transformation::setUpRotation() {
    this->rotate = this->rotate.normalized(); //normalize rotation vector
    int index = 0;
    double min = this->rotate(0);
    for(int i = 1; i <= 2; i++){
        if(this->rotate(i) < min)index = i;
    }
    Vector3d tempM = this->rotate;
    tempM(index) = 1;
    tempM = tempM.normalized(); //find vector M where M is not parallel to rotation vector and normalize it
    Vector3d tempU = this->rotate.cross(tempM);  //find vector U where U is vector perpendicular to M and rotation vector
    tempU = tempU.normalized();
	Vector3d tempV = this->rotate.cross(tempU);  //find vector V where V is perpendicular to U and rotation vector
// 	cout << "tempM: \n" << tempM << endl;
// 	cout << "tempW: \n" << this->rotate << endl;
// 	cout << "tempU: \n" << tempU << endl;
// 	cout << "tempV: \n" << tempV << endl;
    Matrix<double,4,4,RowMajor> tempRw;
    tempRw << tempU(0), tempU(1), tempU(2), 0, 
			tempV(0), tempV(1), tempV(2), 0,
			this->rotate(0), this->rotate(1), this->rotate(2), 
			0 , 0, 0, 0, 1;
    Matrix<double ,4,4,RowMajor> tempRwt = tempRw.transpose();
    double cosine = cos(this->theta*(PI/180));
    double sine = sin(this->theta*(PI/180));
    Matrix<double,4,4,RowMajor> tempRz;
    tempRz << cosine, -sine, 0, 0, 
			sine, cosine, 0, 0, 
			0, 0, 1, 0, 
			0, 0, 0, 1;
//     cout << "Rotation RWt: \n" << tempRwt << endl;
// 	cout << "Rotation RW: \n" << tempRw << endl;
//     cout << "Rotation RZ: \n" << tempRz << endl;
    return (tempRwt * tempRz * tempRw);
}
