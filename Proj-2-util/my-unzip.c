#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n, i;
	char c;
	FILE* file;
	
	if (argc == 1){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
	}
	
	if(!(file = fopen(argv[1], "r"))){
		fprintf(stderr, "error while opening file\n");
		exit(1);
	}
	
	while(!feof(file)){
		fread(&n, sizeof(int), 1, file);
		fread(&c, 1, 1, file);
		if (!feof(file)){
			for(i = 0; i < n; i++){
				fprintf(stdout, "%c", c);
			}
		}
	}
	fclose(file);
	return(0);
}
