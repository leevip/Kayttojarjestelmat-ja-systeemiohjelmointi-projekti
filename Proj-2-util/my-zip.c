#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	FILE* file;
	int n, c, prev;
	if (argc == 1){
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	}
	
	/*For loop allows zipping multiple files. "n" is a counter for the letters "a" and "c" are where the characters are saved to allow comparison to find when the character changes.*/
	for (int i = 1; i < argc; i++){
		if(!(file = fopen(argv[i],"r"))){
			perror("Error: ");
			exit(1);
		}
		prev = fgetc(file);
		n = 1; 
		while(!feof(file)){
			c = fgetc(file);
			if (prev != c){
				fwrite(&n, sizeof(int), 1, stdout);
				fwrite(&prev, 1, 1, stdout);
				prev = c;
				n = 1;
			} else {
				n++;
			}
		}
		fclose(file);
	}
	return(0);
}
