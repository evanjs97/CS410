#ifndef File_Handler_H
#define File_Handler_H
// !File_Handler_H

#include "TransformingObjects.hpp"
#include "Object3D.hpp"
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include "boost/algorithm/string.hpp"

class TransformingObjects;
using namespace boost;
using namespace std;

class FileHandler {
public:
	static void readFile(string& filename, TransformingObjects& transformers);
};

#endif