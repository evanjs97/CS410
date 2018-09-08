#ifndef Transformation_H
#define Transformation_H

#include<iostream>
#include<string>
#include<Eigen/Dense>
#include<vector>

class Object3D{
	public:
		Object3D(std::vector<std::vector<std::string>> file, std::string filename);
		friend std::ostream& operator<<(std::ostream& os, const Object3D& object);

	private:
		std::vector<Eigen::Matrix<double, 3, 1>> vertices;
		std::vector<std::vector<std::string>> model_file;
        std::string filename;
		void extractVertices();
};

#endif
