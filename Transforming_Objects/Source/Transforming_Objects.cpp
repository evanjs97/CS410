// Transforming_Objects.cpp : Defines the entry point for the application.
//

#include "Transforming_Objects.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 2) {
		string filename = argv[1];
		cout << "Filename: " << filename << endl;
		return 0;
	}
	return 0;
}
