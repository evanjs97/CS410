#include<string>
#include<fstream>

using namespace std;

class FileReader.cpp{
	static void readDriverFile(string filename) {
		ifstream driver.open(filename, in);
		while (driver.good()) {
			string line = driver.getline();
			if (line.substr(0, 5) == "model") {

			}
		}
	}

	static void parseModel(string line) {
	}
}