CC = g++
DEBUG = -g
CFLAGS = -Wall -O3 -c $(DEBUG) -std=c++14
LFLAGS = -Wall -lpthread $(DEBUG)
OBJS = TransformingObjects.o FileHandler.o Object3D.o
INCLUDE =-I/s/bach/g/under/evanjs/CS410/Libraries/eigen_library -I/s/bach/g/under/evanjs/CS410/Libraries/boost_library

modeltoworld : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o modeltoworld

TransformingObjects.o : TransformingObjects.cpp TransformingObjects.hpp FileHandler.hpp Object3D.hpp
	$(CC) $(DEBUG) TransformingObjects.cpp $(INCLUDE) $(CFLAGS)

FileHandler.o : FileHandler.cpp FileHandler.hpp TransformingObjects.hpp Object3D.hpp
	$(CC) $(DEBUG) FileHandler.cpp $(INCLUDE) $(CFLAGS)

Object3D.o : Object3D.cpp Object3D.hpp
	$(CC) $(DEBUG) Object3D.cpp $(INCLUDE) $(CFLAGS)
    
clean:
	-rm *.o modeltoworld
