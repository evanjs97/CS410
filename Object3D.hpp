#ifndef Object3D_H
#define Object3D_H

#include "Transformation.hpp"

#include<iostream>
#include<string>
#include<fstream>
#include<Eigen/Dense>
#include<vector>

class Transformation;

class Object3D{
	public:
		Object3D(std::vector<std::vector<std::string>> file, std::string filename);
		friend std::ostream& operator<<(std::ostream& os, const Object3D& object);
        static void addObject(Object3D o){ objects.push_back(o); }
        static int getSize(){return objects.size(); }
        static Object3D& getObject(int i){return objects.at(i); }
        void applyTransformation(Transformation t);
        static void objectToFile();
        static void getFilename(std::string& filename);

	private:
		std::vector<Eigen::Matrix<double, 3, 1>> vertices;
        std::vector<Eigen::Matrix<double, 4, 1>> hg_vertices;
		std::vector<std::vector<std::string>> model_file;
        std::string filename;
		void extractVertices();
        static std::vector<Object3D> objects;
        std::vector<Eigen::Matrix<double,4,1>> transformed_vertices;
};

#endif
