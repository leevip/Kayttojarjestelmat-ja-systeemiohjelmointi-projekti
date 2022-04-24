
Instructions
------------

Program can be run from terminal with commands
./reverse
./reverse input.txt
./reverse input.txt output.txt
	
When the program is ran without input file it takes user's input from terminal.
When running the program with terminal input an empty line is used as end of input.

If the program is run without output file output is printed to terminal. 

If the program is run with output file the output is written in output file defined after input file.


Design choices and development notes
------------------------------------

The lines are saved to a linked list with pointers poining to next and previous nodes to provide the possibility to move forwards and backwards on the list.
Due to how getline() works it does not need to have the memory allocated at the start, but needs to have new memory area allocated after adding a line to the linked list in order to stop it from overwriting the previous lines as a pointer to the line is saved in the linked list.

The program was tested for memoryleaks using valgrind. 
