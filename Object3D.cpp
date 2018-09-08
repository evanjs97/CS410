#include "Object3D.hpp"

Object3D::Object3D(vector<vector<string>> file, string filename) : model_file(file), filename(filename) {
	this->extractVertices();
}

void Object3D::extractVertices() {
	for(vector<string> line : model_file){
		if(line.front() == "v"){
			Matrix<double, 3, 1> vert;
			for(unsigned i = 1; i < line.size(); i++){
				vert(i-1) = stoi(line.at(i));
			}
			this->vertices.push_back(vert);
		}
	}
}

ostream& operator<<(ostream& os, const Object3D& object) {
    os << "Model File: " << object.filename << "\nOBJECT VERTICES:" << endl;
    for(Matrix<double, 3, 1> vert : object.vertices){
        os << vert(0) << " " << vert(1) << " " << vert(2) << endl;
    }
    return os;
    
}
