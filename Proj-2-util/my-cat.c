#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	FILE* file;
	int character;
	int i;
	for(i = 1; i < argc; i++){
		if((file = fopen(argv[i], "r")) == NULL){
			fprintf(stderr, "my-cat: cannot open file\n");
			exit(1);
		}
		
		while(!feof(file)){
			character = fgetc(file); //fgets() was recommended, but used fgetc() as fgets() requires a length and this is easier
			if(!feof(file)){
				printf("%c", character);
			}
		}
		
		fclose(file);
	}
	return(0);
}
