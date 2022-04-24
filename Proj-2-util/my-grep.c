#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{		//List for reading standard input
	char* line;
	struct list *next;
} LIST;

void freeList(LIST* pStart){
	LIST* ptr = pStart;
	while (ptr) {
		ptr = ptr->next;
		free(pStart->line);
		free(pStart);
		pStart = ptr;
	}
}

int main(int argc, char* argv[]){
	FILE* file;
	char* newLine;
	size_t len = 0;
	size_t read;
	LIST *pStart = NULL, *pEnd = NULL, *ptr;
	
	if (argc == 1){
		fprintf(stderr, "my-grep: cannot open file\n");
		exit(1);
	}
	/*If a file is not provided the program reads standard input with getline()*/
	if (argc == 2) {
		while((read = getline(&newLine, &len, stdin))!= 1){
			if (strstr(newLine, argv[1])){
				if (!(ptr = (LIST*)malloc(sizeof(LIST)))){
					perror("Error: ");
					freeList(pStart);
					exit(1);
				}
				ptr->line = newLine;
				ptr->next = NULL;
				if(!pStart){
					pStart = ptr;
				} else {
					pEnd->next = ptr;
				}
				pEnd = ptr;
				if(!(newLine = (char*)malloc(len * sizeof(char)))){	//Allocating a new memory area for
					perror("Error");				//a new line to not overwrite previous
					freeList(pStart);
					exit(1);
				}
			}
		}
		ptr = pStart;
		while (ptr) {
			printf("%s", ptr->line);
			ptr = ptr->next;
		}
		freeList(pStart);
	}
	//For loop for more than one input file
	for(int i = 2; i < argc; i++){
		if((file = fopen(argv[i], "r")) == NULL){
			fprintf(stderr, "my-grep: searchterm [file ...]\n");
			exit(1);
		}
		
		while((read = getline(&newLine, &len, file))!= -1){
			if (strstr(newLine, argv[1])){
				printf("%s", newLine);
			}
		}
		
		fclose(file);
	}
	free(newLine);

	return(0);
}
