Compiling and Running this Program
Model Transformation
By Evan Steiner
------------------------------------
	* Important: Model files will be read from the from projects home directory
	* Libraries: Eigen library is included in the tar in a folder called "Libraries" and will be included by the makefile as a relative path
	* Compiling: To compile simply type the "make" command in the folder where the tar was unpacked, to clear class and
		executable files call "make clean"
	* Running: To run the program simply run the executable named "modeltoworld" passing a single driver file as an argument
		ie. "./modeltoworld Drivers/driver02.txt"
	* Notes: The program will print out the name of each file it reads and of each file it writes to.
			 The program will choose the next available file name/extension that does not exist yet ie. cube_mw00.obj, cube_mw01.obj...cube_mw20.obj
			 The program wont delete or overwrite older transformed obj files