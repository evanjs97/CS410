#include "Transformation.hpp"

Transformation::Transformation(vector<string>& values) {
    this.rotate = (stod(values.at(0)), stod(values.at(1), stod(values.at(2),1);
    this.theta = values.at(3);
    this.scale = values.at(4);
    this.tranlate = (stod(values.at(5)), stod(values.at(6), stod(values.at(7),1);
    this.createTransformationMatrix();
}

void Transformation::createTransformationMatrix() {
    this.transformation(0,0) = this.scale;
    this.transformation(1,1) = this.scale;
    this.transformation(2,2) = this.scale;
    this.transformation(3,3) = 1;
    double rotSin = sin(this.theta);
    double rotCos = cos(this.theta);
    this.transformation.col(3) = this.translate;
    
}
