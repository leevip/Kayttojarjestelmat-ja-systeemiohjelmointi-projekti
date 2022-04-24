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
