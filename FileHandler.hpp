#ifndef File_Handler_H
#define File_Handler_H

#include "Transformation.hpp"
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include "boost/algorithm/string.hpp"


class FileHandler {
public:
	static void readFile(std::string& filename);
};

#endif
