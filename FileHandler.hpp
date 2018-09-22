#ifndef File_Handler_H
#define File_Handler_H

#include "Transformation.hpp"
#include "Object3D.hpp"
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include "boost/algorithm/string.hpp"

class Transformation;
class Object3D;
class FileHandler {
public:
	static void readFile(std::string& filename);
    //static void writeObjectFiles();
    
private:
    //static std::vector<std::string> object_files;
    //static std::vector<Transformation> transformations;
    //static std::vector<Object3D> objects;
};

#endif
