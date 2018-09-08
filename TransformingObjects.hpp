// Transforming_Objects.h : Include file for standard system include files,
// or project specific include files.
#ifndef Transforming_Objects_H
#define Transforming_Objects_H

#include "FileHandler.hpp"
#include "Object3D.hpp"
#include<iostream>
#include<string>
#include<Eigen/Dense>

using namespace std;

class TransformingObjects {
public:
	void addModel(Object3D model){ this->models.push_back(model); }
	friend ostream& operator<<(ostream& os, const TransformingObjects& trobj);
private:
	vector<Object3D> models;
	
};

#endif
