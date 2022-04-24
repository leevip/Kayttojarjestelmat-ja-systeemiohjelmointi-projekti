# Kayttojarjestelmat-ja-systeemiohjelmointi-projekti


Project 1
========

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

Project 2
========
# my-cat

Instructions
-----------
The program can be run with command
./my-cat [file1] [file2] ...

About development
--------
This is a very simple program to write in C. For-loop was used to allow input of multiple files and to avoid errors of not providing a file. The program uses fgetc() to read the files as it is easy and effective in this case.



# my-grep

Instructions
-------
The program can be run with commands
./my-grep searchterm
./my-grep searchterm [file1] [file2] ...

If run without file the program will read standard input and stop reading and print the results after an empty line.

About development
------
The program uses linked list to allow searching from standard input and printing the results after the input has ended. 
getline() was used to read lines to avoid problems with arbitrary length of the lines.
strstr was used to find the searchterm from the input.



# my-zip and my-unzip

Instructions
--------
my-zip can be run with

./my-zip [inputfile1] [inputfile2]

my-unzip can be run with

./my-unzip [file]


Development
---------
my-zip uses for loop to allow input of multiple files. my-zip counts the time a character is read in a while loop and writes the counter and character to output. my-unzip reads the counter and character from the file and uses for loop to write the character to output.

Project 3
=====
This is not complete and does not have all functionalities, but it works and has some simple functionalities. 

# Unix Shell

Instructions
-----------

The program can be run with
./wish
./wish file

Currently the shell can run commands cd and exit as well as basic functionalities with no arguments such as ls, but cannot run commands with arguments other than cd.

Other
-----
Currently this shell does not have many functionalities or error handling.
