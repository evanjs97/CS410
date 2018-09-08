CC = g++
DEBUG = -g
CFLAGS = -Wall -O3 -c $(DEBUG) -std=c++14
LFLAGS = -Wall -lpthread $(DEBUG)
OBJS = Object3D.o TransformingObjects.o FileHandler.o Transformation.o
INCLUDE =-I/s/bach/g/under/evanjs/CS410/Libraries/eigen_library -I/s/bach/g/under/evanjs/CS410/Libraries/boost_library

modeltoworld : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o modeltoworld

Object3D.o : Object3D.cpp Object3D.hpp
	$(CC) $(DEBUG) Object3D.cpp $(INCLUDE) $(CFLAGS)


TransformingObjects.o : TransformingObjects.cpp TransformingObjects.hpp FileHandler.hpp Object3D.hpp
	$(CC) $(DEBUG) TransformingObjects.cpp $(INCLUDE) $(CFLAGS)

FileHandler.o : FileHandler.cpp FileHandler.hpp TransformingObjects.hpp Object3D.hpp Transformation.hpp
	$(CC) $(DEBUG) FileHandler.cpp $(INCLUDE) $(CFLAGS)

Transformation.o : Transformation.cpp Transformation.hpp
	$(CC) $(DEBUG) Transformation.cpp $(INCLUDE) $(CFLAGS)

clean:
	-rm *.o modeltoworld
