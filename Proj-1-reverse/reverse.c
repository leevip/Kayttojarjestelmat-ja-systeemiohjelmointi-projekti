#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct line {
	char* content;
	struct line* pNext;
	struct line* pPrev;
} LINE;

void freeList(LINE* pStart) {
	LINE* ptr;
	do{
		ptr = pStart->pNext;
		free(pStart->content);
		free(pStart);
		pStart = ptr;
	} while (ptr != NULL);
}

void writeLines(char* fileName, LINE* pEnd, LINE* pStart) {
	FILE* file;
	LINE* ptr;
	if((file = fopen(fileName, "w")) == NULL) {
		freeList(pStart);
		fprintf(stderr, "error: cannot open file '%s'\n", fileName);
		exit(1);
	}
	ptr = pEnd;
	while(ptr != NULL){
		fprintf(file,"%s", ptr->content);
		ptr = ptr->pPrev;
	}
	fclose(file);
}

int main(int argc, char *argv[]) {
	LINE *pStart = NULL, *pEnd = NULL;
	LINE *ptr, *pNew;
	char* newLine;
	FILE* file;
	size_t len = 0;
	size_t read;
	
	//See if the program is given too many arguments
	if (argc > 3){
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
	
	if (argc == 1) {	//Deciding input, if no input file is given input will be stdin
		file = stdin;
	} else {					//Error handling if input and output is same file as this was given as a requirement.
		if(argc > 2){
			if (strcmp(argv[1],argv[2]) == 0){	
				fprintf(stderr, "Input and output file must differ\n");
				exit(1);
			}
		}
		if((file = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
			exit(1);
		}
	}	
	while((read = getline(&newLine, &len, file))!= -1) { 
									//Reading the line and appending
		if ((pNew = (LINE*)malloc(sizeof(LINE))) == NULL){	//the linked list is done here
			fprintf(stderr, "error: malloc failed \n");
			exit(1);
		}
		pNew->content = newLine;
		pNew->pNext = NULL;
		if (pStart == NULL) {
			pStart = pNew;
			pEnd = pNew;
			pNew->pPrev = NULL;
		} else {
			pNew->pPrev = pEnd;
			pEnd->pNext = pNew;
			pEnd = pNew;
		}
		
		
		if (argc == 1 && read == 1){
			break;
		}
	
	/*Allocating new memory space for new line first time this was not needed as getline() allocates the memory itself, but is needed here to stop getline from overwriting existing line*/
		newLine = (char*)malloc(len * sizeof(char));	
		if (newLine == NULL) {				
			freeList(pStart);			
			fprintf(stderr, "error: malloc failed\n");
			exit(1);
		}
	}
	fclose(file);
	
	if (argc < 3) {		//If no output file is given print the results
		ptr = pEnd;
		while(ptr != NULL){
			printf("%s",ptr->content);
			ptr = ptr->pPrev;
		}
	}
	
	if (argc > 2) {		//If output file is given write the results to the given file
		writeLines(argv[2], pEnd, pStart);
	}
	
	freeList(pStart);
	free(newLine);
	return(0);
}
