// Transforming_Objects.cpp : Defines the entry point for the application.
//
#include "TransformingObjects.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 2) {
		string filename = argv[1];
		cout << "Filename: " << filename << endl;
		TransformingObjects transformers;
		FileHandler::readFile(filename, transformers);
        cout << "Models: \n" << transformers << endl;
		return 0;
	}
	return 0;
}

ostream& operator<<(ostream& os, const TransformingObjects& trobj) {
    for(Object3D obj : trobj.models){
        os << obj << endl;
    }
    return os;
}
