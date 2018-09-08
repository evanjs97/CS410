// Transforming_Objects.h : Include file for standard system include files,
// or project specific include files.
#ifndef Transforming_Objects_H
#define Transforming_Objects_H

#include "Object3D.hpp"
#include<iostream>
#include<string>
#include<Eigen/Dense>

class Object3D;
class FileHandler;

class TransformingObjects {
public:
	void addModel(Object3D model);
	friend std::ostream& operator<<(std::ostream& os, const TransformingObjects& trobj);
private:
	std::vector<Object3D> models;
	
};

#endif
