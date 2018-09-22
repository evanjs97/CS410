#include "Object3D.hpp"

using namespace std;
using namespace Eigen;

Object3D::Object3D(vector<vector<string>> file, string filename) : model_file(file), filename(filename) {
	this->extractVertices();
}

void Object3D::extractVertices() {
	for(vector<string> line : model_file){
		if(line.front() == "v"){
			Matrix<double, 3, 1> vert;
			for(unsigned i = 1; i < line.size(); i++){
				vert(i-1) = stod(line.at(i));
			}
			vertices.push_back(vert);
            hg_vertices.push_back(vert.homogeneous());
		}
	}
}

ostream& operator<<(ostream& os, const Object3D& object) {
    os << "Model File: " << object.filename << "\nOBJECT VERTICES:" << endl;
    for(Matrix<double,4,1> vert : object.transformed_vertices){
        os << vert.transpose() << endl;
    }
    os << "HG VERTICES:" << endl;
    for(Matrix<double,4,1> vert : object.hg_vertices){
        os << vert.transpose() << endl;
    }
    return os;
    
}

void Object3D::applyTransformation(Transformation t) {
	for(Matrix<double,4,1> vertex : hg_vertices) {
		Matrix<double,4,1> v = t.transformation * vertex;
//         cout << fixed;
//         cout.precision(8);
// 		cout << v.transpose() << endl;
		transformed_vertices.push_back(v);
	}
	
	
}

void Object3D::getFilename(string& filename){
    string name = filename.substr(0,filename.length()-4);
    int count = 0;
    ifstream f;
    
    f.open(name+"_mw00.obj");
    while(f) {
        f.close();
        count++;
        if(count < 10) f.open(name + "_mw0" + to_string(count) + ".obj");
        else f.open(name+"_mw" + to_string(count) + ".obj");
    }
    if(count < 10) filename = name + "_mw0" + to_string(count) + ".obj";
    else filename = name + "_mw" + to_string(count) + ".obj";
    cout << "Writing File: " <<  filename << endl;
    
}

void Object3D::objectToFile() {
    ofstream printer;
	printer << fixed;
	printer.precision(7);
    int vert_count = 0;
    for(Object3D object : Object3D::objects){
        Object3D::getFilename(object.filename);
        printer.open(object.filename);
		vert_count = 0;
        for(vector<string> line : object.model_file) {
            if(line.at(0) == "#" || line.at(0) == "f") {
                for(unsigned i = 0; i < line.size()-1; i++) printer << line.at(i) + " ";
                printer << line.at(line.size()-1) << endl;
            }
            else if(line.at(0) == "v"){
                printer << "v " << object.transformed_vertices.at(vert_count)(0) << " " << object.transformed_vertices.at(vert_count)(1) << " " << object.transformed_vertices.at(vert_count)(2) << endl;
                vert_count++;
            }
        }
		printer.close();
    }
}
