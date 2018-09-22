#include "FileHandler.hpp"


using namespace std;
using namespace boost;
using namespace Eigen;

std::vector<Transformation> Transformation::transformations;
std::vector<Object3D> Object3D::objects;

void FileHandler::readFile(string& filename) {
	ifstream driver;
	driver.open(filename);
    if(!driver){
        cerr << "ERROR: FILE " + filename + " NOT EXIST" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Reading File: " <<filename << endl;
	string line = "";
	vector<vector<string>> file;
	while (getline(driver, line)) {
		vector<string> split_input;
		split(split_input, line, is_any_of(" "));
		if(split_input.back().find(".obj") != string::npos){
            string modelFile = split_input.back();
            split_input.erase(split_input.begin());
            split_input.pop_back();
            Transformation::addTransformation(Transformation(split_input));
            readFile(modelFile);
        }
		if(filename.find(".obj") != string::npos) file.push_back(split_input);
	}
 	if(filename.find(".obj") != string::npos) Object3D::addObject(Object3D(file, filename));
}


