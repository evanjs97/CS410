#include "FileHandler.hpp"


void FileHandler::readFile(string& filename, TransformingObjects& transformers) {
	ifstream driver;
	driver.open(filename);
	cout << "Reading File: " <<filename << endl;
	string line = "";
	vector<vector<string>> file;
	while (getline(driver, line)) {
		vector<string> split_input;
		split(split_input, line, is_any_of(" "));
		if(split_input.back().find(".obj") != string::npos){
            string modelFile = "Models/" + split_input.back();
            readFile(modelFile, transformers);
            
        }
		if(filename.find(".obj") != string::npos) file.push_back(split_input);
        else{
            split_input.erase(split_input.begin());
            split_input.pop_back();
            
        }
	}
	if(filename.find(".obj") != string::npos) transformers.addModel(Object3D(file, filename));
}
