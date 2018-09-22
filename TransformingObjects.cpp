// Transforming_Objects.cpp : Defines the entry point for the application.
//
#include "TransformingObjects.hpp"
#include "FileHandler.hpp"
using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 2) {
		string filename = argv[1];
		TransformingObjects transformers;
		FileHandler::readFile(filename);
//         for(int i = 0; i < Object3D::getSize(); i++){
//             cout << "Transformation: \n" << Transformation::getTransformation(i) << endl;
//         }
        TransformingObjects::transformObjects();
        
        Object3D::objectToFile();
		return 0;
	}else{
        cerr << "ERROR: incorrect number of arguments program should be called with './modeltoworld driverfile.txt'" << endl;
    }
	return 0;
}

ostream& operator<<(ostream& os, const TransformingObjects& trobj) {
    for(Object3D obj : trobj.models){
        os << obj << endl;
    }
    return os;
}

void TransformingObjects::transformObjects() {
    for(int i = 0; i < Object3D::getSize(); i++){
         Object3D::getObject(i).applyTransformation(Transformation::getTransformation(i));
    }
}
